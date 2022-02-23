#include <iostream>

#include <vector>

#include <cmath>

using namespace std;

//Ilaria Bruzzone = 4844842
//Filippo Rottigni = 4795353

const int d0 = 3;
const int d1 = 5;

const int n0 = 4;
const int n1 = 10;
const int dim_matricola = 10 * (d1 + 1) + d0;

typedef vector < float > Vector;
typedef vector < vector < float > > Matrix;

Matrix m1 = {
  {
    3,
    1,
    -1,
    0
  },
  {
    0,
    7,
    -3,
    0
  },
  {
    0,
    -3,
    9,
    -2
  },
  {
    0,
    0,
    4,
    -10
  }
};

Matrix m2 = {
  {
    2,
    4,
    -2,
    0
  },
  {
    1,
    3,
    0,
    1
  },
  {
    3,
    -1,
    1,
    2
  },
  {
    0,
    -1,
    2,
    1
  }
};

float fact(int);

float norm_infinity(const Matrix &);

void print_matrix(Matrix);

void print_vector(const Vector &);

Matrix Pascal(int);

Matrix Trid(int);

Matrix mult_matrix(Matrix);

void swap_row(Matrix &, Matrix &, int);

void rid(Matrix &, Matrix &);

Vector back_sost(const Matrix &,
  const Matrix &);

Vector solve(Matrix &,
	Matrix &);

Matrix matrice_es3(const unsigned int &);

Matrix mult_scalar(int,
  const Matrix &);

Matrix tilde(const Matrix &,
  const Matrix &);