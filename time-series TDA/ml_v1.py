import IPython as IP
IP.get_ipython().magic('reset -sf')
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import json as json
import ripser as ripser
import persim as persim
from scipy import signal
from scipy.spatial import KDTree
from matplotlib.gridspec import GridSpec
from numpy.lib.stride_tricks import sliding_window_view as takens # a more fitting name
from tqdm import tqdm
from sklearn.model_selection import train_test_split
import tensorflow.keras as keras
import math
"""
feature extraction, ML model and analysis of the importance of each feature
using integrated gradients
"""
""" signal to noise ratio """
def snr(sig, noisy_signal, dB=True):
    noise = sig - noisy_signal
    a_sig = math.sqrt(np.mean(np.square(sig)))
    a_noise = math.sqrt(np.mean(np.square(noise)))
    snr = (a_sig/a_noise)**2
    if(not dB):
        return snr
    return 10*math.log(snr, 10)
""" root mean squared error """
def rmse(sig, pred, squared=False):
    error = sig - pred
    num = np.sum(np.square(error))
    denom = np.size(sig)
    e = num/denom
    if(squared):
        return e
    return np.sqrt(e)

def preprocess():
    f = open('./datasets/DROPBEAR.json')
    data = json.load(f)
    f.close()
    
    acc = np.array(data['acceleration_data'])
    acc_t = np.array(data['time_acceleration_data'])
    pin = np.array(data['measured_pin_location'])
    pin_t = np.array(data['measured_pin_location_tt'])
    
    # pin contains some nan values. replace with nearby non-nan values
    from math import isnan
    for i in range(len(pin)):
        if(isnan(pin[i])):
            pin[i] = pin[i-1]
    
    # remove first 1.5 sec where nothing happens
    pin = pin[pin_t > 1.5]
    pin_t = pin_t[pin_t > 1.5] - 1.5
    acc = acc[acc_t > 1.5]
    acc_t = acc_t[acc_t > 1.5] - 1.5
    
    x = acc
    y = pin
    x_t = acc_t
    y_t = pin_t
    
    return (x, y, x_t, y_t)
#%% system description
sample_rate = 1000 # sampling rate (Hz)
window_size = .05 # in seconds
window_stride = .001 # in seconds
d = 6 # if None found optimally
R_tol = 10 # tolerance for false neighbors
e_tol = .001 # tolerated amount of false neighbors

window_points = int(sample_rate * window_size)
#%% loading DROPBEAR
(x, y, x_t, y_t) = preprocess()
experiment_length = x.size/25600
# resample to 1 kHz
num = int(experiment_length*1000)
x, x_t = signal.resample(x, num, x_t)
y = np.interp(x_t, y_t, y)

X = takens(x, d)
Y = takens(y, d)
X_t = takens(x_t, d)

Q = takens(X, window_points, axis=0)
Q_y = takens(Y, window_points, axis=0)
Q_t = takens(X_t, window_points, axis=0)

n_stride = int(window_stride * sample_rate)
n_windows = Q.shape[0]//n_stride
#%% load results
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
#%% feature extraction

#%% feature extraction - take the five
# process at each timestep
h0_max = np.zeros((n_windows, 5, 2))
h1_max = np.zeros((n_windows, 5, 2))
h2_max = np.zeros((n_windows, 5, 2))

for i, results in enumerate(save_results):
    h0 = results[0]
    h1 = results[1]
    h2 = results[2]
    
    h0p = h0[:,1]
    h1p = h1[:,1] - h1[:,0]
    h2p = h2[:,1] - h2[:,0]
    
    h0i = np.flip(np.argsort(h0p))
    h1i = np.flip(np.argsort(h1p))
    h2i = np.flip(np.argsort(h2p))
    
    for j in range(min(5, h0i.size)):
        h0_max[i, j, 0] = h0[h0i[j+1], 0] # birth
        h0_max[i, j, 1] = h0p[h0i[j+1]] # persistence
    for j in range(min(5, h1i.size)):
        h1_max[i, j, 0] = h1[h1i[j], 0] # birth
        h1_max[i, j, 1] = h1p[h1i[j]] # persistence
    for j in range(min(5, h2i.size)):
        h2_max[i, j, 0] = h2[h2i[j], 0] # birth
        h2_max[i, j, 1] = h2p[h2i[j]] # persistence
# scale results and append
h0_birth = h0_max[:,:,0] # full of zeros, disregard
h0_pers = h0_max[:,:,1]
h1_birth = h1_max[:,:,0]
h1_pers = h0_max[:,:,1]
h2_birth = h2_max[:,:,0]
h2_pers = h2_max[:,:,1]

data_arrays = [h0_pers, h1_birth, h1_pers, h2_birth, h2_pers]
data_data = []
data = None
for i, dat_array in enumerate(data_arrays):
    dat_m = np.mean(dat_array)
    dat_s = np.std(dat_array)
    data_data.append((dat_m, dat_s))
    
    data_array = (dat_array - dat_m)/dat_s
    data_arrays[i] = data_array
    if(data is None):
        data = data_array
    else:
        data = np.append(data, data_array, axis=1)
#%% ML
y = Q_y[:,-1,-1]
y_experimental = y[:y.size//n_stride*n_stride].reshape(-1, n_stride)[:,0]
y_s = np.std(y)
y = y_experimental/y_s # normalize for training
(data_train, data_test, y_train, y_test) = train_test_split(data, y, test_size=.2)
# model is a dense NN
model = keras.models.Sequential([
    keras.layers.Dense(200, activation='relu', input_shape=(25,)),
    keras.layers.Dense(200, activation='relu'),
    keras.layers.Dense(200, activation='relu'),
    keras.layers.Dense(1),
])
adam = keras.optimizers.Adam(
    learning_rate = 0.0005
) #clipnorm=1
model.compile(
    loss="mse",
    optimizer=adam,
)
early_stopping = keras.callbacks.EarlyStopping(
    monitor="val_loss",
    min_delta=0,
    patience=15,
    verbose=0,
    mode="auto",
    baseline=None,
    restore_best_weights=True,
)
model.fit(
    data_train, y_train,
    batch_size=64,
    shuffle=True,
    epochs=1000,
    validation_data=[data_train, y_train],
    callbacks=[early_stopping]
)
#%% see model results
y_test *= y_s
y_train *= y_s
y_pred = model.predict(data_test).flatten() * y_s

rmse_error = rmse(y_test, y_pred)
snr_error = snr(y_test, y_pred)

print('rmse: ' + str(rmse_error))
print('snr: ' + str(snr_error))

y_pred_all = model.predict(data) * y_s

plt.figure()
plt.plot(y_experimental, label='experimental values')
plt.plot(y_pred_all, label='model prediction')
plt.legend()
plt.tight_layout()