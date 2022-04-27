#include "lab2_aux.h"



//Ilaria Bruzzone = 4844842
//Filippo Rottigni = 4795353



//Es 1 a)
float fact(int n) {
  if (n < 0)
    return -1;
  if (n == 0 || n == 1)
    return 1;
  return n * fact(n - 1);
}

float norm_infinity(const Matrix &m) {
  float max = 0;
  for (int i = 0; i < m.size(); i++) {
    float sum = 0;
    for (int j = 0; j < m.at(i).size(); j++)
      sum += fabs(m.at(i).at(j));
    if (sum > max)
      max = sum;
  }
  return max;
}

void print_matrix(Matrix m) {
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m.at(i).size(); j++)
      cout << m.at(i).at(j) << " ";
    cout << endl;
  }
}

void print_vector(const Vector &v) {
  for (int i = 0; i < v.size(); i++)
    cout << v.at(i) << " ";
  cout << endl;
}

Matrix Pascal(int n) {
  Matrix pascal(n);
  for (int i = 0; i < n; i++)
    pascal.at(i).resize(n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      pascal.at(i - 1).at(j - 1) = (fact(i + j - 2)) / (fact(i - 1) * fact(j - 1));
  return pascal;
}

Matrix Trid(int n) {
  Matrix trid(n);
  for (int i = 0; i < n; i++)
    trid.at(i).resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        trid.at(i).at(j) = 2;
      else if (abs(i - j) == 1)
        trid.at(i).at(j) = -1;
      else trid.at(i).at(j) = 0;
    }
  }
  return trid;
}



//Es 2
Matrix mult_matrix(Matrix m) {
  Matrix risultato(m.at(0).size(), Vector(1));
  for (int i = 0; i < m.size(); i++) {
    float somma = 0;
    for (int j = 0; j < m.at(0).size(); j++) {
      somma += m.at(i).at(j);
    }
    risultato.at(i).at(0) = somma;
  }
  return risultato;
}

void swap_row(Matrix &m, Matrix &b, int n) {
  float max = fabs(m.at(n).at(n));
  float n_riga = n;
  for (int i = n + 1; i < m.size(); i++) {
    if (fabs(m.at(i).at(n)) > max) {
      max = fabs(m.at(i).at(n));
      n_riga = i;
    }
  }
  if (n_riga != n) {
    Vector temp(m.at(n));
    m.at(n) = m.at(n_riga);
    m.at(n_riga) = temp;
    Vector temp2(b.at(n));
    b.at(n) = b.at(n_riga);
    b.at(n_riga) = temp2;
  }
}

void rid(Matrix &m, Matrix &n) {
  for (int k = 0; k < m.at(0).size() - 1; k++) {
    swap_row(m, n, k);
    for (int i = k + 1; i < m.size(); i++) {
      float mul = (m.at(i).at(k)) / (m.at(k).at(k));
      n.at(i).at(0) -= mul * n.at(k).at(0);
      for (int j = k + 1; j < m.at(0).size(); j++)
        m.at(i).at(j) -= mul * m.at(k).at(j);
      m.at(i).at(k) = 0;
    }
  }
}

Vector back_sost(const Matrix &m,
  const Matrix &n) {
  Vector soluz(m.at(0).size());
  int calc = 0;
  soluz.at(soluz.size() - 1) = (n.at(n.size() - 1).at(0)) / (m.at(m.size() - 1).at(m.size() - 1));
  calc++;
  float to_sub;
  for (int i = m.size() - 2; i >= 0; i--) {
    to_sub = 0;
    for (int j = 1; j <= calc; j++)
      to_sub += soluz.at(soluz.size() - j) * m.at(i).at(m.size() - j);
    soluz.at(i) = (n.at(i).at(0) - to_sub) / m.at(i).at(i);
    calc++;
  }
  return soluz;
}

Vector solve(Matrix &a,
  Matrix &b) {
  rid(a, b);
  return back_sost(a, b);
}



//Es 3
Matrix matrice_es3(const unsigned int &n) {
  Matrix target(n, Vector(1));
  for (int i = 0; i < target.size(); i++) {
    if (i % 2 == 0)
      target.at(i).at(0) = -0.01;
    else
      target.at(i).at(0) = 0.01;
  }
  return target;
}

Matrix mult_scalar(int scalar,
  const Matrix &aux) {
  Matrix result(aux.size(), Vector(aux.at(0).size()));
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.at(i).size(); j++)
      result.at(i).at(j) = (aux.at(i).at(j)) * scalar;
  }
  return result;
}

Matrix tilde(const Matrix &b,
  const Matrix &db) {
  Matrix aux(b.size(), Vector(1));
  for (int i = 0; i < aux.size(); i++)
    aux.at(i).at(0) = b.at(i).at(0) + db.at(i).at(0);
  return aux;
}