#include "lab2_aux.cpp"


//Ilaria Bruzzone = 4844842
//Filippo Rottigni = 4795353

int main()
{
  //Es 1 a)
  cout << "----------*Esercizio 1, punto a)*----------" << endl << endl;
  cout << "La matrice A:" << endl;
  print_matrix(m1);
  cout << "La norma infinito vale: " << norm_infinity(m1) << endl;
  cout << endl << endl;
  cout << "La matrice B:" << endl;
  print_matrix(m2);
  cout << "La norma infinito vale: " << norm_infinity(m2) << endl;

  //Es 1 b)
  cout << endl << endl;
  cout << "----------*Esercizio 1, punto b)*----------" << endl << endl;
  Matrix Pasc = Pascal(n1);
  cout << "La matrice di Pascal:" << endl;
  print_matrix(Pasc);
  cout << "La norma infinito vale: " << norm_infinity(Pasc) << endl;

  //Es 1 c)
  cout << endl << endl;
  cout << "----------*Esercizio 1, punto c)*----------" << endl << endl;
  Matrix Tri = Trid(dim_matricola);
  cout << "La matrice tridiagonale:" << endl;
  print_matrix(Tri);
  cout << "La norma infinito vale: " << norm_infinity(Tri) << endl;

  //Es 2
  cout << endl << endl;
  cout << "----------*Esercizio 2*----------" << endl << endl;
  cout << "Matrice A:" << endl;
  Matrix aux1 = mult_matrix(m1);
  print_vector(solve(m1, aux1));
  cout << endl;

  cout << "Matrice B:" << endl;
  Matrix aux2 = mult_matrix(m2);
  print_vector(solve(m2, aux2));
  cout << endl;

  cout << "Matrice Pascal:" << endl;
  Matrix aux3 = mult_matrix(Pasc);
  print_vector(solve(Pasc, aux3));
  cout << endl;

  cout << "Matrice Tridiagonale:" << endl;
  Matrix aux4 = mult_matrix(Tri);
  print_vector(solve(Tri, aux4));
  cout << endl << endl;

  //Es 3
  //Matrici ausilirie:
  Matrix mat1;
  Matrix mat2;
  Matrix mat3;
  
  
  cout << "----------*Esercizio 3*----------" << endl << endl;
  cout << "Matrice A:" << endl;
  mat1 = matrice_es3(n0);
  mat2 = mult_scalar(norm_infinity(aux1), mat1);
  mat3 = tilde(aux1, mat2);
  print_vector(solve(m1, mat3));
  cout << endl << endl;

  cout << "Matrice B:" << endl;
  mat1 = matrice_es3(n0);
  mat2 = mult_scalar(norm_infinity(aux2), mat1);
  mat3 = tilde(aux2, mat2);
  print_vector(solve(m2, mat3));
  cout << endl << endl;

  cout << "Matrice Pascal:" << endl;
  mat1 = matrice_es3(n1);
  mat2 = mult_scalar(norm_infinity(aux3), mat1);
  mat3 = tilde(aux3, mat2);
  print_vector(solve(Pasc, mat3));
  cout << endl << endl;

  cout << "Matrice Tridiagonale:" << endl;
  mat1 = matrice_es3(dim_matricola);
  mat2 = mult_scalar(norm_infinity(aux4), mat1);
  mat3 = tilde(aux4, mat2);
  print_vector(solve(Tri, mat3));
}