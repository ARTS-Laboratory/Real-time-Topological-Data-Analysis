import IPython as IP
IP.get_ipython().magic('reset -sf')
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import json as json
import ripser as ripser
import persim as persim
from scipy import signal
from matplotlib.gridspec import GridSpec
"""
Using Dataset 4, Univariate signal with nonstationarity. 
"""
#%%
# set default fonts and plot colors
plt.rcParams.update({'image.cmap': 'viridis'})
cc = plt.rcParams['axes.prop_cycle'].by_key()['color']
plt.rcParams.update({'font.serif':['Times New Roman', 'Times', 'DejaVu Serif',
 'Bitstream Vera Serif', 'Computer Modern Roman', 'New Century Schoolbook',
 'Century Schoolbook L',  'Utopia', 'ITC Bookman', 'Bookman', 
 'Nimbus Roman No9 L', 'Palatino', 'Charter', 'serif']})
plt.rcParams.update({'font.family':'serif'})
plt.rcParams.update({'font.size': 10})
plt.rcParams.update({'mathtext.fontset': 'custom'})
plt.rcParams.update({'mathtext.rm': 'serif'})
plt.rcParams.update({'mathtext.it': 'serif:italic'})
plt.rcParams.update({'mathtext.bf': 'serif:bold'})
plt.close('all')
#%%
def preprocess(resample_period):
    import json
    f = open('data_6_with_FFT.json')
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
    num = int((acc_t[-1] - acc_t[0])/resample_period)
    
    # resample acceleration and pin to desired rate
    acc, resample_t = signal.resample(acc, num, acc_t)
    pin = np.interp(resample_t, pin_t, pin)
    
    X = acc
    y = pin
    
    return (X, y)
#%% tunable numbers
test = 1

data = np.load('./datasets/dataset-4/data_II/npy/test%02d.npy'%test)
X = data[:,-1]

# downsample X and take only second before and after nonstationarity
X = X.reshape(-1, 5)[:,0]
X = X[X.size*4//10:X.size*6//10]

w_t = 0.005 # window size (in seconds)
s_t = 0.0008 # sliding amount
d = 10 # TDA dimensionality (if None, = w_n)
sr = 25000 # sampling rate (from the data)
t = (1/sr)*np.arange(X.size)
#%%
w_n = int(w_t*sr) # samples in window
if(d == None):
    d = w_n
s_n = int(s_t*sr) # sample sliding per window
n_windows = (X.size - 2*w_n)//s_n
n_samples = 2*w_n + n_windows*s_n

X = X[:n_samples]
#%% TDA
save_results = []
for i in range(n_windows):
    #%%
    sig = X[i*s_n:i*s_n+w_n+d-1]
    data = np.lib.stride_tricks.sliding_window_view(sig, (d), writeable=False)
    results = ripser.ripser(data, maxdim=2)['dgms']
    save_results.append(results)
    print(i)
#%% save results
sv = []
for results in save_results:
    h0 = results[0]
    h1 = results[1]
    h2 = results[2]
    
    sv.append([h0.tolist(), h1.tolist(), h2.tolist()])
with open('./processed TDA/test%d.json'%test, 'w') as f:
    json.dump(sv, f)
#%% load results
with open('./processed TDA/test%d.json'%test, 'r') as f:
    results = json.load(f)
save_results = []
for r in results:
    h0 = np.array(r[0])
    h1 = np.array(r[1])
    h2 = np.array(r[2])
    
    if(h0.size == 0):
        h0 = h0.reshape(0, 2)
    if(h1.size == 0):
        h1 = h1.reshape(0, 2)
    if(h2.size == 0):
        h2 = h2.reshape(0, 2)
    
    save_results.append([np.array(h0), np.array(h1), np.array(h2)])
#%% make an animation
fig = plt.figure(figsize=(5, 6), constrained_layout=True)
gs = GridSpec(3, 2, figure=fig)
ax1 = fig.add_subplot(gs[0:2,:])
ax2 = fig.add_subplot(gs[2,:])

ax2.set_xlabel('time (s)')
ax2.set_ylabel('acceleration (m/s^2)')

ax2.set_ylim((np.min(X), np.max(X)))
# ax3.set_ylim((0, np.max(y)))

l2, = ax2.plot([],[], c=cc[0])

def animate(i):
    results = save_results[i]
    sig = X[i*s_n:i*s_n+2*w_n]
    t_sig = t[i*s_n:i*s_n+2*w_n]
    
    persim.plot_diagrams(results,show=False,lifetime=False,ax=ax1)
    l2.set_data(t_sig, sig)
    ax2.set_xlim((t_sig[0], t_sig[-1]))
#%% animation frames 
for i in range(0, len(save_results), 2):
    fig = plt.figure(figsize=(5, 6), constrained_layout=True)
    gs = GridSpec(3, 2, figure=fig)
    ax1 = fig.add_subplot(gs[0:2,:])
    ax2 = fig.add_subplot(gs[2,:])

    ax2.set_xlabel('time (s)')
    ax2.set_ylabel('acceleration (m/s^2)')
    
    ax2.set_ylim((np.min(X), np.max(X)))
    
    ax2.set_xticks([])
    
    l2, = ax2.plot([],[], c=cc[0])
    
    results = save_results[i]
    sig = X[i*s_n:i*s_n+2*w_n]
    t_sig = t[i*s_n:i*s_n+2*w_n]
    
    persim.plot_diagrams(results,show=False, xy_range=[0, .3, 0, .3], lifetime=False,ax=ax1)
    l2.set_data(t_sig, sig)
    ax2.set_xlim((t_sig[0], t_sig[-1]))
    
    fig.savefig('./figs/animation frames/%04d.png'%(i//2), dpi=300)
    plt.close('all')
    
    print(i)
#%% maximum H1 persistence 
h1persistence = np.zeros((len(save_results)))
h1birth = np.zeros((len(save_results)))
h1death = np.zeros((len(save_results)))
h1_t = np.zeros((len(save_results)))
for i, r in enumerate(save_results):
    h1 = r[1]
    h1_persistence = h1[:,1] - h1[:,0]
    h1argmax = np.argmax(h1_persistence)
    h1birth[i] = h1[h1argmax, 0]
    h1death[i] = h1[h1argmax, 1]
    h1persistence[i] = h1_persistence[h1argmax]
    h1_t[i] = t[i*s_n+2*w_n]
#%%
fig, (ax2, ax3, ax4) = plt.subplots(3, 1, figsize=(5, 6), sharex=True)

ax2.set_ylabel('Max. H1 persistence')
ax3.set_ylabel('H1 birth')
ax4.set_ylabel('H1 death')
ax4.set_xlabel('time (s)')
ax4.set_xlim((t[0], t[-1]))

ax2.plot(h1_t, h1persistence)
ax3.plot(h1_t, h1birth)
ax4.plot(h1_t, h1death)

plt.tight_layout()
plt.savefig('./figs/persistence.png', dpi=500)
#%%
# import os
# for file in os.listdir('./figs'):
#     i = int(file[:-4])
#     os.rename('./figs/'+file, './figs/%04d.png'%i)
# m = 0
# for results in save_results:
#     if(results[2].size > 0):
#         m = max(m, np.max(results[2]))
#%% animation is to intensive to run
# ani = mpl.animation.FuncAnimation(fig, animate, interval=s_t, frames=n_windows)
# ani.save('animation.mp4', writer='ffmpeg')