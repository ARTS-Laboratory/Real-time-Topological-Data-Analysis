x_points = x;
y_points = y;

[a, M, M_rearranged] = fitzgibbon(x_points, y_points);

%y is not a function of x, so the conic is rearranged to solve for y in
%terms of x. quadratic equation is used to solve for both solutions of y,
%yeilding the top and bottom half of the fit. I'll find a more elegant way
%to solve for the fit, but this will make HDL coding simpler for now. 

% Generate points for the fit
x_ellipse = linspace(min(x_points), max(x_points), 1000);
y_ellipse = NaN(size(x_ellipse));
y_ellipse2 = NaN(size(x_ellipse));

% Compute y_ellipse and y_ellipse2 
indices = ((a(4)*x_ellipse + a(5)).^2 - 4*a(3)*(a(1)*x_ellipse.^2 + a(2)*x_ellipse + a(6))) >= 0;
y_ellipse(indices) = (-(a(4)*x_ellipse(indices) + a(5)) + sqrt((a(4)*x_ellipse(indices) + a(5)).^2 - 4*a(3)*(a(1)*x_ellipse(indices).^2 + a(2)*x_ellipse(indices) + a(6)))) / (2*a(3));
y_ellipse2(indices) = (-(a(4)*x_ellipse(indices) + a(5)) - sqrt((a(4)*x_ellipse(indices) + a(5)).^2 - 4*a(3)*(a(1)*x_ellipse(indices).^2 + a(2)*x_ellipse(indices) + a(6)))) / (2*a(3));


figure;
plot(x_points, y_points, 'b.');
hold on;
plot(x_ellipse, real(y_ellipse), 'r-'); 
plot(x_ellipse, real(y_ellipse2), 'r-'); 
hold off;