//Celeste Bazzi, Luca Comparini, Eugenio Pallestrini
#include <iostream>
#include <math.h>
using namespace std;


/*2. Fissato l’intero positivo N, implementare un programma che permetta di calcolare fN(x) per il punto x e il grado N dati in input.
Considerare i due algoritmi seguenti per i valori descritti dei parametri x e N, confrontando i risultati ottenuti per fN (x) con i valori restituiti per f (x) dalla funzione exp della libreria ANSI math.h, tramite errore relativo e assoluto.
- Algoritmo 1: determinare un’approssimazione di f(x) per il punto x = 0.5 ed il punto x = 30, valutando fN (x) per N = 3, 10, 50, 100, 150. Ripetere l’esercizio considerando il punto x = −0.5 ed il punto x = −30.
- Algoritmo 2: Osservando che per l’esponenziale vale f (−x) = 1/f (x) e quindi f (−x) ≈ 1/fN (x), de- terminare una diversa approssimazione di f(−0.5) e f(−30) nel modo seguente: valutare fN(+0.5) e fN (+30) per N = 3, 10, 50, 100, 150 e, successivamente, calcolarne il reciproco.*/

const int I = 4; //numero pari
const int J = 5;
const	double x[I]={0.5,30,-0.5,-30}; //prima meta' numeri positivi, la seconda meta' l'opposto della prima
const	double n[J]={3,10,50,100,150};

double factorial(double); //calcola ricorsivamente il fattoriale di n
double taylor(double, double); //calcola ricorsivamente l'esponenziale di x usando il polinomio di taylor di grado N
double err_assoluto(double, double); //calcola l'errore assoluto, ovvero: |x_perturbato-x_corretto|
double err_relativo(double, double); //calcola l'errore relativo, ovvero: err_assoluto/x_corretto
void algoritmo(); 	// esecuzione dell'intero algoritmo: ...


int main(){
	
	algoritmo();

}

double taylor(double x, double n){
	if(n==0) return 1;
	if(n==1) return x+1;
	return taylor(x, n-1) + pow(x,n)/factorial(n);
}

double factorial(double n){
  if(n==1) return 1;
  return n*factorial(n-1);
}

double err_assoluto(double x_perturbato, double x_corretto){
	return x_perturbato-x_corretto;
}

double err_relativo(double x_perturbato, double x_corretto){
	return err_assoluto(x_perturbato, x_corretto)/x_corretto;
	
}

void algoritmo(){
	double x_perturbato;
	double x_corretto;
	
	for(int i=0; i<I; i++){
		for(int j=0; j<J; j++){
			cout << "\n--------------------------------\n" << endl;
			cout << "x= " << x[i] <<"\nN= " << n[j] << endl;
			
			cout << "\nAlgoritmo 1:" << endl;
			
			x_perturbato = taylor(x[i],n[j]);
			x_corretto = exp(x[i]);
			cout << "valore fN(x):    " << x_perturbato << endl;
			cout << "valore exp(x):   " << x_corretto << endl;
			cout << "errore assoluto: " << err_assoluto(x_perturbato, x_corretto) << endl;
			cout << "errore relativo: " << err_relativo(x_perturbato, x_corretto) << endl;
			
			if(i>=I/2){
				cout << "\nAlgoritmo 2:" << endl;
				
				x_perturbato = taylor(x[i-I/2],n[j]);
				
				cout << "valore 1/fN(-x): " << 1/x_perturbato << endl;
				cout << "valore exp(x):   " << x_corretto << endl;
				cout << "errore assoluto: " << err_assoluto(1/x_perturbato, x_corretto) << endl;
				cout << "errore relativo: " << err_relativo(1/x_perturbato, x_corretto) << endl;			
			}
		}
	}
}
