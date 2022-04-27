%{ 
ESERCIZIO 1
Celeste Bazzi:S4840738
Luca Comparini:S4184885
Eugenio Pallestrini:S4878184
%}
d0 = 4;
d1 = 8;
n = 10*(d1+1) + d0;
A = diag(ones(1, n-1), 1) + eye(n);
E = zeros(n);
E(n, 1) = 2^(-n);
B = A+E;
syms lambda;
SA = double(solve(det(A-lambda*eye(n))==0, lambda));
SB = double(solve(det(B-lambda*eye(n))==0, lambda));
% autovalori
VA = eig(A)
VB = eig(B)
resA = isequal(SA,VA)
resB = isequal(SB,VB)
% norme
n1 = norm(B-A)/norm(A)
n2 = norm(VB-VA)/norm(VA)

% A trasposta e B trasposta
At = A';
Bt = B';
SAt = double(solve(det(At-lambda*eye(n))==0, lambda));
SBt = double(solve(det(Bt-lambda*eye(n))==0, lambda));
% autovalori trasposte
VAt = eig(At);
VBt = eig(Bt);
resA = isequal(SAt,VAt)
resB = isequal(SBt,VBt)
n3 = norm(At-A)/norm(A)
n4 = norm(VAt-VA)/norm(VA)
n5 = norm(Bt-B)/norm(B)
n6 = norm(VBt-VB)/norm(VB)

