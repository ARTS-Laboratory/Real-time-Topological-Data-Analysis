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
tau = 5 # set delay
xx = D[400-tau:1000-tau,1]


plt.figure()
plt.plot(tt*1000,yy)
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')

window=400



for i_step in range(0,550,5):
    print(i_step)
    #i_step = 100
    
    
    
    y = yy[i_step:window+i_step]
    t = tt[i_step:window+i_step]
    x = xx[i_step:window+i_step]
    data = np.vstack((x,y)).T
    
    rips = ripser.Rips()
    dgms = rips.fit_transform(data)
    H0_dgm = dgms[0]
    H1_dgm = dgms[1]
    
    # The resolution of the persistence image is adjusted by choosing the pixel size, given in the same units as the diagram
    pimgr = persim.PersistenceImager(pixel_size=1)
    pimgr.fit(H1_dgm)
    
    plt.figure(figsize=(10,6))
    rows = np.linspace(0.6,0.075,2)
    columns =np.linspace(0.06,0.75,3)
    plot_size = [0.28,0.35]
    ax = []
    for ii in range(3):
        for i in range(2):
            ax.append(plt.axes([columns[ii],rows[i],plot_size[0],plot_size[1]]))
            
    a_ix=0
    ax[a_ix].plot(t*1000,y,'o--')
    ax[a_ix].set_ylim([-45,45])
    ax[a_ix].set_xlabel('time (ms)')
    ax[a_ix].set_ylabel('acceleratoin (kg$_n$)')
    ax[a_ix].set_title('Time Series')

    a_ix=2
    ax[a_ix].plot(x,y,'o--')
    ax[a_ix].set_xlabel('acceleratoin($t-$' +str(tau) + ')')
    ax[a_ix].set_ylabel('acceleratoin (kg$_n$)')
    ax[a_ix].set_title('Embedded Space')
    
    a_ix=4
    tda_results = ripser.ripser(data)
    diagrams = tda_results['dgms']
    persim.plot_diagrams(diagrams, show=True, ax=ax[a_ix])
    ax[a_ix].set_title('Persistence Diagram')
    
    a_ix=1
    pimgr.pixel_size = 1
    pimgr.plot_diagram(H1_dgm, skew=True, ax=ax[a_ix])
    ax[a_ix].set_title('Birth - Persistence Coordinates')
    
    a_ix=3
    pimgr.pixel_size = 1
    pimgr.plot_image(pimgr.transform(H1_dgm), ax=ax[a_ix])
    ax[a_ix].set_title('Persistence Image\npixel size: '+str(pimgr.pixel_size))
    
    a_ix=5
    pimgr.pixel_size = 0.1
    pimgr.plot_image(pimgr.transform(H1_dgm), ax=ax[a_ix])
    ax[a_ix].set_title('Persistence Image\npixel size: '+str(pimgr.pixel_size))
    
    plt.savefig('plots/i_step of'+str(i_step))


















