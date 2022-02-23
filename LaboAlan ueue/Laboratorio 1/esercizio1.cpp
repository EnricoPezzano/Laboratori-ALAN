#include <iostream>
#include <cmath>
using namespace std;
//esercizio 1 lab 1 (Alan)

int  main(){
	int d0=2; //ultima cifra matricola Bruzzone Ilaria
	int d1=4; //penultima cifra matricola Bruzzone Ilaria
	double a,b,c, pot,pot1,ris,ris1;
	
	for(int i=0;i<=6;i++){
		pot=pow(10,i);
		a=(d0+1)*pot;
	
		pot1=pow(10,20);
		b=(d1+1)*pot1;
		
		c=-b;
		//----eseguo calcoli--//
		
		ris=(a+b)+c;
		ris1=a+(b+c);
		
		cout<<" Quando i vale: "<<i<<endl;
		cout<<"risultato di (a+b)+c:"<<ris<<endl;
		cout<<"risultato di a+(b+c)"<<ris1<<endl;
	}
	
	
	
	
	
}

