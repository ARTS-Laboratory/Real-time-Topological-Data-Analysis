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


def cart2pol(x, y):
    rho = np.sqrt(x**2 + y**2)
    phi = np.arctan2(y, x)
    return(rho, phi)

def pol2cart(rho, phi): # input a degree
    phi = math.radians(phi)
    x = rho * np.cos(phi)
    y = rho * np.sin(phi)
    return(x, y)


def circle_plot_data(e,data):
    """
    Build  a cirlce around points in data with radius e

    Parameters
    ----------
    e : TYPE
        DESCRIPTION.
    data : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    x = data[:,0]
    y = data[:,1]

    num_points = 25
    angles = 360/(num_points)
    
    circle_pol = np.ones((num_points,2))
    circle_pol[:,0] = e 
    
    for i in range(num_points):
        circle_pol[i,1] = angles*i 

    point_circle_car = [None] * x.shape[0]
    
    for ii in range(data.shape[0]):
        point_circle_car[ii]=np.ones((num_points,2))
        for i in range(num_points):
            point_circle_car[ii][i,:] = np.array(pol2cart(circle_pol[i,0],circle_pol[i,1])) + data[ii]
    
    # close the cirlce by repeating a point
    for ii in range(data.shape[0]):
        point_circle_car[ii] = np.vstack((point_circle_car[ii],point_circle_car[ii][0,:]))
        
        
    return(point_circle_car)





#%% load the data

np.random.seed(7) # a seed of 7 can get a H_1 with only 5 data points
data=np.random.randn(5,2)

#data = np.array([[0,0,1,1],[0,1,1,0]]).T
x = data[:,0]
y = data[:,1]



plt.figure(figsize=(7,2.5))
plt.subplot(121)
plt.xlim([-1,2])
plt.ylim([-1,2])




    




    
    
plt.scatter(x,y)
# for i in range(x.shape[0]):
#     plt.text(x[i]+0.05,y[i],str(i))
    
# e=1
# cr = circle_plot_data(e,data)
# for ii in range(data.shape[0]):
#     plt.plot(cr[ii][0:,0],cr[ii][0:,1],'k--',lw=0.5)
    
# e=1.414
# cr = circle_plot_data(e,data)
# for ii in range(data.shape[0]):
#     plt.plot(cr[ii][0:,0],cr[ii][0:,1],'r--',lw=0.5)
    
e=2
cr = circle_plot_data(e,data)
for ii in range(data.shape[0]):
    plt.plot(cr[ii][0:,0],cr[ii][0:,1],'g--',lw=0.5)
    
    
    
plt.axis('equal')



plt.subplot(122)
t1 = time.time()
tda_results = ripser.ripser(data,maxdim=2) # ,metric='manhattan'
persim.plot_diagrams(tda_results['dgms'], show=True,lifetime=False)

plt.tight_layout()

















