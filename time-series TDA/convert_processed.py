import numpy as np
import json
"""
The processed dropbear.json file is too large to push to github, so I'm splitting
up the files and saving as .npy
"""
with open('./processed TDA/dropbear.json', 'r') as f:
    results = json.load(f)
save_results = []
for r in results:
    h0 = np.array(r[0])
    h1 = np.array(r[1])
    h2 = np.array(r[2])
    
    if(h0.size == 0):
        h0 = h0.reshape(0, 2)
    if(h1.size == 0):
        h1 = h1.reshape(0, 2)
    if(h2.size == 0):
        h2 = h2.reshape(0, 2)

    save_results.append([np.array(h0), np.array(h1), np.array(h2)])
for i, r in enumerate(save_results):
    h0 = r[0]
    h1 = r[1]
    h2 = r[2]
    
    np.save('./processed TDA/dropbear/h0/%05d.npy'%i, h0)
    np.save('./processed TDA/dropbear/h1/%05d.npy'%i, h1)
    np.save('./processed TDA/dropbear/h2/%05d.npy'%i, h2)