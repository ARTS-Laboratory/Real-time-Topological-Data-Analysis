import IPython as IP
IP.get_ipython().magic('reset -sf')
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import pandas as PD
import scipy as sp
# from scipy import interpolate
import pickle
import time
import re
import json as json
import pylab
import math as math
import itertools as itertools
import ripser as ripser
import persim as persim
"""
Make a persistence diagram of a sine wave.
"""
#%% set default fonts and plot colors
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
#%% function definitions
def cart2pol(x, y):
    rho = np.sqrt(x**2 + y**2)
    phi = np.arctan2(y, x)
    return(rho, phi)

def pol2cart(rho, phi): # input a degree
    phi = math.radians(phi)
    x = rho * np.cos(phi)
    y = rho * np.sin(phi)
    return(x, y)

class TimeDelayArray:
    
    def __init__(self, signal):
        self.signal = signal
        self.len = len(signal)
    
    def __getitem__(self, indices):
        n, t = indices
        return self.signal[(n + t)%self.len]
    
    def __len__(self):
        return self.len
#%% load the data
N = 15 # number of samples across the sine wave
k = 1 # step size
n = 15 # number of timesteps
sig = np.sin(np.linspace(0, 2*np.pi, num=N, endpoint=False))

# time-delay embedding
d = TimeDelayArray(sig)

data = np.zeros((N, n))
for i in range(N):
    for j in range(n):
        data[i, j] = d[i, j]
# ripser algorithm
tda_results = ripser.ripser(data)
persim.plot_diagrams(tda_results['dgms'], show=True,lifetime=False)
plt.tight_layout()
# barcode
results = tda_results['dgms']
fig, axes = plt.subplots(nrows=len(results), ncols=1, figsize=(4,4), sharex=True)
fig.subplots_adjust(hspace=0)
plt.xlabel(r'$\varepsilon$')
for i, ax in enumerate(axes):
    bars = results[i]
    ax.set_yticks([])
    ax.set_ylabel(r'H$_%d$'%i)
    for j, bar in enumerate(bars):
        ax.plot(bar, [-j, -j], c='k')
        print(bar)
axes[0].set_xlim(left=0)