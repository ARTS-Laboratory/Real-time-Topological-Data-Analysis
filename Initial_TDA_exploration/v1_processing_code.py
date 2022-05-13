#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 10 09:30:27 2016

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

xx = np.loadtxt('data/MG_tau_20.csv')
xx = xx[144:224]

plt.figure()
plt.plot(xx)


d = 10 #12 is a good number

yy= xx[0:xx.shape[0]-d]
yy_delay = xx[d::]

plt.figure()
plt.title(d)
plt.plot(yy_delay,yy,'*')

#%% draw one line

ii = 1
dist = []
for i in range(68):
    x1 = yy_delay[ii]
    x2 = yy_delay[i]
    y1 = yy[ii]
    y2 = yy[i]

    dist.append(math.hypot(x2-x1, y2-y1))

dist = np.asarray(dist)
dist[dist==0]='nan'

dist_min = np.nanargmin(dist)

plt.figure()
plt.title('Distance')
plt.plot(dist)

plt.figure()
plt.title(d)
plt.plot(yy_delay,yy,'*')

X = [yy_delay[ii],yy_delay[dist_min]]
Y = [yy[ii],yy[dist_min]]


plt.plot(X,Y,'r')



#%% draw a bunch of lines


plt.figure()
plt.title(d)
plt.plot(yy_delay,yy,'*')
    
for ii in range(67):
    dist = []
    for i in range(68):
        x1 = yy_delay[ii]
        x2 = yy_delay[i]
        y1 = yy[ii]
        y2 = yy[i]
    
        dist.append(math.hypot(x2-x1, y2-y1))
    
    dist = np.asarray(dist)
    dist[dist==0]='nan'
    
    dist_min = np.nanargmin(dist)
    
    # plt.figure()
    # plt.title('Distance')
    # plt.plot(dist)
    
    X = [yy_delay[ii],yy_delay[dist_min]]
    Y = [yy[ii],yy[dist_min]]

    
    plt.plot(X,Y,'r')












































