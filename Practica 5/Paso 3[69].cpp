/* Mateo Guijarro Pardo y Javier Diaz Sanz
 	Fecha: 17/10/2023	*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
int valor;
do {
	cout<<"Introduzca un valor entero entre 1 y 100: \n";
	cin >> valor;
	if(valor <1 || valor >100)
		cout<<"el valor introducido no esta en ese rango \n";
}	while (valor <1 || valor >100);
return 0;
}