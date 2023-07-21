import IPython as IP
IP.get_ipython().magic('reset -sf')
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
"""
Again with DROPBEAR, doing 'optimal' embedding dimension
"""
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
window_size = .25 # in seconds
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
save_results = []
for i in tqdm(range(n_windows)):
    i = i*n_stride
    q = Q[i].T
    results = ripser.ripser(q, maxdim=2)['dgms']
    save_results.append(results)
# save results
sv = []
for results in save_results:
    h0 = results[0]
    h1 = results[1]
    h2 = results[2]
    
    sv.append([h0.tolist(), h1.tolist(), h2.tolist()])
with open('./processed TDA/dropbear.json', 'w') as f:
    json.dump(sv, f)