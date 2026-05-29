/**************************
    Autores: Javier Diaz Sanz y Mateo Guijarro Pardo
    Fecha: 10-10-2023
**************************/

#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{ 
 int i;
 int terminos;
 long double factorial;
 long double suma;
 long double ex;
 cout << "Introduzca el numero de terminos: ";
 cin >> terminos;
 factorial = 1;
 suma = 0;
 ex = 1;
 
 for (i = 0; i < terminos; i++)
 { 
 
 suma = suma + ex;
 factorial = (i+1) * factorial;
 ex = 1 / factorial;
 
 } 
 
 cout << "El resultado de la e^x es: " << suma << endl;
 
 return 0;
}