#include <iostream>
using namespace std;
#include <cstdlib>
long int CalcularFactorial (int variable);
int main (void)
{
long int m, n, fac_n, fac_m, fac_mn;
long int comb;
do
{
cout << "Dime numero combinatorio (m sobre n) con m >= n" << endl;
cin >> m >> n;
}
while (m < n);

fac_m = CalcularFactorial(m);
fac_n= CalcularFactorial(n);
fac_mn= CalcularFactorial(m-n);
comb = fac_m / ( fac_n * fac_mn);
cout << "El combinatorio de " << m << " sobre " << n << " es " << comb << endl;
system ("PAUSE");
return 0;
}
long int CalcularFactorial (int variable){
	long int fact;
	int i;
	fact = 1;
	for (i = variable; i >= 1; i--)
	fact = fact * i;
	
	return fact;
}