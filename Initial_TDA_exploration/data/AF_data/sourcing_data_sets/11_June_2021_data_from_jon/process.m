clear
close all
clc

load('Unit105_Series1_3.mat')
load('Unit105_Series1_4.mat')
load('Unit105_Series1_5.mat')
load('Unit105_Series1_1.mat')
load('Unit105_Series1_2.mat')


series_1 = [Unit105_Series1_1(:,7),Unit105_Series1_1(:,1:6)];
writematrix(series_1,'series_1.csv')

series_2 = [Unit105_Series1_2(:,7),Unit105_Series1_2(:,1:6)];
writematrix(series_2,'series_2.csv')

series_3 = [Unit105_Series1_3(:,7),Unit105_Series1_3(:,1:6)];
writematrix(series_3,'series_3.csv')

series_4 = [Unit105_Series1_4(:,7),Unit105_Series1_4(:,1:6)];
writematrix(series_4,'series_4.csv')

series_5 = [Unit105_Series1_5(:,7),Unit105_Series1_5(:,1:6)];
writematrix(series_5,'series_5.csv')



