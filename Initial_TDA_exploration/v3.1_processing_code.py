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



#%% Do a TDA for a single e

ii=0
#e_range = np.arange(0,0.05,0.005)
e = 1
num_points = 10
lines_points = TDA(x,y,e,num_points)

plt.figure()
plt.scatter(x,y)

label_created = False
for i in range(len(lines_points)):
    x_temp = [x[lines_points[i][0]],x[lines_points[i][1]]]
    y_temp = [y[lines_points[i][0]],y[lines_points[i][1]]]
    if label_created == False:
        plt.plot(x_temp,y_temp,cc[ii],label='1-simplex of e = '+str(e))
        label_created = True
    else:
        plt.plot(x_temp,y_temp,cc[ii])

plt.xlabel('acceleratoin - tau=10')
plt.ylabel('acceleratoin (kg$_n$)')
plt.legend()



#%% Do a TDA for a a range of e


e_range = np.arange(0,4,0.5)
num_points = 10

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
            print(a)
            lines_points_clean.append(a)  # save the line, as a min to max number
            lines_e_clean.append(e_range[ii])


lines_points = lines_points_clean
lines_e = lines_e_clean



# for ii in range(e_range.shape[0]):
#     label_created = False
#     for i in range(len(lines_points[ii])):
#         x_temp = [x[lines_points[ii][i][0]],x[lines_points[ii][i][1]]]
#         y_temp = [y[lines_points[ii][i][0]],y[lines_points[ii][i][1]]]
#         if label_created == False:
#             plt.plot(x_temp,y_temp,cc[ii],label='1-simplex of e = '+str(e_range[ii]))
#             label_created = True
#         else:
#             plt.plot(x_temp,y_temp,cc[ii])

# plt.xlabel('acceleratoin - tau=10')
# plt.ylabel('acceleratoin (kg$_n$)')
# plt.legend()


# plot the bar chart

plt.figure()
for i in range(len(lines_e)):
    plt.hlines(len(lines_e)-i,0,lines_e[i],color='k')
plt.xlabel('e')
plt.ylabel('number')


# plot the lines on the original data
point_center_car = np.vstack((x,y)).T

# plot the data
plt.figure()
plt.scatter(x,y)
i_color = 0
for ii in range(e_range.shape[0]):
    label_created = False
    for i in range(len(lines_e)):
        
        if lines_e[i] == e_range[ii]:
            x_temp = [point_center_car[lines_points[i][0]][0],point_center_car[lines_points[i][1]][0]]
            y_temp = [point_center_car[lines_points[i][0]][1],point_center_car[lines_points[i][1]][1]]
            if label_created == False:
                plt.plot(x_temp,y_temp,cc[i_color],label='1-simplex of e = '+str(e_range[ii]))
                if i_color == 9:
                    i_color = 0
                else:
                    i_color = i_color +1
                label_created = True
            else:
                plt.plot(x_temp,y_temp,cc[i_color])

plt.legend()




                
# # plot the data
# plt.figure()
# plt.scatter(x,y)
# for ii in range(e_range.shape[0]):
#     label_created = False
#     for i in range(len(lines_e)):
        
#         if lines_e[i] == e_range[ii]:
#             x_temp = [point_center_car[lines_points[i][0]][0],point_center_car[lines_points[i][1]][0]]
#             y_temp = [point_center_car[lines_points[i][0]][1],point_center_car[lines_points[i][1]][1]]
#             if label_created == False:
#                 plt.plot(x_temp,y_temp,cc[ii],label='1-simplex of e = '+str(e_range[ii]))
#                 label_created = True
#             else:
#                 plt.plot(x_temp,y_temp,cc[ii])



#%%




# point_center_car = np.vstack((x,y)).T

# # plot the data
# plt.figure()
# plt.scatter(x,y)


# # plot the data

# #%% loop the data
# lines_points = []
# lines_e = []

# num_points = 10
# angles = 360/(num_points)
# circle_pol = np.ones((num_points,2))
# e_range = np.arange(0,0.05,0.005)

# for e in e_range:
    
    
    
#     circle_pol[:,0] = e 
#     for i in range(num_points):
#         circle_pol[i,1] = angles*i 
    
    
#     point_circle_car = [None] * x.shape[0]
    
#     for ii in range(point_center_car.shape[0]):
#         point_circle_car[ii]=np.ones((num_points,2))
#         for i in range(num_points):
#             point_circle_car[ii][i,:] = np.array(pol2cart(circle_pol[i,0],circle_pol[i,1])) + point_center_car[ii]
    
#     # close the cirlce by repeating a point
#     for ii in range(point_center_car.shape[0]):
#         point_circle_car[ii] = np.vstack((point_circle_car[ii],point_circle_car[ii][0,:]))
    
#     # plot the data points with the circles
#     plt.figure()
#     plt.title('e = ' + str(e))
#     plt.scatter(x,y)
#     for i in range(x.shape[0]):
#         plt.text(x[i]+0.05,y[i],str(i))
#     for ii in range(point_center_car.shape[0]):
#         plt.plot(point_circle_car[ii][0:,0],point_circle_car[ii][0:,1],'k')
#         #plt.plot([point_circle_car[ii][0,0],point_circle_car[ii][-1,0]],[point_circle_car[ii][0,1],point_circle_car[ii][-1,1]],'k')
#     plt.axis('equal')
#     # ii = 0
#     # plt.plot(point_circle_car[ii][:,0],point_circle_car[ii][:,1])
        
    
#     #%% build the H_= birth index
    
#     # for any point on a circle, see if it lies inside any other cirlce
    
#     # ii=0
    
#     # X = bool(is_inside_sm(point_circle_car[ii], [4,0.6]))
#     # print(X)
    
    
    
#     for iii in range(point_center_car.shape[0]): # test for earch circlE
#         for ii in range(point_center_car.shape[0]): # loop through each of the other circles around points, and see if any of the tested poits fall in the new circles
#             if ii != iii:
#                 test = []
#                 for i in range(num_points):
#                     #print(bool(is_inside_sm(point_circle_car[ii], point_circle_car[iii][i])))
#                     test.append(bool(is_inside_sm(point_circle_car[ii], point_circle_car[iii][i])))
#                 #print(any(test))
                
#                 # if there is a true, we have to add a line between iii and ii
#                 if any(test) == True:
#                     a = [np.min([iii,ii]),np.max([iii,ii])]
#                     if not (a in lines_points):
#                         lines_points.append(a)  # save the line, as a min to max number
#                         lines_e.append(e)
                                 
                                 
    

# # plot the bar chart

# plt.figure()
# for i in range(len(lines_e)):
#     plt.hlines(len(lines_e)-i,0,lines_e[i],color='k')
# plt.xlabel('e')
# plt.ylabel('number')


# # plot the lines on the original data

# # plot the data
# plt.figure()
# plt.scatter(x,y)
# for ii in range(e_range.shape[0]):
#     label_created = False
#     for i in range(len(lines_e)):
        
#         if lines_e[i] == e_range[ii]:
#             x_temp = [point_center_car[lines_points[i][0]][0],point_center_car[lines_points[i][1]][0]]
#             y_temp = [point_center_car[lines_points[i][0]][1],point_center_car[lines_points[i][1]][1]]
#             if label_created == False:
#                 plt.plot(x_temp,y_temp,cc[ii],label='1-simplex of e = '+str(e_range[ii]))
#                 label_created = True
#             else:
#                 plt.plot(x_temp,y_temp,cc[ii])

# plt.legend()



