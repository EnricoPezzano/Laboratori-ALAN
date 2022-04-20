// ENRICO PEZZANO  S4825087
//	MATTEO MANNAI	 S4823690
//	MARIO SGUARIO	 S4841630

#include <iostream>
#include <cmath>
using namespace std;

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