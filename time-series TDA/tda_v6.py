import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import json as json
import ripser as ripser
import persim as persim
from scipy import signal
from scipy.spatial import KDTree
from matplotlib.gridspec import GridSpec
from numpy.lib.stride_tricks import sliding_window_view as takens # a more fitting name
from tqdm import tqdm
from sklearn.model_selection import train_test_split
import tensorflow.keras as keras
import math
import gtda
from gtda import homology
from gtda import diagrams
"""
Again with DROPBEAR, doing 'optimal' embedding dimension, using giotto 
instead of Ripser, getting features at each timestep
"""
plt.rcParams.update({'image.cmap': 'viridis'})
cc = plt.rcParams['axes.prop_cycle'].by_key()['color']
plt.rcParams.update({'font.serif':['Times New Roman', 'Times', 'DejaVu Serif',
 'Bitstream Vera Serif', 'Computer Modern Roman', 'New Century Schoolbook',
 'Century Schoolbook L',  'Utopia', 'ITC Bookman', 'Bookman',
 'Nimbus Roman No9 L', 'Palatino', 'Charter', 'serif']})
plt.rcParams.update({'font.family':'serif'})
plt.rcParams.update({'font.size': 12})
plt.rcParams.update({'mathtext.fontset': 'custom'})
plt.rcParams.update({'mathtext.rm': 'serif'})
plt.rcParams.update({'mathtext.it': 'serif:italic'})
plt.rcParams.update({'mathtext.bf': 'serif:bold'})
plt.rcParams["animation.html"] = "jshtml" # necessary only for jupyter notebooks
plt.close('all')
#%%
def preprocess():
    f = open('./datasets/DROPBEAR.json')
    data = json.load(f)
    f.close()
    
    acc = np.array(data['acceleration_data'])
    acc_t = np.array(data['time_acceleration_data'])
    pin = np.array(data['measured_pin_location'])
    pin_t = np.array(data['measured_pin_location_tt'])
    
    # pin contains some nan values. replace with nearby non-nan values
    from math import isnan
    for i in range(len(pin)):
        if(isnan(pin[i])):
            pin[i] = pin[i-1]
    
    # remove first 1.5 sec where nothing happens
    pin = pin[pin_t > 1.5]
    pin_t = pin_t[pin_t > 1.5] - 1.5
    acc = acc[acc_t > 1.5]
    acc_t = acc_t[acc_t > 1.5] - 1.5
    
    x = acc
    y = pin
    x_t = acc_t
    y_t = pin_t
    
    return (x, y, x_t, y_t)
#%% system descriptors
sample_rate = 1000 # sampling rate (Hz)
window_size = .05 # in seconds
window_stride = .001 # in seconds
d = 6 # if None found optimally
R_tol = 10 # tolerance for false neighbors
e_tol = .001 # tolerated amount of false neighbors

window_points = int(sample_rate * window_size)
#%% loading DROPBEAR and determining optimal embedding dimension and time delay
(x, y, x_t, y_t) = preprocess()
experiment_length = x.size/25600
# resample to 1 kHz
num = int(experiment_length*1000)
x, x_t = signal.resample(x, num, x_t)
y = np.interp(x_t, y_t, y)
# optimal imbedding dimension
criterion = not d is None # criterion not satisfied
if(not criterion):
    d = 2
X = takens(x, d)
Y = takens(y, d)
X_t = takens(x_t, d)
e_lst = [] # save amount of false neighbors with increasing dimension
while(not criterion):
    X1 = X[:-1]
    X2 = takens(x, d+1)
    X_ = takens(x, d+1)
    
    # k-nearest neighbors
    knn = KDTree(X1)
    
    n_fn = 0 # number of false neighbors
    for i1, q1 in enumerate(X1):
        r = knn.query(q1, k=2)
        d1 = r[0][1]
        i2 = r[1][1]
        
        d2 = np.sqrt(np.sum(np.square((X2[i1] - X2[i2]))))
        if(d2/d1 > R_tol):
            n_fn += 1
    if(n_fn/X1.shape[0] > e_tol):
        d = d+1
        X = takens(x, d)
        Y = takens(y, d)
        X_t = takens(x_t, d)
    else:
        criterion = True
    print(n_fn)
    e_lst.append(n_fn/X1.shape[0])

# we find the best embedding to be d=6
Q = takens(X, window_points, axis=0)
Q_y = takens(Y, window_points, axis=0)
Q_t = takens(X_t, window_points, axis=0)

n_stride = int(window_stride * sample_rate)
n_windows = Q.shape[0]//n_stride
#%% Now do TDA
feature_space = np.zeros((n_windows, 39))
# initialize persistence diagram object
vrdiag = gtda.homology.VietorisRipsPersistence(homology_dimensions=(0,1,2))
# initialize metric objects
metric_names = ['bottleneck',
           'wasserstein',
           'landscape',
           'betti',
           'heat',
           'silhouette'] # persistence_image
metrics = [diagrams.Amplitude(metric=metric_name, order=None) for metric_name in metric_names]
# this for-loop might not be necessary for giotto-tda
for i in tqdm(range(n_windows), ascii=False):
    #%%
    i = i*n_stride
    q = Q[i].T
    qt = vrdiag.fit_transform([q])[0]
    # extract max persistences per each dimension
    h0 = qt[qt[:,-1] == 0][:,:2]
    h1 = qt[qt[:,-1] == 1][:,:2]
    h2 = qt[qt[:,-1] == 2][:,:2]
    
    h0p = h0[:,1] - h0[:,0]
    h1p = h1[:,1] - h1[:,0]
    h2p = h2[:,1] - h2[:,0]
    
    h0i = np.flip(np.argsort(h0p))
    h1i = np.flip(np.argsort(h1p))
    h2i = np.flip(np.argsort(h2p))
    
    for j in range(min(3, h0i.size)):
        feature_space[i, j] = h0[h0i[j+1], 0]
        feature_space[i, j+3] = h0p[h0i[j+1]]
    for j in range(min(3, h1i.size)):
        feature_space[i, j+13] = h1[h1i[j], 0]
        feature_space[i, j+16] = h1p[h1i[j]]
    for j in range(min(3, h2i.size)):
        feature_space[i, j+26] = h2[h2i[j], 0]
        feature_space[i, j+29] = h2p[h2i[j]]
    
    # amplitude metrics
    for j, metric in enumerate(metrics):
        yt = metric.fit_transform([qt]).flatten()
        feature_space[i, j+4] = yt[0]
        feature_space[i, j+17] = yt[1]
        feature_space[i, j+32] = yt[2]
np.save('./processed TDA/dropbear features.npy', feature_space)
#%% make some plots
feature_space = np.load('./processed TDA/dropbear features.npy')
feature_names = ['first birth',
                 'second birth',
                 'third birth',
                 'first persis.',
                 'second persis.',
                 'third persis.',
                 'bottleneck',
                 'wasserstein',
                 'landscape',
                 'betti',
                 'heat',
                 'silhouette',
                 'persis. image']
t = Q_t[:,-1, -1]
for i in range(3):
    for j in range(13):
        print('i: ' + str(i))
        print('j: ' + str(j))
        print('name: ' + 'H%d %s'%(i, feature_names[j]))
        # plt.figure(figsize=(6, 2))
        # plt.plot(t, feature_space[:,13*i+j])
        # plt.xlabel('time (s)')
        # plt.ylabel('H%d %s'%(i, feature_names[j]))
        # plt.tight_layout()
        # plt.savefig('./figs/dropbear features/H%d %s.png'%(i, feature_names[j]), dpi=300)
#%% a persistence diagram
from gtda import plotting
import persim as persim
vrdiag = gtda.homology.VietorisRipsPersistence(homology_dimensions=(0,1,2))

i = 8200 # 8000
i = i*n_stride
q = Q[i].T
qt = vrdiag.fit_transform([q])[0]
h0 = qt[qt[:,-1] == 0][:,:2]
h1 = qt[qt[:,-1] == 1][:,:2]
h2 = qt[qt[:,-1] == 2][:,:2]
fig, ax = plt.subplots(1, 1, figsize=(3, 3))
persim.plot_diagrams([h0, h1, h2], size=30, xy_range=[-.05, 2.05, -.05, 2.05], show=False)
ax.set_xticks([0, 1, 2])
ax.set_yticks([0, 1, 2])
fig.tight_layout()
fig.show()
fig.savefig('./figs/persistence.png', dpi=500)
#%% three features in time 
feat1 = feature_space[:,13*0 + 7] # H0 Wasserstein Amplitude
feat2 = feature_space[:,13*1 + 0] # H1 first birth
feat3 = feature_space[:,13*2 + 9] # H2 Betti number
fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(4, 3), sharex=True)
ax1.set_xlim([t[0], t[-1]])
ax1.plot(t, feat1, linewidth=1)
ax1.set_ylabel('feature 1')
ax1.set_yticks([])
ax2.plot(t, feat2, linewidth=1)
ax2.set_ylabel('feature 2')
ax2.set_yticks([])
ax3.plot(t, feat3, linewidth=1)
ax3.set_yticks([])
ax3.set_ylabel('feature 3')
ax3.set_xlabel('time (s)')
plt.tight_layout()
plt.savefig('./figs/features.png', dpi=1800)