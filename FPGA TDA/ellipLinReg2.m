data = readmatrix('ellipse_points.csv');

x = data(:,1);
y = data(:,2);

x_center = mean(x);
y_center = mean(y);

x_ = x - x_center;
y_ = y - y_center;

t = atan2(y_, x_);

x = 5 + 4*cos(t) + rand(size(t));
y = 8 + 2*sin(t) + rand(size(t));

i = size(t); %where t is a column vector

W=[ones(i) cos(t) zeros(i) zeros(i) ;
   zeros(i) zeros(i) ones(i) sin(t)];

af = W \ [x;y];

residual = W*af - [x;y];
residual_global = norm(W*af - [x;y]);

disp(residual);
disp(residual_global);

plot(x,y,'*'); hold on
xnew = af(1) + af(2)*cos(t);
ynew = af(3) + af(4)*sin(t);
plot(xnew, ynew, 'r')
hold off