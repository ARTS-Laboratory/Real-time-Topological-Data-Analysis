function [a, M, M_rearranged] = fitzgibbon(x,y)

D1 = [x .^ 2, x .* y, y .^ 2 ];
D2 = [x,y, ones(size(x))];

S1 = D1' * D1;
S2 = D1' * D2;
S3 = D2' * D2;

T = - inv(S3) * S2'; % inv() not supported by HDL Coder

M = S1 + S2 * T;
M_rearranged = M;  % Store the original M matrix
M = [M(3, :) ./ 2; - M(2, :); M(1, :) ./ 2];

[evec, eval] = eig(M); % eig() not supported by HDL Coder

cond = 4 * evec(1, :) .* evec(3, :) - evec(2, :) .^ 2;

a1 = evec(:, cond > 0);

a = [a1; T * a1];

end