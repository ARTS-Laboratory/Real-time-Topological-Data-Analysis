# -*- coding: utf-8 -*-
"""
Created on Sat May 14 00:00:01 2022

@author: ADOWNEY2
"""

from memory_profiler import profile
import numpy as np
import ripser as ripser
import time

@profile
def my_func():
    
    D = np.loadtxt('data/AF_data/accel_4.csv',skiprows=2,delimiter=',')
    tt = D[400:1000,0] # time
    yy = D[400:1000,1] # acceleceration
    tau_1 = 1 # set delay
    tau_2 = 5 # set delay
    tau_3 = 10 # set delay
    xx_1 = D[400-tau_1:1000-tau_1,1]
    xx_2 = D[400-tau_2:1000-tau_2,1]
    xx_3 = D[400-tau_3:1000-tau_3,1]

    window=1000
    
    i_step = 100
    y = yy[i_step:window+i_step]
    t = tt[i_step:window+i_step]
    x_1 = xx_1[i_step:window+i_step]
    x_2 = xx_2[i_step:window+i_step]
    x_3 = xx_3[i_step:window+i_step]
    data = np.vstack((x_1,x_2,x_3,y)).T

    t1 = time.time()
    tda_results = ripser.ripser(data,metric='manhattan',maxdim=2)
    print('********************** time '+str(round(time.time()-t1,3))+' s')
    

  
if __name__=='__main__':
  my_func()
  
  
  
  