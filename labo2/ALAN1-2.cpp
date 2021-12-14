//    ENRICO PEZZANO   S4825087
//    MATTEO MANNAI    S4823690
//    MARIO SGUARIO    S4841630

#include <iostream>
#include <math.h>

using namespace std;

//....................Header............................

struct PointPtr
{
    int payload;
    PointPtr* next;
};

struct DLMatrix
{
    PointPtr* head;
    PointPtr* tail;
}P,T,Pn,Tn;

int factorial(int);
void addNumber(int,DLMatrix&);
void PrintMatrix(int,DLMatrix&);
void Pascal(int,DLMatrix&);
void Tridiagonale(int,DLMatrix&);
long int NormaINF (int,int,DLMatrix&);

//....................Main............................

int main()
{
    int i,j;
    int nMatricola = 10*(3+1) + 0;
    
    cout<<"\nInserisci numero righe della matrice: ";
    cin>>i;
    cout<<endl<<"\nInserisci numero colonne della matrice: ";
    cin>>j;
    cout<<endl;

    Pascal(10,P);
    Tridiagonale(nMatricola,T);
    
    cout<<"Matrice di Pascal:............\n"<<endl;
    PrintMatrix(10,P);
    cout<<"\n  Norma Infinito: "<<NormaINF(10,10,P)<<endl;
    cout<<endl;
    
    cout<<"Matrice di Tridiagonale:............\n"<<endl;
    PrintMatrix(nMatricola,T);
    cout<<"\n  Norma Infinito: "<<NormaINF(nMatricola,nMatricola,T)<<endl;
    cout<<endl;
    
    if(i==j && i>1)
    {
        Pascal(i,Pn);
        Tridiagonale(i,Tn);
        cout<<"Matrice di Pascal con n input:............\n"<<endl;
        PrintMatrix(i,Pn);
        cout<<"\n  Norma Infinito: "<<NormaINF(i,j,Pn)<<endl;
        cout<<endl;
        
        cout<<"Matrice di Tridiagonale con n input:............\n"<<endl;
        PrintMatrix(i,Tn);
        cout<<"\n  Norma Infinito: "<<NormaINF(i,j,Tn)<<endl;
        cout<<endl;
        
        
    }

}

//....................Function Body............................

long int NormaINF (int i, int j, DLMatrix& M)
{
    //max 1-n(somm j-n(|aij|))
    long int sum=0;
    long int max=0;
    
    PointPtr* aux = new PointPtr;
    aux = M.head;
    
        
        for(int x=1; x<=i;x++)
        {
            for(int x=1; x<=j;x++)
            {
                sum =sum + fabs(aux->payload);
                aux=aux->next;
            }
            if(sum>max)
                max=sum;
        }
    return max;
        
}

void Tridiagonale(int n, DLMatrix& M)
{
    int Pij =0;
    
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            if(i==j)
                Pij=2;
            else
            if(fabs(i-j)==1)
                Pij=-1;
            else
                Pij =0;
            
            addNumber(Pij,M);
        }
    }
}

void Pascal(int n, DLMatrix& M)
{
        int Pij =0;
        
        for(int i=1; i<=n;i++)
        {
            for(int j=1; j<=n;j++)
            {
                int Pij = factorial(i+j-2)/(factorial(i-1)*factorial(j-1));
                addNumber(Pij,M);
            }
        }
}


void addNumber(int n, DLMatrix& M)
{
    if(M.head == NULL || M.tail == NULL)
    {
        
        PointPtr* p = new PointPtr;
        M.head = p;
        M.tail = p;
        p->next = NULL;
        p->payload = n;
    }
    else
    {
        PointPtr* p = new PointPtr;
        M.tail->next =  p;
        M.tail = p;
        p->next = NULL;
        p->payload = n;

    }
}

void PrintMatrix(int col,DLMatrix& M)
{
    if(M.head== NULL || M.tail== NULL)
        cout<<"Empty matrix !"<<endl;
    
    else
    {
        PointPtr* aux = new PointPtr;
        aux=M.head;
    
        while(aux->next!=NULL)
        {
            cout<<"  (";
            for(int i=0;i<col;i++)
            {
                cout<<aux->payload<<" ";
                aux=aux->next;
            }
            cout<<")"<<endl;
            if (aux==NULL)
                return;
        }
    }
}


int factorial(int n)
{
    if(n == 0)
        return 1;
    return n * factorial(n-1);
}
