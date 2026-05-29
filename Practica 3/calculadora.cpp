/****************
    Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
    Fecha: 03/10/2023

****************/


#include <iostream>
#include <cstdlib>
using namespace std; 

int main (void) 
{
    
    float a, b;
    char operacion;
    
    cout << "Introduzca el valor de a: " <<endl;
         cin >> a;
    cout << "Introduzca el valor de b: " <<endl;
         cin >> b;
    cout << "Introduzca que la operacion que quiere realizar: s, r, m o d"<<endl;
        cin >> operacion; 
 
    switch (operacion)
    {
        case 's': 
            cout <<"La suma de a,b es: " << a+b << endl;
        break ;
        
        case 'r': 
            cout <<"La resta de a,b es: " << a-b << endl;
        break ;
        
        case 'm': 
            cout <<"La multiplicacion de a,b es: " << a*b << endl;
        break ;
        
        case 'd': 
            cout <<"La division de a,b es: " << a/b << endl;
        break ;
        
        default: 
            cout << "No se ha especificado ninguna operacion valida\n";

    }
         
    system ("pause");
    return 0;
    
}