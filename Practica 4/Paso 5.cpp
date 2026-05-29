/* Mateo Guijarro Pardo y Javier Diaz Sanz
 	Fecha: 10/10/2023	*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
int i, n ;
cout  << "las tablas de multiplicar del 1 al 10 son: " << endl;
for (i = 1; i <= 10; i++)
{
	for (n=1; n<=10 ;n++)
	cout<< i << "*" << n << " = " << i*n << endl ;
	
}
return 0;
}