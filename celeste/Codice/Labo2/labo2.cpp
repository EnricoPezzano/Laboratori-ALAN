#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*Eugenio Pallestrini=4878184
d0 = 4
d1 = 8
*/
typedef float type;
typedef vector<vector<type>> matrice;
const unsigned int size = 4;
const unsigned int size1 = 10;
const unsigned int size2 = 94;

matrice A ={{3, 1, -1, 0},{0, 7, -3, 0},{0, -3, 9, -2},{0, 0 , 4, -10}};
matrice B ={{2, 4, -2, 0},{1, 3, 0, 1},{3, -1, 1, 2},{0, -1 , 2, 1}};

type fattoriale(int);
type normainfinito(const matrice &);
void print(matrice);
matrice pascal(int);
matrice tridiagonale(int);
matrice prodotto_matrice(matrice);
void scambio(matrice &, matrice &, int);
void riduzione (matrice &, matrice &);
vector<type> sost_indietro (const matrice &, const matrice &);
vector<type> risoluzione_sistema (const matrice &, const matrice &);
void print_vector (const vector<type> &);
matrice matrice_perturbata(const unsigned int &);
matrice prodotto_scalare (int, const matrice &);
matrice perturbazione (const matrice &, const matrice &);


int main(){
	//-----------------------esercizio 1-----------------------
	//-----------------------a-----------------------
	cout<<"_________esercizio 1_________"<<endl;
	cout<<"-----------a-----------"<<endl<<endl;
	cout<<"MATRICE A: "<<endl;
	print(A);
	cout<<"Norma infinito: "<<normainfinito(A)<<endl;
	cout<<endl<<endl;
	cout<<"MATRICE B: "<<endl;
	print(B);
	cout<<"Norma Infinito: "<<normainfinito(B)<<endl;

	//-----------------------b-----------------------
	cout<<endl<<endl;
	cout<<"-----------b-----------"<<endl<<endl;
	matrice P = pascal(size1);
	cout<<"MATRICE DI PASCAL: "<<endl;
	print(P);
	cout<<"Norma infinito: "<<normainfinito(P)<<endl;

	//-----------------------c-----------------------
	cout<<endl<<endl;
	cout<<"-----------c-----------"<<endl<<endl;
	matrice T = tridiagonale (size2);
	cout<<"MATRICE TRIDIAGONALE: "<<endl;
	print(T);
	cout<<"Norma Infinito: "<<normainfinito(T)<<endl;

	//-----------------------esercizio 2-----------------------
	cout<<endl<<endl;
	cout<<"_________esercizio 2_________"<<endl<<endl;
	cout<<"Risultato del sistema Ax=b1: "<<endl;
	matrice b1 = prodotto_matrice(A);
	print_vector(risoluzione_sistema(A, b1));
	cout << endl;

	cout<<"Risultato del sistema Bx=b2: "<<endl;
	matrice b2 = prodotto_matrice(B);
	print_vector(risoluzione_sistema(B, b2));
	cout << endl;

	cout<<"Risultato del sistema Px=b3: "<<endl;
	matrice b3 = prodotto_matrice(P);
	print_vector(risoluzione_sistema(P, b3));
	cout << endl;

	cout<<"Risultato del sistema Tx=b4: "<<endl;
	matrice b4 = prodotto_matrice(T);
	print_vector(risoluzione_sistema(T, b4));
	cout<<endl<<endl;

	//-----------------------esercizio 3-----------------------
	cout<<"_________esercizio 3_________"<<endl<<endl;
	cout << "Risultato del sistema Ax=b1+δb1:" << endl;
	matrice mat1 = matrice_perturbata(size);
	matrice δb1 = prodotto_scalare(normainfinito(b1),mat1);
	matrice b1p = perturbazione(b1, δb1);
	print_vector(risoluzione_sistema(A, b1p));
	cout<<endl<<endl;

	cout << "Risultato del sistema Bx=b2+δb2:" << endl;
	matrice mat2 = matrice_perturbata(size);
	matrice δb2 = prodotto_scalare(normainfinito(b2),mat2);
	matrice b2p = perturbazione(b2, δb2);
	print_vector(risoluzione_sistema(B, b2p));
	cout<<endl<<endl;

	cout << "Risultato del sistema Px=b3+δb3:" << endl;
	matrice mat3 = matrice_perturbata(size1);
	matrice δb3 = prodotto_scalare(normainfinito(b3),mat3);
	matrice b3p = perturbazione(b3, δb3);
	print_vector(risoluzione_sistema(P, b3p));
	cout<<endl<<endl;

	cout << "Risultato del sistema Tx=b4+δb4:" << endl;
	matrice mat4 = matrice_perturbata(size2);
	matrice δb4 = prodotto_scalare(normainfinito(b4),mat4);
	matrice b4p = perturbazione(b4, δb4);
	print_vector(risoluzione_sistema(T, b4p));
}

//-----------------------esercizio 1-----------------------

type fattoriale(int n){
	if(n < 0) return -1;
	if(!n) return 1;
	return n*fattoriale(n-1);
}

type normainfinito(const matrice &m){
	type max = 0;
	type sum;
	for (int i = 0; i < m.size(); i++){
		sum = 0;
		for (int j = 0; j < m.at(i).size(); j++)
			sum += fabs(m.at(i).at(j));
		if(max<sum)
			max = sum;
	}
	return max;
}

void print(matrice m){
	for (int i = 0; i < m.size(); i++){
		for (int j = 0; j < m.at(i).size(); j++)
			cout << m.at(i).at(j) << " ";
		cout << endl;
	}
}

matrice pascal(int n){
	matrice p(n);
	for (int i = 0; i < n; i++)
		p.at(i).resize(n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			p.at(i-1).at(j-1) = (fattoriale(i+j-2))/(fattoriale(i-1)*fattoriale(j-1));
	}
	return p;
}

matrice tridiagonale(int n){
	matrice t(n);
	for (int i = 0; i < n; i++)
		t.at(i).resize(n);
	for (int i = 0; i < n; i++){
		for (int j= 0; j < n; j++){
	  		if (i==j)
					t.at(i).at(j)=2;
	  		else if(abs(i-j)==1)
					t.at(i).at(j) = -1;
	  		else t.at(i).at(j) = 0;
		}
  }
  return t;
}

//-----------------------esercizio 2-----------------------
matrice prodotto_matrice(matrice m){
	matrice risultato(m.at(0).size(), vector<type>(1));
	for (int i = 0; i < m.size(); i++){
		type sum = 0;
		for (int j = 0; j < m.at(0).size(); j++){
			sum += m.at(i).at(j);
		}
		risultato.at(i).at(0) = sum;
	}
	return risultato;
}

void scambio(matrice &m, matrice &b, int n){
		type max = fabs(m.at(n).at(n));
		type riga = n;
		for (int i = n+1; i < m.size(); i++){
      if(fabs(m.at(i).at(n)) > max){
				max = fabs(m.at(i).at(n));
				riga = i;
      }
    }
		if (riga!=n){
			vector<type> temp (m.at(n));
			m.at(n) = m.at(riga);
			m.at(riga) = temp;
			vector<type> temp1 (b.at(n));
			b.at(n) = b.at(riga);
			b.at(riga) = temp1;
		}
}

void riduzione (matrice &m, matrice &b) {
	for (int k = 0; k<m.at(0).size()-1; k++) {
			scambio(m, b, k);
		for (int i = k+1; i<m.size(); i++){
			type mul = (m.at(i).at(k))/(m.at(k).at(k));
			b.at(i).at(0) -= mul*b.at(k).at(0);
			for (int j = k+1; j<m.at(0).size(); j++)
				m.at(i).at(j) -= mul*m.at(k).at(j);
			m.at(i).at(k) = 0;
		}
	}
}

vector<type> sost_indietro (const matrice &m, const matrice &n){
	vector <type> risultato(m.at(0).size());
	int calc = 0;
	risultato.at(risultato.size()-1) = (n.at(n.size()-1).at(0))/(m.at(m.size()-1).at(m.size()-1));
	calc++;
	type to_sub;
	for (int i = m.size()-2; i>=0; i--){
			to_sub = 0;
			for (int j = 1; j<=calc; j++)
				to_sub += risultato.at(risultato.size()-j)*m.at(i).at(m.size()-j);
			risultato.at(i) = (n.at(i).at(0)-to_sub)/m.at(i).at(i);
			calc++;
	}
	return risultato;
}

vector<type> risoluzione_sistema (const matrice &mat, const matrice &ter){
		matrice coeff = mat;
		matrice term_noti = ter;
		riduzione(coeff, term_noti);
		return sost_indietro (coeff, term_noti);
}

void print_vector (const vector<type> &v){
		for (int i = 0; i<v.size(); i++)
				cout << v.at(i) << " ";
		cout << endl;
}

//-----------------------esercizio 3-----------------------
matrice matrice_perturbata(const unsigned int &n){
		matrice target(n, vector<type>(1));
		for (int i = 0; i<target.size(); i++){
			if (i%2!=0)
				target.at(i).at(0) = 0.01;
			else
				target.at(i).at(0) = -0.01;
		}
		return target;
}

matrice prodotto_scalare (int scalar, const matrice &mul){
		matrice result(mul.size(), vector<type>(mul.at(0).size()));
		for (int i = 0; i<result.size(); i++){
			for (int j = 0; j<result.at(i).size(); j++)
				result.at(i).at(j) = (mul.at(i).at(j))*scalar;
		}
		return result;
}

matrice perturbazione (const matrice &b, const matrice &δb){
		matrice to_return(b.size(), vector<type>(1));
		for (int i = 0; i<to_return.size(); i++)
			to_return.at(i).at(0) = b.at(i).at(0)+δb.at(i).at(0);
		return to_return;
}

