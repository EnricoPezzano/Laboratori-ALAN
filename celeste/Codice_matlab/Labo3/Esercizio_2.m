% ESERCIZIO 2
s = [1 1 1 1 1 1 3 10 4 5 6 8 5 6];
t = [2 7 6 5 3 4 10 11 10 8 5 9 4 8];
%creiamo il grafo e specifico le coppie di nodi con graph(s,t)
%creiamo la matrice di adiacenza con Adjacency(G)
%creiamo la matrice completa dalla matrice sparsa con full
A = full(adjacency(graph(s,t)))
syms count;
V = zeros(1,11);

for i = 1:length(A(:,1))
   count = 0;
   for j = 1:length(A(1,:)) 
       if A(i,j)==1
           count = count+1;
       end
   end
   V(i) = count;
end

D = diag(V);
G = A*inv(D)
%salviamo gli autovalori in una matrice diagonale "autovalori"
%salviamo una matrice "autovettori" dove le colonne sono i corrispondenti
%autovettori in modo che G*autovettori = autovettori*autovalori
[autovettori,autovalori] = eig(G);

autovalori
autovettori
