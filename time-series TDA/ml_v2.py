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
import tensorflow as tf

import math
"""
feature extraction, ML model and analysis of the importance of each feature
using integrated gradients, using giotto-tda to calculate metrics
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
#%% ML
X = np.load('./processed TDA/dropbear features.npy')

# remove certain features
remove_features = np.flip([0, 1, 2, 10, 11, 12, 23, 24, 25, 38])
keep_features = [i for i in range(39)]
for feature in remove_features:
    keep_features.pop(keep_features[feature])
X_ = None
for feature in keep_features:
    x = X[:,feature].reshape(-1, 1)
    x = (x - np.mean(x))/np.std(x) # normalize
    if(X_ is None):
        X_ = x
    else:
        X_ = np.append(X_, x, axis=1)
X = X_

y_experimental = Q_y[:,-1,-1]
t = Q_t[:,-1, -1]
y_s = np.std(y)
y = y_experimental/y_s # normalize for training
(X_train, X_test, y_train, y_test) = train_test_split(X, y, test_size=.2)
# model is a dense NN
model = keras.models.Sequential([
    keras.layers.Dense(150, activation='relu', input_shape=(29,)),
    keras.layers.Dense(150, activation='relu'),
    keras.layers.Dense(150, activation='relu'),
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
    X_train, y_train,
    batch_size=64,
    shuffle=True,
    epochs=1000,
    validation_data=[X_test, y_test],
    callbacks=[early_stopping]
)

keras.models.save_model(model, './model saves/dropbear')

#%% see model results
plt.rcParams.update({'image.cmap': 'viridis'})
cc = plt.rcParams['axes.prop_cycle'].by_key()['color']
plt.rcParams.update({'font.serif':['Times New Roman', 'Times', 'DejaVu Serif',
 'Bitstream Vera Serif', 'Computer Modern Roman', 'New Century Schoolbook',
 'Century Schoolbook L',  'Utopia', 'ITC Bookman', 'Bookman',
 'Nimbus Roman No9 L', 'Palatino', 'Charter', 'serif']})
plt.rcParams.update({'font.family':'serif'})
plt.rcParams.update({'font.size': 12})
plt.rcParams.update({'mathtext.fontset': 'custom'})
plt.rcParams.update({'mathtext.rm': 'serif'})
plt.rcParams.update({'mathtext.it': 'serif:italic'})
plt.rcParams.update({'mathtext.bf': 'serif:bold'})
plt.rcParams["animation.html"] = "jshtml" # necessary only for jupyter notebooks
plt.close('all')


y_test_rescaled = y_test * y_s
y_train_rescaled = y_train * y_s
y_pred = model.predict(X_test).flatten() * y_s

rmse_error = rmse(y_test_rescaled, y_pred)
snr_error = snr(y_test_rescaled, y_pred)

print('rmse: ' + str(rmse_error))
print('snr: ' + str(snr_error))

y_pred_all = model.predict(X) * y_s

plt.figure(figsize=(5, 2.6))
plt.plot(t, y_pred_all, '--', linewidth=.5, c=cc[1], label='model prediction')
plt.plot(t, y_experimental, linewidth=1, c=cc[2], label='roller location')
plt.xlabel("time (s)")
plt.ylabel("displacement (m)")
plt.ylim([.04, .2])
plt.xlim([t[0], t[-1]])
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("./figs/model prediction.png", dpi=500)
plt.savefig("./figs/model prediction.svg")
#%% feature importance with gradients
def compute_gradients(X, y_true):
    y_true = tf.constant(y_true)
    X = tf.constant(X)
    with tf.GradientTape() as tape:
        tape.watch(X)
        y_pred = model(X)
        error = keras.losses.MeanSquaredError()(y_true, y_pred)
    return tape.gradient(error, X)

grads = compute_gradients(X, y)
grads = grads.numpy()

# RMS of grads along feature dimension
tot_grads = np.sqrt(np.sum(np.square(grads), axis=0))
tot_grads = tot_grads / np.sum(tot_grads) # sum to 1
#%% plot of gradient importance
pers_names = ['first birth',
                 'second birth',
                 'third birth',
                 'first persis.',
                 'second persis.',
                 'third persis.',
                 'bottleneck',
                 'Wasserstein',
                 'landscape',
                 'Betti',
                 'heat',
                 'silhouette',
                 'persis. image']
feature_names = []
for i in range(3):
    for p in pers_names:
        feature_names.append(r'$H_' + str(i) + '$ ' + p)
for f in remove_features:
    feature_names.pop(f)

grad_order = np.flip(np.argsort(tot_grads))
tot_grads_ordered = np.flip(np.sort(tot_grads))
feature_names_ordered = ['']*len(feature_names)
for i in range(len(feature_names)):
    feature_names_ordered[i] = feature_names[grad_order[i]]

fig, ax = plt.subplots(1, 1, figsize=(4.2, 2.5))
ax.bar(np.linspace(0, 1, 29), tot_grads_ordered, width=.02, align='center')
ax.set_xticks([])
ax.set_xlabel('feature')
ax.set_ylabel('feature importance')
plt.tight_layout()
plt.savefig('./figs/feature bar.png', dpi=1600)