#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 10 09:30:27 2016

@author: downey
"""

# %% import modules

import IPython as IP
IP.get_ipython().magic('reset -sf')
import matplotlib.pyplot as plt
import matplotlib as mpl
import os as os
import numpy as np
import pandas as PD
import scipy as sp
from scipy import interpolate
import pickle
import time
import re
import json as json
import csv

import pylab
plt.rcParams.update({'font.size': 9,'font.weight':100})

#del mpl.font_manager.weight_dict['roman']
#mpl.font_manager._rebuild()

cc = plt.rcParams['axes.prop_cycle'].by_key()['color']
plt.close('all')

#%% Load the expermintal data
# tt = np.loadtxt('data/time_fig2.csv',delimiter=',')
# dd_1 = np.loadtxt('data/test1_fig2.csv',delimiter=',')
# dd_2 = np.loadtxt('data/test2_fig2.csv',delimiter=',')
# dd_3 = np.loadtxt('data/test3_fig2.csv',delimiter=',')
# dd_4 = np.loadtxt('data/test4_fig2.csv',delimiter=',')
# dd_5 = np.loadtxt('data/test5_fig2.csv',delimiter=',')


accel_1 = []
accel_2 = []
accel_3 = []
accel_4 = []
accel_5 = []
accel_6 = []
accel_7 = []

start = 9500
stop = 14500
D = np.loadtxt('series_1_matlab.csv',skiprows=2,delimiter=',')
tt = (D[start:stop,0]-D[start,0])/1000
accel_1.append(tt)
accel_2.append(tt)
accel_3.append(tt)
accel_4.append(tt)
accel_5.append(tt)
accel_6.append(tt)

accel_1.append(D[start:stop,3])
accel_2.append(D[start:stop,4])
accel_3.append(D[start:stop,5])
accel_4.append(D[start:stop,6])
accel_5.append(D[start:stop,1])
accel_6.append(D[start:stop,2])


D = np.loadtxt('series_2_matlab.csv',skiprows=2,delimiter=',')
accel_1.append(D[start:stop,3])
accel_2.append(D[start:stop,4])
accel_3.append(D[start:stop,5])
accel_4.append(D[start:stop,6])
accel_5.append(D[start:stop,1])
accel_6.append(D[start:stop,2])




D = np.loadtxt('series_3_matlab.csv',skiprows=2,delimiter=',')
accel_1.append(D[start:stop,3])
accel_2.append(D[start:stop,4])
accel_3.append(D[start:stop,5])
accel_4.append(D[start:stop,6])
accel_5.append(D[start:stop,1])
accel_6.append(D[start:stop,2])



D = np.loadtxt('series_4_matlab.csv',skiprows=2,delimiter=',')
accel_1.append(D[start:stop,3])
accel_2.append(D[start:stop,4])
accel_3.append(D[start:stop,5])
accel_4.append(D[start:stop,6])
accel_5.append(D[start:stop,1])
accel_6.append(D[start:stop,2])



D = np.loadtxt('series_5_matlab.csv',skiprows=2,delimiter=',')
accel_1.append(D[start:stop,3])
accel_2.append(D[start:stop,4])
accel_3.append(D[start:stop,5])
accel_4.append(D[start:stop,6])
accel_5.append(D[start:stop,1])
accel_6.append(D[start:stop,2])


fields = 'time, accel 1, accel 2, accel 3, accel 4, accel top, accel bottom'
fields_2 = ['time - seconds (computed after test)', 'deacceleration - kg', 'deacceleration - kg', 'deacceleration - kg', 'deacceleration - kg', 'deacceleration - kg', 'deacceleration - kg']

tt = np.asarray(tt).T
accel_1 = np.asarray(accel_1).T
accel_2 = np.asarray(accel_2).T
accel_3 = np.asarray(accel_3).T
accel_4 = np.asarray(accel_4).T
accel_5 = np.asarray(accel_5).T
accel_6 = np.asarray(accel_6).T

np.savetxt('accel_1.csv', accel_1, delimiter=',') 
np.savetxt('accel_2.csv', accel_2, delimiter=',') 
np.savetxt('accel_3.csv', accel_3, delimiter=',') 
np.savetxt('accel_4.csv', accel_4, delimiter=',') 
np.savetxt('accel_5.csv', accel_5, delimiter=',') 
np.savetxt('accel_6.csv', accel_6, delimiter=',')     

offset = 0
plt.figure(figsize=(6.5,10))


plt.subplot(4,1,1)
plt.plot(accel_4[:,0]*1000000-offset,accel_4[:,1],label='test 1',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_4[:,2],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_4[:,3],label='test 3',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_4[:,4],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_4[:,5],label='test 5',lw='0.5')
plt.xlim(0,2)
plt.ylim(-90,60)
plt.grid('on')
plt.xlabel('time (microseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #4')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()


plt.subplot(4,1,2)
plt.plot(accel_4[:,0]*1000000-offset,accel_3[:,1],label='test 1',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_3[:,2],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_3[:,3],label='test 3',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_3[:,4],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_3[:,5],label='test 5',lw='0.5')
plt.xlim(0,2)
plt.ylim(-23,32)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #3')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()


plt.subplot(4,1,3)
plt.plot(accel_4[:,0]*1000000-offset,accel_2[:,1],label='test 1',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_2[:,2],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_2[:,3],label='test 3',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_2[:,4],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_2[:,5],label='test 5',lw='0.5')
plt.xlim(0,2)
plt.ylim(-45,65)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #2')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()


plt.subplot(4,1,4)
plt.plot(accel_4[:,0]*1000000-offset,accel_1[:,1],label='test 1',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_1[:,2],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_1[:,3],label='test 3',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_1[:,4],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000-offset,accel_1[:,5],label='test 5',lw='0.5')
plt.xlim(0,2)
plt.ylim(-23,28)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #1')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()


# plt.savefig('candata_all_accels.png',dpi=500)






offset = 9.92
plt.figure(figsize=(6.5,5))


plt.subplot(2,1,1)
plt.plot(accel_4[:,0]*1000000,accel_5[:,1],label='test 1',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_5[:,2],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_5[:,3],label='test 3',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_5[:,4],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_5[:,5],label='test 5',lw='0.5')
plt.xlim(0,2)
plt.ylim(-10,20)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #5')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()


plt.subplot(2,1,2)
plt.plot(accel_4[:,0]*1000000,accel_6[:,1],label='test 1',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_6[:,2],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_6[:,3],label='test 3',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_6[:,4],label='test 2',lw='0.5')
plt.plot(accel_4[:,0]*1000000,accel_6[:,5],label='test 5',lw='0.5')
plt.xlim(0,2)
plt.ylim(-10,20)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #6')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()



















