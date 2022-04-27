//Celeste Bazzi, Luca Comparini, Eugenio Pallestrini
#include <iostream>
#include <math.h>
using namespace std;

/*1. Si consideri il numero di matricola del primo componente, in ordine alfabetico, del gruppo; si indichi con d0 e d1, rispettivamente, l’ultima e la penultima cifra di tale numero di matricola.
Posto a = (d0 +1)·10i, con i = 0,1,...,6, b = (d1 +1)·1020, c = −b, eseguire i seguenti calcoli in aritmetica di macchina a doppia precisione, cio`e utilizzando variabili di tipo double:
• (a+b)+c 
• a+(b+c)*/

int main(){
	//Considerata la matricola S4840738
	double d0 = 8; //ultima cifra della matricola
	double d1 = 3; //penultima cifra della matricola
	double a, b, c; //dichiarazione delle variabili

	for(int i=0; i<=6; i++){
		a=(d0+1)*pow(10,i);
		b=(d1+1)*pow(10,20);
		c=-b;
		cout << "\n--------------------------------\n" << endl;
		cout << "a: " << a << "\n" << "b: " << b << "\n"<< "c: " << c << endl;
		cout << endl;
		cout << "a+b: " << a+b << endl;
		cout << "b+c: " << b+c << endl;
		cout << endl;
		cout << "(a+b)+c: " << (a+b)+c << endl;
		cout << "a+(b+c): " << a+(b+c) << endl;
		cout << "errore assoluto: " << fabs(((a+b)+c)-a) << endl;
		cout << "errore relativo: " << (fabs(((a+b)+c)-a))/a << endl;
	}
}
