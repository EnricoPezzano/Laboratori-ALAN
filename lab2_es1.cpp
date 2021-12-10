//    ENRICO PEZZANO   S4825087
//    MATTEO MANNAI    S4823690
//    MARIO SGUARIO    S4841630

#include <iostream>
#include <cmath>
using namespace std;

// int NormaINF (int A,int n){
//     //max 1-n(somm j-n(|aij|))

//     int sum=0;
//     int max=0;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++)
//             sum =sum + fabs(A[i][j]);

//      if(sum>max)
//          max=sum;
//     }
// }
// int main()
// {
//     int n;

//     cout<<" inserisci la dimensione della matrice quadrata"<<endl;
//     cin>>n;

//     int A[n][n];

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cout<<" inserisci il valore in posizione A:"<<i<<j<<endl;
//             cin>>A[i][j];
//         }
//     }
// }

void norma_inf(int A[][4]){
    
}

int main()
{
    int A1[4][4] = {{3,1,-1,0}, {0,7,-3,0}, {0,-3,9,-2}, {0,0,4,-10}};
    int A2[4][4] = {{3,1,-1,0}, {0,7,-3,0}, {0,-3,9,-2}, {0,0,4,-10}};

    norma_inf(A1);
    norma_inf(A2);

}