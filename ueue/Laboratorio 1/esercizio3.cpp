#include <iostream>
#include <math.h>
using namespace std;
//PROTOTIPI FUNZIONI
float Sing_eps(float ,float );
double Doubl_eps(double b, double eps);
//MAIN
int main(){
	
	float E, epsilon;
	float base;
	E=2.0;
	base=2.0;
	
	cout<<"Singola precisione di macchina: "<<Sing_eps(base,E)<<endl; 
	cout<<"Doppia precisione di macchina: "<<Doubl_eps(base,E)<<endl;
}
//DICHIARAZIONE FUNZIONE
float Sing_eps(float b,float eps){
	
		while((1+eps/b)>1.0){
		eps=eps/b;
		}
	return eps;
}


double Doubl_eps(double b, double eps){
		while((1+eps/b)>1.0){
		eps=eps/b;
		}
	return eps;
}
