//    ENRICO PEZZANO   S4825087
//    MATTEO MANNAI    S4823690
//    MARIO SGUARIO    S4841630

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int NormaINF (int,int);
void PrintMatrix (int,int);

int main()
{
    
    int n;
    cout<<" inserisci la dimensione della matrice quadrata"<<endl;
    cin>>n;
    
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<" inserisci il valore in posizione A:"<<i<<j<<endl;
            cin>>A[i][j];
        }
    }
}

int NormaINF (int A[][],int n)
{
    //max 1-n(somm j-n(|aij|))
    int sum=0;
    int max=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum =sum + fabs(A[i][j]);
        }
     if(sum>max)
         max=sum;
    }
    return max;
}

void PrintMatrix (int A[][],int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<A[i][j];
        }
    }
}
