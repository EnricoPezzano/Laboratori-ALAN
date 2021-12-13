//    ENRICO PEZZANO   S4825087
//    MATTEO MANNAI    S4823690
//    MARIO SGUARIO    S4841630
//non va, c'è un problema su Fn, probabilmente calcolo fattoriale //METTI TUTTI I TIPI COME FLOAT O COME DOUBLE
#include <iomanip>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

float factorial(int);

void Alg1();
void Alg2();

int main()
{
    unsigned int N[5] = {3,10,50,100,150};
    long double x[4] = {0.5,30,-0.5,-30};
    cout<<"Lanciamo il primo algoritmo: \n";
    Alg1();

    cout<<"Lanciamo il secondo algoritmo: \n";
    Alg2();
}

float factorial(int n){
    if(n == 0)
        return 1;
    return n * factorial(n-1);
}



void Alg1(){
    unsigned int N[5] = {3,10,50,100,150};
    double x[4] = {0.5,30,-0.5,-30};
    long double fun = 0;
    long double som = 0;
    double espo = 0;

    cout<<endl;

    for(int i=0; i<4; i++)
    {
        cout<<"Il punto x="<<x[i]<<"\n\n";
        for(int j=0; j<5; j++)
        {
            for(int n=0; n<N[j]; n++)
            {
                long double potenza = pow(x[i],n);
                long double fattoriale = factorial(n); //da cambiare il tipo delle variabili //potrebbe non essere qui il problema (il calcolo con 30 è bruttino)
                fun= potenza/fattoriale ;
                som+=fun;
                //cout << "fun: " << fun << endl;
            }

            cout<<endl<<endl<<x[i];
            espo =exp(x[i]);
            cout<< setprecision(50) <<"Per N="<<N[j]<<" -> Fn(0)="<<som<<endl;
            som = 0;

        }

        cout<<" \n F di x ="<<espo<<endl;
        cout<<endl;
    }

}


void Alg2(){
    unsigned int N[5] = {3,10,50,100,150};
    long double x[2] = {0.5,30};
    long double fun, som, espo;
    cout<<endl;
    for(int i=0; i<2; i++)
    {
        cout<<"Il punto x="<<x[i]<<"\n\n";
        for(int j=0; j<5; j++)
        {
            for(int n=1; n<N[j]; n++)
            {
                fun=pow(x[i],n) / factorial(n);
                som+=fun;
            }
            espo =exp(x[i]);
            cout<<"Per N="<<N[j]<<" -> Fn(0)="<<1/som<<endl;

        }

        cout<<" \n F di x ="<<1/espo<<endl;
        cout<<endl;
    }

}
