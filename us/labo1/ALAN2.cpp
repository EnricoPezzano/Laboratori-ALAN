// ENRICO PEZZANO  S4825087
//	MATTEO MANNAI	 S4823690
//	MARIO SGUARIO	 S4841630

#include <iostream>
#include <math.h>
using namespace std;
/*
Fissato l’intero positivo N, implementare un programma che permetta di calcolare fN(x) per il punto x e il grado N dati in input.
Considerare i due algoritmi seguenti per i valori descritti dei parametri x e N, confrontando i risultati ottenuti per fN (x) con i valori restituiti per f (x) dalla funzione exp
   della libreria ANSI math.h, tramite errore relativo e assoluto.
- Algoritmo 1: determinare un’approssimazione di f(x) per il punto x = 0.5 ed il punto x = 30, valutando fN (x) per N = 3, 10, 50, 100, 150. Ripetere l’esercizio considerando il 
   punto x = −0.5 ed il punto x = −30.
- Algoritmo 2: Osservando che per l’esponenziale vale f (−x) = 1/f (x) e quindi f (−x) ≈ 1/fN (x), de- terminare una diversa approssimazione di f(−0.5) e f(−30) nel modo seguente: 
   valutare fN(+0.5) e fN (+30) per N = 3, 10, 50, 100, 150 e, successivamente, calcolarne il reciproco.
*/


double factorial(double n){
   if(n == 1) return 1;

   return n * factorial(n-1);
}

void Alg1(){
   double N[5] = {3,10,50,100,150};
   double x[4] = {0.5,30,-0.5,-30};
   double fun, som, espo;
   cout<<endl;
   for(int i=0; i<4; i++){
      cout<<"Il punto x="<<x[i]<<"\n\n";
      for(int j=0; j<5; j++){
         for(int n=1; n<N[j]; n++){
            fun=pow(x[i],n) / factorial(n);
            som+=fun;
         }

         espo =exp(x[i]);
         cout<<"Per N="<<N[j]<<" -> Fn(0)="<<som<<endl;
      }

      cout<<" \n F di x ="<<espo<<endl;
      cout<<endl;
   }
}

void Alg2(){
   double N[5] = {3,10,50,100,150};
   double x[2] = {0.5,30};
   double fun, som, espo;
   cout<<endl;
   for(int i=0; i<2; i++){
      cout<<"Il punto x="<<x[i]<<"\n\n";
      for(int j=0; j<5; j++){
         for(int n=1; n<N[j]; n++){
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

int main()
{
   cout<<"Lanciamo il primo algoritmo: \n";
   Alg1();

   cout<<"Lanciamo il secondo algoritmo: \n";
   Alg2();
}