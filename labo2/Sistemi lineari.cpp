//    ENRICO PEZZANO   S4825087
//    MATTEO MANNAI    S4823690
//    MARIO SGUARIO    S4841630

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<float>> matrice;

int d1 = 3;
int d0 = 0;

const unsigned int nMatricola = 10*(d1+1) + d0;

matrice A ={{3, 1, -1, 0},{0, 7, -3, 0},{0, -3, 9, -2},{0, 0 , 4, -10}};
matrice B ={{2, 4, -2, 0},{1, 3, 0, 1},{3, -1, 1, 2},{0, -1 , 2, 1}};

float fattoriale(int);
float normainfinito(const matrice &);
void print(matrice);
matrice pascal(int);
matrice tridiagonale(int);
matrice prodotto_matrice(matrice);
void scambio(matrice &, matrice &, int);
void riduzione (matrice &, matrice &);
vector<float> sost_indietro (const matrice &, const matrice &);
vector<float> risoluzione_sistema (const matrice &, const matrice &);
void print_vector (const vector<float> &);
matrice matrice_perturbata(const unsigned int &);
matrice prodotto_scalare (int, const matrice &);
matrice perturbazione (const matrice &, const matrice &);


int main(){
    //--------------------esercizio 1--------------------
    
    cout<<"Es 1 a)" <<endl;
    cout<<"A:"<<print(A)<<endl<<"Norma infinito: "<<normainfinito(A)<<endl;
    cout<<endl;
    cout<<"A:"<<print(B)<<endl<<"Norma infinito: "<<normainfinito(B)<<endl;
    cout<<endl;
    
    cout<<"Es 1 b)" <<endl;
    matrice P = pascal(10);
    cout<<"Matrice Pascal:"<<print(P)<<endl<<"Norma infinito: "<<normainfinito(P)<<endl;
    cout<<endl;

    cout<<"Es 1 c)" <<endl;
    matrice T = tridiagonale (nMatricola);
    cout<<"Matrice Tridiagonale:"<<print(T)<<endl<<"Norma infinito: "<<normainfinito(T)<<endl;
    cout<<endl;

    //-----------------------esercizio 2-----------------------
    
    cout<<"Es 2" <<endl;
    
    cout<<"Risultato del sistema b=Ax: "<<endl;
    matrice b1 = prodotto_matrice(A);
    print_vector(ElimGauss(A, b1));
    cout << endl;

    cout<<"Risultato del sistema b=Bx: "<<endl;
    matrice b2 = prodotto_matrice(B);
    print_vector(ElimGauss(B, b2));
    cout << endl;

    cout<<"Risultato del sistema b=Px: "<<endl;
    matrice b3 = prodotto_matrice(P);
    print_vector(ElimGauss(P, b3));
    cout << endl;

    cout<<"Risultato del sistema b=Tx: "<<endl;
    matrice b4 = prodotto_matrice(T);
    print_vector(ElimGauss(T, b4));
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

float fattoriale(int n){
    if(n < 0) return -1;
    if(!n) return 1;
    return n*fattoriale(n-1);
}

float normainfinito(const matrice &m){
    float max = 0;
    float sum;
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
    matrice risultato(m.at(0).size(), vector<float>(1));
    for (int i = 0; i < m.size(); i++){
        float sum = 0;
        for (int j = 0; j < m.at(0).size(); j++)
        {
            sum += m.at(i).at(j);
        }
        risultato.at(i).at(0) = sum;
    }
    return risultato;
}

void print_vector (const vector<float> &v){
        for (int i = 0; i<v.size(); i++)
                cout << v.at(i) << " ";
        cout << endl;
}

//-----------------------esercizio 3-----------------------
matrice matrice_perturbata(const unsigned int &n){
        matrice target(n, vector<float>(1));
        for (int i = 0; i<target.size(); i++){
            if (i%2!=0)
                target.at(i).at(0) = 0.01;
            else
                target.at(i).at(0) = -0.01;
        }
        return target;
}

matrice prodotto_scalare (int scalar, const matrice &mul){
        matrice result(mul.size(), vector<float>(mul.at(0).size()));
        for (int i = 0; i<result.size(); i++){
            for (int j = 0; j<result.at(i).size(); j++)
                result.at(i).at(j) = (mul.at(i).at(j))*scalar;
        }
        return result;
}

matrice perturbazione (const matrice &b, const matrice &δb){
        matrice to_return(b.size(), vector<float>(1));
        for (int i = 0; i<to_return.size(); i++)
            to_return.at(i).at(0) = b.at(i).at(0)+δb.at(i).at(0);
        return to_return;
}
