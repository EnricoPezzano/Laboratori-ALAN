% Es 1
% Ilaria Bruzzone = 4844842
% Filippo Rottigni = 4795353

% d0 = 3
% d1 = 5

m = 10*(4+1)+5;
A = [m,3];

for i=1:m
    for j=1:3
       if (j == 1)
           A(i,j) = 1;
       else
           A(i,j) = i/m;
       end
    end
end

A(:,3)= A(:,3).^2;

[U1,S1,V1] = svd(A);
Vect = diag(S1);
disp(Vect);
[U2,S2,V2] = svd(A');
Vect = diag(S2);
disp(Vect);

disp("Autovalori di AA'");
Vect = eig(A*A.');
disp(Vect);
disp("Autovalori di A'A");
Vect = eig(A.'*A);
disp(Vect);

disp("Immagine di A, confrontadola con U");
Im1 = orth(A);
disp("Immagine di A");
disp(Im1);

disp("Kern di A, confrontandolo con V'");
Ker1 = null(A);
disp(Ker1);

disp("Immagine di A', confrontandola con U");
Im2 = orth(A');
disp("Immagine di A'");
disp(Im2);
disp("Kern di A', confrontandolo con V'");
Ker2 = null(A')
disp(Ker2);