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




accel_1 = np.loadtxt('accel1.txt',delimiter=',')
accel_2 = np.loadtxt('accel2.txt',delimiter=',')
accel_3 = np.loadtxt('accel3.txt',delimiter=',')
accel_4 = np.loadtxt('accel4.txt',delimiter=',')
fs = 1/1000000
N = accel_1.shape[0]
tt = np.linspace(0,N*fs,num=N)





plt.figure(figsize=(6.5,5))
plt.plot(tt,accel_1,label='accel 1',lw='0.5')
plt.plot(tt,accel_2,label='accel 2',lw='0.5')
plt.plot(tt,accel_3,label='accel 3',lw='0.5')
plt.plot(tt,accel_4,label='accel 4',lw='0.5')
plt.ylim(-90,60)
plt.grid('on')
plt.xlabel('time (s)')
plt.ylabel('deacceleration (g)')
plt.title('accelerometer #4')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()



#%% Compare the data sets



D = np.loadtxt('../../accel_1.csv',skiprows=2,delimiter=',')

ref = D[:,3]

plt.figure(figsize=(6.5,5))
plt.plot(accel_1,label='accel 1',lw='0.5')
plt.plot(ref,label='ref',lw='0.5')
plt.ylim(-90,60)
plt.grid('on')
plt.xlabel('time (s)')
plt.ylabel('deacceleration (g)')
plt.title('accelerometer #4')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()











































