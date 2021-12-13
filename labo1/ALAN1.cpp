//  ENRICO PEZZANO  S4825087
//	MATTEO MANNAI	S4823690
//	MARIO SGUARIO	S4841630

#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;


int main () {

//Enrico è il primo membro del gruppo: le ultime due cifre del suo numero di matricola sono rispettivamente:
	double d0 = 7;
	double d1 = 8;

//Assegnamo alle variabili i loro valori per quanto possibile
	double a = d0+1;
	double b = (d1+1) * pow(10,20);
	double c = -b;

  double abs_err1 = 0;
  double abs_err2 = 0;
  double rel_err1 = 0;
  double rel_err2 = 0;

// Iteriamo su i e svolgiamo i calcoli, per ogni valore:
	for (int i = 0; i <= 6; ++i) {
    a = d0+1;                           //inizializzo a ad ogni ciclo
		a = a * pow(10,i);

    cout << "i = " << i << "\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "c = " << c << "\n";

    cout << endl;

    double sum1 = (a + b) + c;
    double sum2 = a + (b + c);
    abs_err1 = fabs(sum1-a);            //calcolo errore assoluto
    abs_err2 = fabs(sum2-a);
    rel_err1 = abs_err1/a;              //calcolo errore relativo
    rel_err2 = abs_err2/a;

    cout << setprecision(22) << "(a + b) + c = " << sum1 << "\n";       //uso setprecision() per visualizzare il numero intero
    cout << "erorre assoluto (a + b) + c ->" << abs_err1 << endl;
    cout << "erorre relativo (a + b) + c ->" << rel_err1 << endl;

    cout << endl;

    cout << setprecision(22) << "a + (b + c) = " << sum2 << "\n";
    cout << "erorre assoluto a + (b + c) ->" << abs_err2 << endl;
    cout << "erorre relativo a + (b + c) ->" << rel_err2 << endl;

    cout << endl;
    cout << endl;
	}
}
