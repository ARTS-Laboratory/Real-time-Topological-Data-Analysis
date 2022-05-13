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

D = np.loadtxt('../data/accel_4.csv',skiprows=2,delimiter=',')
tt = D[:,0]-0.00195
tt = tt*1000 
dd_1 = D[:,1]
dd_2 = D[:,2]
dd_3 = D[:,3]
dd_4 = D[:,4]
dd_5 = D[:,5]

plt.figure(figsize=(6.5,10))


plt.subplot(4,1,1)
plt.plot(tt,dd_1,label='test 1',lw='0.5')
#plt.plot(tt,dd_2,'--',label='test 2',lw='0.5')
plt.plot(tt,dd_3,'-.',label='test 3',lw='0.5')
#plt.plot(tt,dd_4,':',label='test 4',lw='0.5')
plt.plot(tt,dd_5,'-',label='test 5',lw='0.5')
plt.xlim(0,0.6)
plt.ylim(-90,60)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #4')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()

D = np.loadtxt('../data/accel_3.csv',skiprows=2,delimiter=',')
tt = D[:,0]-0.00198
tt = tt*1000 
dd_1 = D[:,1]
dd_2 = D[:,2]
dd_3 = D[:,3]
dd_4 = D[:,4]
dd_5 = D[:,5]

plt.subplot(4,1,2)
plt.plot(tt,dd_1,label='test 1',lw='0.5')
#plt.plot(tt,dd_2,'--',label='test 2',lw='0.5')
plt.plot(tt,dd_3,'-.',label='test 3',lw='0.5')
#plt.plot(tt,dd_4,':',label='test 4',lw='0.5')
plt.plot(tt,dd_5,'-',label='test 5',lw='0.5')
plt.xlim(0,0.6)
plt.ylim(-23,32)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #3')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()

D = np.loadtxt('../data/accel_2.csv',skiprows=2,delimiter=',')
tt = D[:,0]-0.00198
tt = tt*1000 
dd_1 = D[:,1]
dd_2 = D[:,2]
dd_3 = D[:,3]
dd_4 = D[:,4]
dd_5 = D[:,5]

plt.subplot(4,1,3)
plt.plot(tt,dd_1,label='test 1',lw='0.5')
#plt.plot(tt,dd_2,'--',label='test 2',lw='0.5')
plt.plot(tt,dd_3,'-.',label='test 3',lw='0.5')
#plt.plot(tt,dd_4,':',label='test 4',lw='0.5')
plt.plot(tt,dd_5,'-',label='test 5',lw='0.5')
plt.xlim(0,0.6)
plt.ylim(-45,65)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #2')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()



D = np.loadtxt('../data/accel_1.csv',skiprows=2,delimiter=',')
tt = D[:,0]-0.00198
tt = tt*1000 
dd_1 = D[:,1]
dd_2 = D[:,2]
dd_3 = D[:,3]
dd_4 = D[:,4]
dd_5 = D[:,5]

plt.subplot(4,1,4)
plt.plot(tt,dd_1,label='test 1',lw='0.5')
#plt.plot(tt,dd_2,'--',label='test 2',lw='0.5')
plt.plot(tt,dd_3,'-.',label='test 3',lw='0.5')
#plt.plot(tt,dd_4,':',label='test 4',lw='0.5')
plt.plot(tt,dd_5,'-',label='test 5',lw='0.5')
plt.xlim(0,0.6)
plt.ylim(-23,28)
plt.grid('on')
plt.xlabel('time (milliseconds)')
plt.ylabel('deacceleration $(\mathdefault{kg_n})$')
plt.title('accelerometer #1')
plt.legend(framealpha=1,fontsize=8,ncol=2,loc=3)
plt.tight_layout()


plt.savefig('candata_all_accels.png',dpi=500)

























