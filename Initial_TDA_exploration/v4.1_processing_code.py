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
from pointInside import *
import itertools as itertools

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


def TDA(x,y,e,num_points):
    """
    TDA code copied into function. Not cleaned up at all.
    
    @author: downey
    """
    
    point_center_car = np.vstack((x,y)).T
    
    # loop the data
    lines_points = []
    lines_e = []
    
    #num_points = 10
    angles = 360/(num_points)
    circle_pol = np.ones((num_points,2))
    

    circle_pol[:,0] = e 
    for i in range(num_points):
        circle_pol[i,1] = angles*i 
    
    
    point_circle_car = [None] * x.shape[0]
    
    for ii in range(point_center_car.shape[0]):
        point_circle_car[ii]=np.ones((num_points,2))
        for i in range(num_points):
            point_circle_car[ii][i,:] = np.array(pol2cart(circle_pol[i,0],circle_pol[i,1])) + point_center_car[ii]
    
    # close the cirlce by repeating a point
    for ii in range(point_center_car.shape[0]):
        point_circle_car[ii] = np.vstack((point_circle_car[ii],point_circle_car[ii][0,:]))
    
    for iii in range(point_center_car.shape[0]): # test for earch circle
        for ii in range(point_center_car.shape[0]): # loop through each of the other circles around points, and see if any of the tested poits fall in the new circles
            if ii != iii:
                test = []
                for i in range(num_points):
                    #print(bool(is_inside_sm(point_circle_car[ii], point_circle_car[iii][i])))
                    test.append(bool(is_inside_sm(point_circle_car[ii], point_circle_car[iii][i])))
                #print(any(test))
                
                # if there is a true, we have to add a line between iii and ii
                if any(test) == True:
                    a = [np.min([iii,ii]),np.max([iii,ii])]
                    if not (a in lines_points):
                        lines_points.append(a)  # save the line, as a min to max number
                        lines_e.append(e)

    #return(lines_points,lines_e)
    return(lines_points)




#%% load the data



D = np.loadtxt('data/AF_data/accel_4.csv',skiprows=2,delimiter=',')
tt = D[400:1000,0] # time
yy = D[400:1000,1] # acceleceration
tau = 10 # set delay
xx = D[400-tau:1000-tau,1]


plt.figure()
plt.plot(tt*1000,yy)
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')

window=20

i_step = 150
y = yy[i_step:window+i_step]
t = tt[i_step:window+i_step]
x = xx[i_step:window+i_step]

plt.figure()
plt.subplot(211)
plt.plot(t*1000,y,'o-')
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')

plt.subplot(212)
plt.plot(x,y,'o-')
plt.xlabel('acceleratoin - tau=10')
plt.ylabel('acceleratoin (kg$_n$)')
plt.tight_layout()





#%% Do a TDA for a a range of e


e_range = np.arange(0,4,0.5)
#num_points = 10




iterable = list(range(x.shape[0]))
line_ends = list(map(list,itertools.combinations(iterable,2)))
lines_e = []
for i in range(len(line_ends)):
    lines_e.append(np.sqrt( (x[line_ends[i][1]] - x[line_ends[i][0]])**2 + (y[line_ends[i][1]] - y[line_ends[i][0]])**2 ))



# sort the list 
#lines_e_sort = lines_e.sort()

#lines_e = [2, 3, 1, 4, 5]
list_index=[]
  
for i in range(len(lines_e)):
      list_index.append([lines_e[i],i])
list_index.sort()
sort_index = []
for i in list_index:
      sort_index.append(i[1])
lines_e_sort = []
for i in range(len(lines_e)):
      lines_e_sort.append(lines_e[sort_index[i]])




# plot the bar chart
plt.figure()
for i in range(len(lines_e_sort)):
    plt.hlines(len(lines_e_sort)-i,0,lines_e_sort[i],color='k')
plt.xlabel('$\epsilon$')
plt.ylabel('number')


# plot the lines on the original data
point_center_car = np.vstack((x,y)).T

# plot the data
plt.figure()
plt.scatter(x,y)
for i in range(len(lines_e)):
    x_temp = [x[line_ends[i][1]],x[line_ends[i][0]]]
    y_temp = [y[line_ends[i][1]],y[line_ends[i][0]]]
    plt.plot(x_temp,y_temp,color=cc[1],lw=0.5,zorder=0)






