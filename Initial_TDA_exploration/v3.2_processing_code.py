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
tt = D[450:700,0] # time
yy = D[450:700,1] # acceleceration
tau = 10 # set delay
xx = D[400-tau:1000-tau,1]


plt.figure()
plt.plot(tt*1000,yy)
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')



#%% Step through the data for every point

window=20

e_range = np.arange(0,17,4)
num_points = 10
number_time_steps = tt.shape[0]-window# 200
time_steps_offset = 0
e_over_time = np.zeros((e_range.shape[0],number_time_steps))


t_for_step = []

for i_step in range(time_steps_offset,time_steps_offset+number_time_steps):
    print(str(i_step)+ ' of ' + str(number_time_steps))
    y = yy[i_step:window+i_step]
    t = tt[i_step:window+i_step]
    x = xx[i_step:window+i_step]
    t_for_step.append(t[-1])
    
    # plt.figure()
    # plt.subplot(211)
    # plt.plot(t*1000,y,'o-')
    # plt.xlabel('time (ms)')
    # plt.ylabel('acceleratoin (kg$_n$)')
    
    # plt.subplot(212)
    # plt.plot(x,y,'o-')
    # plt.xlabel('acceleratoin - tau=10')
    # plt.ylabel('acceleratoin (kg$_n$)')
    # plt.tight_layout()
    
    
    #% Do a TDA for a a range of e
    
    lines_points = []
    
    for ii in range(e_range.shape[0]):
        
        lines_points.append(TDA(x,y,e_range[ii],num_points))
        
    
    # trim the list of lines for redundent lines
    lines_points_clean = []
    lines_e_clean = []
    
    for ii in range(len(lines_points)):
        for i in range(len(lines_points[ii])):
            a = lines_points[ii][i]
            if not (a in lines_points_clean):
                lines_points_clean.append(a)  # save the line, as a min to max number
                lines_e_clean.append(e_range[ii])
    
    
    lines_points = lines_points_clean
    lines_e = lines_e_clean
    
    
    # plot the bar chart
    
    # plt.figure()
    # for i in range(len(lines_e)):
    #     plt.hlines(len(lines_e)-i,0,lines_e[i],color='k')
    # plt.xlabel('e')
    # plt.ylabel('number')
    
    # create matrix to fill
    
    
    
    for i in range(e_range.shape[0]):
        e_over_time[i,i_step-time_steps_offset] = lines_e.count(e_range[i])
    


t_for_step = np.asarray(t_for_step)
plt.figure()
for i in range(e_range.shape[0]):
    plt.plot(t_for_step*1000,e_over_time[i,:],'*-',label='e ='+str(e_range[i]))


plt.xlabel('time (ms)')
plt.ylabel('number of occurrences')
plt.legend()





plt.figure()
plt.subplot(211)
plt.plot(tt*1000,yy)
plt.xlabel('time (ms)')
plt.ylabel('acceleratoin (kg$_n$)')


plt.subplot(212)
for i in [1,2,3,4]:
    plt.plot(t_for_step*1000,e_over_time[i,:],'*-',label='e ='+str(e_range[i]))
plt.xlabel('time (ms)')
plt.ylabel('number of occurrences')
plt.tight_layout()

plt.legend()







