#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 10 09:30:27 2016


Installed Ripser thtrough navigator, using
https://anaconda.org/conda-forge/ripser
https://stackoverflow.com/questions/39299726/cant-find-package-on-anaconda-navigator-what-to-do-next


documentation for Ripser can be found here
https://ripser.scikit-tda.org/en/latest/reference/stubs/ripser.ripser.html#ripser.ripser


@author: downey
"""

#%% import modules and set default fonts and colors

import IPython as IP
IP.get_ipython().magic('reset -sf')
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import pandas as PD
import scipy as sp
from scipy import interpolate
import pickle
import time
import re
import json as json
import pylab
import math as math
from pointInside import *
import itertools as itertools
import ripser as ripser
import persim as persim



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



#%% load the data



D = np.loadtxt('data/AF_data/accel_4.csv',skiprows=2,delimiter=',')
tt = D[400:1000,0] # time
yy = D[400:1000,1] # acceleceration
tau_1 = 5 # set delay
tau_2 = 10 # set delay
xx_1 = D[400-tau_1:1000-tau_1,1]
xx_2 = D[400-tau_2:1000-tau_2,1]

plt.figure()
plt.plot(tt*1000,yy)
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')

window=500

i_step = 100
y = yy[i_step:window+i_step]
t = tt[i_step:window+i_step]
x_1 = xx_1[i_step:window+i_step]
x_2 = xx_2[i_step:window+i_step]
data = np.vstack((x_1,x_2,y)).T

plt.figure(figsize=(7,2.5))
plt.subplot(121)
plt.plot(t*1000,y,'-')
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')

# plt.subplot(223)
# plt.plot(x_1,y,'o--')
# plt.xlabel('acceleratoin($t-$' +str(tau_1) + ')')
# plt.ylabel('acceleratoin (kg$_n$)')
# plt.tight_layout()

plt.subplot(122)
t1 = time.time()
tda_results = ripser.ripser(data,metric='manhattan',maxdim=2)
print('time '+str(round(time.time()-t1,3))+' s')
diagrams = tda_results['dgms']
persim.plot_diagrams(diagrams, show=True)

plt.tight_layout()

plt.savefig('high-rate_TDA',dpi=300)



        # data = datasets.make_circles(n_samples=110)[0]
        # dgms = ripser(data)['dgms']
        # plot_dgms(dgms)



# rips = ripser.Rips()
# dgms = rips.fit_transform(data)
# H0_dgm = dgms[0]
# H1_dgm = dgms[1]

# plt.figure(figsize=(10,5))
# plt.subplot(121)
# plt.scatter(data[:,0], data[:,1], s=4)
# plt.title("Scatter plot of noisy data with some circles")

# plt.subplot(122)
# rips.plot(dgms, legend=False, show=False)
# plt.title("Persistence diagram of $H_0$ and $H_1$")
# plt.show()

# # The resolution of the persistence image is adjusted by choosing the pixel size, given in the same units as the diagram
# pimgr = persim.PersistenceImager(pixel_size=1)
# pimgr.fit(H1_dgm)

# fig, axs = plt.subplots(1, 3, figsize=(10,3))
# pimgr.plot_diagram(H1_dgm, skew=True, ax=axs[0])
# axs[0].set_title('Diagram', fontsize=16)

# pimgr.plot_image(pimgr.transform(H1_dgm), ax=axs[1])
# axs[1].set_title('Pixel Size: 1', fontsize=16)

# pimgr.pixel_size = 0.01
# pimgr.plot_image(pimgr.transform(H1_dgm), ax=axs[2])
# axs[2].set_title('Pixel Size: 0.1', fontsize=16)

# plt.tight_layout()











# plt.figure(figsize=(10,6))


# plt.subplot(231)
# plt.plot(t*1000,y,'o--')
# plt.xlabel('time (ms)')
# plt.ylabel('acceleratoin (kg$_n$)')
# plt.title('Time Series')


# plt.subplot(232)
# plt.plot(x_1,y,'o--')
# plt.xlabel('acceleratoin($t-$' +str(tau_1) + ')')
# plt.ylabel('acceleratoin (kg$_n$)')
# plt.title('Embedded Space')


# plt.subplot(233)
# tda_results = ripser.ripser(data)
# diagrams = tda_results['dgms']
# persim.plot_diagrams(diagrams, show=True)
# plt.title('Persistence Diagram')



# plt.subplot(234)
# pimgr.pixel_size = 1
# pimgr.plot_diagram(H1_dgm, skew=True)
# plt.title('Birth - Persistence Coordinates')


# plt.subplot(235)
# pimgr.pixel_size = 1
# pimgr.plot_image(pimgr.transform(H1_dgm))
# plt.title('Persistence Image\npixel size: '+str(pimgr.pixel_size))


# plt.subplot(236)
# pimgr.pixel_size = 0.01
# pimgr.plot_image(pimgr.transform(H1_dgm))
# plt.title('Persistence Image\npixel size: '+str(pimgr.pixel_size))



# plt.tight_layout()




















