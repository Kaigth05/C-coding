#include <iostream>
using namespace std;
#include <cstdlib>

void IntroducirParametros (long int&m, long int&n);
long int CalcularFactorial (int variable);
void MostrarResultado(long int m, long int n, long int comb);

int main (void)
{
    long int m, n, fac_n, fac_m, fac_mn;
    long int comb;
    m = 0;
    n = 0;
    IntroducirParametros (m,n);
    
    fac_m = CalcularFactorial(m);
    fac_n= CalcularFactorial(n);
    fac_mn= CalcularFactorial(m-n);
    comb = fac_m / ( fac_n * fac_mn);
    MostrarResultado (m, n, comb);
    
    return 0;
}

void IntroducirParametros (long int&m, long int&n)
{ 
    do
    {
        cout << "Dime numero combinatorio (m sobre n) con m >= n" << endl;
        cout << "Dame el valor del primer parametro: " << endl;
        cin >> m;
        cout << "Dame el valor del segundo parametro: " << endl;
        cin >> n;
    }
    
    while (m < n);

 return;
}
 
long int CalcularFactorial (int variable)
{
	long int fact;
	int i;
	fact = 1;
	for (i = variable; i >= 1; i--)
	fact = fact * i;
	
	return fact;
}

void MostrarResultado(long int m, long int n, long int comb)
{
    cout << "Combinatorio de " << m << " sobre " << n << " = " << comb << endl;
    return;
}
    