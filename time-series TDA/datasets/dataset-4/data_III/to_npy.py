import numpy as np
"""
Take files from .lvm to .npy, add a time column
"""

for i in range(1,13):
    #%%
    file = "Test" + str(i) + ".lvm"
    
    s = np.genfromtxt(file,
                       missing_values=[''], 
                       filling_values=0,
                       skip_header=23)
    dt = 1/50000
    t = dt*np.arange(s.shape[0])
    t = np.expand_dims(t, 1)
    s = np.append(t, s, axis=1)
    
    np.save('./npy/test%02d.npy'%i, s)