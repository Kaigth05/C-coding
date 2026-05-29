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
 long double suma;
 long double div;
 cout << "Introduzca el numero de terminos: ";
 cin >> terminos;
 suma = 0;
 div = 1;
 
 for (i = 1; i <= terminos; i++)
 { 
 
 suma = suma + div;
 div = 1.0 / (i + 1);
 
 } 
 
 cout << "El resultado de la e^x es: " << suma << endl;
 
 return 0;
}