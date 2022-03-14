%ESERCIZIO 3

A = [1 -1 2; 
    -2 0 5; 
    6 -3 6]

p = [1;
     1;
     1];

q = [3;
     10;
     4];

disp("Applichiamo il metodo delle potenze con  (1, 1, 1)' ");
[y,lambda1,i]=potenze(3,A,p,1000,1e-10)
disp("Applichiamo il metodo delle potenze con (3, 10, 4)' ");
[y,lambda2,i]=potenze(3,A,q,1000,1e-10)

disp("Applichiamo il metodo delle potenze inverse con p=4");
[lambda3,i]=potenze_inverse(A,1e-10,1000,p,4,3)
disp("Applichiamo il metodo delle potenze inverse con p=4.5");
[lambda4,i]=potenze_inverse(A,1e-10,1000,q,4.5,3)



