import numpy as np
import matplotlib.pyplot as plt
"""
a simple plot of a sine wave embedded into two dimensions
"""
plt.rcParams.update({'image.cmap': 'viridis'})
cc = plt.rcParams['axes.prop_cycle'].by_key()['color']
plt.rcParams.update({'font.serif':['Times New Roman', 'Times', 'DejaVu Serif',
 'Bitstream Vera Serif', 'Computer Modern Roman', 'New Century Schoolbook',
 'Century Schoolbook L',  'Utopia', 'ITC Bookman', 'Bookman',
 'Nimbus Roman No9 L', 'Palatino', 'Charter', 'serif']})
plt.rcParams.update({'font.family':'serif'})
plt.rcParams.update({'font.size': 17})
plt.rcParams.update({'mathtext.fontset': 'custom'})
plt.rcParams.update({'mathtext.rm': 'serif'})
plt.rcParams.update({'mathtext.it': 'serif:italic'})
plt.rcParams.update({'mathtext.bf': 'serif:bold'})
plt.rcParams["animation.html"] = "jshtml" # necessary only for jupyter notebooks
plt.close('all')

x = np.linspace(0, 2*np.pi, num=400, endpoint=True)
y = np.sin(x)
y_ = np.append(y[100:], y[:100])

yds = y.reshape(-1, 20)[:,0]
y_ds = y_.reshape(-1, 20)[:,0]

plt.figure(figsize=(4,4))
plt.xlim([-1.1, 1.1])
plt.ylim([-1.1, 1.1])
plt.xticks([])
plt.yticks([])
plt.plot(y, y_)
plt.plot(yds, y_ds, marker='o', linewidth=0, c=cc[0])
plt.xlabel(r'$x(t)$')
plt.ylabel(r'$x(t-\pi/2)$')
plt.tight_layout()
plt.savefig('./figs/circle.png', dpi=1800)