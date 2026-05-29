/************************************* 
Autor: 
Fecha: 04-11-2010 
Objetivo: Aprender el uso de vectores con valores booleanos 
**************************************/ 

#include <iostream> 
using namespace std; 
#include <cstdlib> 

const int N = 5; 
typedef bool vector[N]; 

int main (void) 
{ 
 
vector v; 
 
int i,pos; 

for (i = 0; i < N; i++) 

v[i] = false; 
 
cout << "Dame un numero entre 0 i " << N - 1 << endl; 
cin >> pos; 

v[pos] = true; 
 
cout << "Dame un numero entre 0 i " << N - 1 << endl; 
cin >> pos; 
v[pos] = true; 
  
cout << "Mostramos" << endl; 

for (i = 0; i < N; i++) 
 
if (v[i] == true) 
cout << "v[" << i << "] = " << v[i] << endl; 
 
system ("pause"); 
 
return 0; 
}
