/**************************
    Autores: Javier Diaz Sanz y Mateo Guijarro Pardo
    Fecha: 10-10-2023
**************************/

#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{ 

 int i, j;
 int tamanyo;
 cout << "Introduzca el lado del triangulo: \n";
    cin >> tamanyo; 
 
 for (i = 0; i < tamanyo; i++)
 { 
    for (j = 1; j <= tamanyo-i; j++)
        cout << "*";
    cout << endl; 
 
 } 
 
 return 0; 
}