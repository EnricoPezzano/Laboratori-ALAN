% Es1

% Ilaria Bruzzone = 4844842
% Filippo Rottigni = 4795353

d0 = 3;
d1 = 5;
n = 10*(d1+1) + d0;

A = diag(ones(1, n-1), 1) + eye(n);
E = zeros(n);
E(n, 1) = 2^(-n);
B = A+E;

syms lambda;
SA = double(solve(det(A-lambda*eye(n))==0, lambda))
SB = double(solve(det(B-lambda*eye(n))==0, lambda));
VA = eig(A) % vettore di autovalori di A
VB = eig(B)

resA = isequal(SA,VA) % se 1 allora sono uguali
resB = isequal(SB,VB)

n1 = norm(B-A)/norm(A)
n2 = norm(VB-VA)/norm(VA)

% A e B trasposte
At = A';
Bt = B';

SAt = double(solve(det(At-lambda*eye(n))==0, lambda));
SBt = double(solve(det(Bt-lambda*eye(n))==0, lambda));
VAt = eig(At); % vettore di autovalori di A trasposta
VBt = eig(Bt);

resA = isequal(SAt,VAt)
resB = isequal(SBt,VBt)

n3 = norm(At-A)/norm(A)
n4 = norm(VAt-VA)/norm(VA)
n5 = norm(Bt-B)/norm(B)
n6 = norm(VBt-VB)/norm(VB)

