//  ENRICO PEZZANO  S4825087
//	MATTEO MANNAI	S4823690
//	MARIO SGUARIO	S4841630

// #include <iomanip>  //serve?
#include <iostream>
#include <cmath>
using namespace std;

int main () 
{
	int d = 0;
	float single_precision = 1;

    //Cicliamo finchè il valore è minore della precisione di macchina
	while (single_precision != 0) {
		d++;
		single_precision = pow (2, -d);
	}

    //Usciti dal ciclo il valore di d è il valore minimo tale che 1=1+2^(-d)
    //Dunque lo decrementiamo di uno e calcoliamo esp
	d--;
	single_precision = pow (2, -d);
	
	//Stampiamo il risultato ottenuto
	cout<<"\n";
	cout << setprecision(50)<< "d con Float: " << d << endl << "eps = " << single_precision << endl;

	//Ripetiamo il processo con una variabile double a doppia precisione
	d = 0;
	double double_precision = 1;
	while (double_precision != 0) {
		d++;
		double_precision = pow (2, -d);
	}

	d--;
	double_precision = pow (2, -d);
	cout<<"\n";
	cout << setprecision(50)<<"d con Double: " << d << endl << "eps = " << double_precision<< endl;
}
