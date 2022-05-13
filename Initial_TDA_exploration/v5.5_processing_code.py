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


ticks = []
ticks.append(time.time())

D = np.loadtxt('data/AF_data/accel_4.csv',skiprows=2,delimiter=',')
tt = D[400:1000,0] # time
yy = D[400:1000,1] # acceleceration




# plt.figure()
# plt.plot(tt*1000,yy)
# plt.xlabel('time (ms)')
# plt.ylabel('acceleratoin (kg$_n$)')

# Window the data


window=300
i_step = 200
tau = 1 # set delay

xx = D[400-tau:1000-tau,1]
y = yy[i_step:window+i_step]
t = tt[i_step:window+i_step]
x = xx[i_step:window+i_step]

data = np.vstack((x,y)).T

ticks.append(time.time())



#%% Build the Persistence Diagram

tda_results = ripser.ripser(data,metric='manhattan')
diagrams = tda_results['dgms']

ticks.append(time.time())


# Build Birth - Persistence Coordinates

#H0_dgm = diagrams[0]
H1_dgm = diagrams[1]

#ticks.append(time.time())


#%% Generate persistence images from diagrams. 
#The option skew=True specifies that the diagrams are currently in birth-death 
# coordinates and must first be transformed to birth-persistence coordinates:

# The resolution of the persistence image is adjusted by choosing the pixel size, given in the same units as the diagram
pimgr = persim.PersistenceImager(pixel_size=0.1) # build the container
pimgr.fit(diagrams[1]) # fit the data for the h_1 diagrams. I think this just sets the parameters
D_image = pimgr.transform(diagrams[1])


ticks.append(time.time())


#%% Plot the bar plots for the times it takes to do things. 


ticks_difference = []
for i in range(len(ticks)-1):
    ticks_difference.append((ticks[i+1]-ticks[i])*1000)

xbar = np.arange(len(ticks)-1)
plt.figure()
plt.bar(xbar,ticks_difference)
plt.xticks([0,1,2],labels=['load and\nwindow data','TDA','Transform persistence\ndiagram to image\nfor pixel size: '+str(pimgr.pixel_size)],rotation = 30)
plt.ylabel('time (ms)')
plt.tight_layout()


#%% Plot the output just for a reference

plt.figure(figsize=(10,6))

plt.subplot(231)
plt.plot(t*1000,y,'o--')
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')
plt.title('Time Series')

plt.subplot(232)
plt.plot(x,y,'o--')
plt.xlabel('acceleratoin($t-$' +str(tau) + ')')
plt.ylabel('acceleratoin (kg$_n$)')
plt.title('Embedded Space')

plt.subplot(233)
tda_results = ripser.ripser(data)
diagrams = tda_results['dgms']
persim.plot_diagrams(diagrams, show=True)
plt.title('Persistence Diagram')

plt.subplot(234)
pimgr.pixel_size = 1
pimgr.plot_diagram(H1_dgm, skew=True)
plt.title('Birth - Persistence Coordinates')

plt.subplot(235)
pimgr.pixel_size = 1
pimgr.plot_image(pimgr.transform(H1_dgm))
plt.title('Persistence Image\npixel size: '+str(pimgr.pixel_size))

plt.subplot(236)
pimgr.pixel_size = 0.1
pimgr.plot_image(pimgr.transform(H1_dgm))
plt.title('Persistence Image\npixel size: '+str(pimgr.pixel_size))

plt.tight_layout()




















