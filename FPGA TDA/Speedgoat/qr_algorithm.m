function [eigenvectors, eigenvalues] = qr_algorithm(A)
    % Maximum number of iterations
    max1 = 500; 

    % Size of matrix A
    n = size(A,1);
    
    % Initialize V to the identity matrix
    V = eye(n); 

    for k = 1:max1
        % Compute the QR factorization of A
        [Q,R] = gram_schmidt(A); 
        % Set A to the result of the QR algorithm
        A = R*Q;
        % The eigenvectors are accumulated in V
        V = V*Q; 
    end
    
    % The eigenvalues are on the diagonal of A
    eigenvalues = A;
    
    % The eigenvectors are the columns of V
    eigenvectors = V;
end