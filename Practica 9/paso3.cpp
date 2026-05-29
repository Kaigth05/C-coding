/************************************* 
Autor: 
Fecha: 04-11-2014 
Objetivo: Aprender el uso de vectores de tamanyo variable 
**************************************/ 

#include <iostream> 
using namespace std; 

const int MAX = 100; 
typedef int Vector[MAX]; 

int main (void) 
{ 
 Vector v; 

 
int i, total, num; 

 

 
// Leemos el vector desde teclado 
 // Primero el tamanyo del vector que vamos a utilizar 
 cout << "Introducir valores del vector" << endl; 
 do 
 { 

 
cout << "Dime el numero de elementos del vector (entre 0 y " << MAX << "): "; 
 cin >> num; 
 } 
 while (num < 0 || MAX <= num); 

// Despues los elementos del vector
 
for (i = 0; i < num; i++) 

 
{ 

 
cout << "Dime elemento " << i << " del vector: "; 
 cin >> v[i]; 

 
} 

 
// Finalmente calculamos la suma de los elementos que hemos utilitzado 
 // Sumamos hasta 'num'. NO sumamos hasta a MAX!! 
 total = 0; 
 for (i = 0; i < num; i++) 

 
total += v[i]; // Es lo mismo que total = total + v[i] 

 
// Mostramos el resultado 
 cout << "La suma de los elementos del vector es: " << total << endl; 

 
return 0; 
}