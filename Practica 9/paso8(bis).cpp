/************************************* 
Autor: Javier Díaz Sanz y Mateo Guijarro Pardo
Fecha: 07-11-2023 
Objetivo: Aprender el uso de vectores con valores booleanos 
**************************************/ 

#include <iostream> 
using namespace std; 
#include <cstdlib> 

const int N = 251;
typedef bool vector[N]; 

int main (void) 
{ 
    vector v; 
     
    int i, pos; 
    i = 0;
    
    for (i = 0; i < N ; i++) 
    {
        v[i] = false;
    }
    
    do
    {
        cout << "Dame un numero entre 0 i " << N - 1 << endl; 
        cin >> pos; 
        
        if (pos > -1 && pos < 251)
        {
            v[pos] = true;
        } 
    }
    
    while (v[pos] == true);
    
    cout << "Mostramos" << endl;
    
    for (i = 0; i < N; i++)
    {
        if (v[i] == true) 
        cout << "v[" << i << "] = " << v[i] << endl;
    } 
    
    return 0; 
}
