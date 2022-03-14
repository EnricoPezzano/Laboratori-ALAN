#include <iostream>
#include <math.h>
using namespace std;

//-----FATTORIALE---//

double funz_fattoriale(double v){  //FUNZIONE FATTORIALE
	if(v>0){
		for(int i=v-1;i>=1;i--){
			v=(v*i);
		}
	}
	else return 1;
	return v;
}

//--------POLINOMIO DI TAYLOR-----//

double Funz_taylor(double p, double N){  //FUNZIONE POLINOMIO DI TAYLOR
	
	double risultato=0;
	double pot_x;
	for(int i=0;i<=N;i++){
		pot_x=pow(p,i);
		funz_fattoriale(i);
		risultato=risultato+pot_x/funz_fattoriale(i);
	}
	return risultato;
}

//--------------------MAIN----------------//

int main(){
	double x=exp(0.5); //e^x;
	double x1=exp(30); //e^x;
	double x2=exp(-0.5);
	double x3=exp(-30);
	int valori_N[5]={3,10,50,100,150};
	double ris,ris1,risn,ris1n;
	

	cout<<"Approssimazione di f(x)=e^x con x=0.5: "<<x<<endl;
	cout<<"Approssimazione di f(x)=e^x con x=30: "<<x1<<endl;
	cout<<"Approssimazione di f(x)=e^x con x=-0.5: "<<x2<<endl;
	cout<<"Approssimazione di f(x)=e^x con x=-30: "<<x3<<endl;
	
	cout<<"ALGORITMO 1:"<<endl;
	
	for(int j=0;j<5;++j){
		ris=Funz_taylor(0.5,valori_N[j]); //approssimo funzione con polinomio di taylor 
		ris1=Funz_taylor(30,valori_N[j]); 
		
		cout<<"N vale: "<<valori_N[j]<<endl;
		cout<<"Per x=0.5: "<<ris<<endl;
		cout<<"Per x=30: "<<ris1<<endl;
	}
	
	cout<<"-----------------------Ripeto esercizio precedente con valori opposti------------------------------"<<endl;

	
	for(int j=0;j<5;j++){
		ris=Funz_taylor(-0.5,valori_N[j]); 
		ris1=Funz_taylor(-30,valori_N[j]); 
		
		cout<<"N vale: "<<valori_N[j]<<endl;
		cout<<"Per x= -0.5: "<<ris<<endl;
		cout<<"Per x= -30: "<<ris1<<endl;
	}
	
		
	cout<<"ALGORITMO 2:"<<endl;
		
		cout<<"------------------------Calcolo reciproco----------------------"<<endl;

		for(int j=0;j<5;j++){
		ris=Funz_taylor (0.5,valori_N[j]); //approssimo funzione con polinomio di taylor 
		ris1=Funz_taylor (30,valori_N[j]); 
		
		double risn=Funz_taylor (-0.5,valori_N[j]); //approssimo funzione con polinomio di taylor 
		double ris1n=Funz_taylor (-30,valori_N[j]); 
		
		/*cout<<"N vale: "<<val_N[j]<<endl;
		cout<<"Reciproco per x= 0.5: "<<1/risn<<endl; //divido per 1 (calcolo reciproco)
		cout<<"Reciproco per x= 30: "<<1/ris1n<<endl;*/
		
				
		
		cout<<"Reciproco per x= -0.5: "<<1/ris<<endl; //divido per 1 (calcolo reciproco)
		cout<<"Reciproco per x= -30: "<<1/ris1<<endl;
		
		}
		
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"STAMPO ERRORI RELATIVI E ASSOLUTI per 0.5 E 30 '"<<endl;
	
	for(int j=0;j<5;j++){
		ris=Funz_taylor (0.5,valori_N[j]); //approssimo funzione con polinomio di taylor 
		ris1=Funz_taylor (30,valori_N[j]); 
		risn=Funz_taylor (-0.5,valori_N[j]); //approssimo funzione con polinomio di taylor 
		ris1n=Funz_taylor (-30,valori_N[j]); 
		
		cout<<"N vale: "<<valori_N[j]<<endl;
		
		cout<<"errore assoluto 0.5:"<<ris-x<<endl;
		cout<<"errore assoluto 30:"<<ris1-x1<<endl;
		
		
		
		cout<<"errore relativo 0.5:"<<(ris-x)/x<<endl;
		cout<<"errore relativo 30:"<<(ris1-x1)/x1<<endl;
	
	}
	cout<<"STAMPO ERRORI RELATIVI E ASSOLUTI per -0.5 E -30 '"<<endl;
	
	for(int j=0;j<5;j++){
		ris=Funz_taylor (0.5,valori_N[j]); //approssimo funzione con polinomio di taylor 
		ris1=Funz_taylor (30,valori_N[j]); 
		risn=Funz_taylor (-0.5,valori_N[j]); //approssimo funzione con polinomio di taylor 
		ris1n=Funz_taylor (-30,valori_N[j]); 
		
		cout<<"N vale: "<<valori_N[j]<<endl;
		
		cout<<"errore assoluto -0.5:"<<1/ris-x2<<endl;
		cout<<"errore assoluto -30:"<<1/ris1-x3<<endl;
		
		cout<<"errore relativo -0.5:"<<(1/ris-x2)/x2<<endl;
		cout<<"errore relativo -30:"<<(1/ris1-x3)/x3<<endl;
	
		}
	
	}
	
	
	
		
		
		
	
	