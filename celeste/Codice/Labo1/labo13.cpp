//Celeste Bazzi, Luca Comparini, Eugenio Pallestrini
#include <iostream>
#include <math.h>

using namespace std;

/*3. Implementare un programma che determina la precisione di macchina eps, ossia il valore positivo eps = 2^-d, dove d e' il piu' grande intero positivo tale che 1 + 2^-d > 1 in aritmetica di macchina; calcolarne il valore sia in singola che in doppia precisione.*/

float find_singola_precisione();
double find_doppia_precisione();


int main(){

float singola=find_singola_precisione();
double doppia=find_doppia_precisione();

cout << "singola precisione: eps = 2^-" <<singola << "="<< pow(2,-singola) << endl;
	cout << "doppia precisione:  eps = 2^-" << doppia << "="<< pow(2,-doppia)<< endl;
}

float find_singola_precisione(){
	float p=0;
	float eps= 1;
	for(int d=0; 1+eps > 1; d++){
		eps= pow(2,-d);
		if(1+eps == 1) p= d-1;
	}
	return p;
}


double find_doppia_precisione(){
	double p=0;
	double eps= 1;
	for(int d=0; 1+eps > 1; d++){	
		eps= pow(2,-d);
		if(1+eps == 1) p=d-1;
	}
	return p;
}
