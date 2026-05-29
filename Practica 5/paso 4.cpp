/****************
    Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
    Fecha: 17-10-2023
****************/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() 
    {
        int acc;
        float num, div;
        
        cout << "Introduzca entero positivo (terminar poniendo un 0): \n";
            cin >> num;
        
        do 
        {
            if(num !=0)
            {
                div=num/10;
                num=div;
                
                if(div>=0.1)
                {
                    acc++;
                }
                
            }
            
        }
        
        while (div >= 0.1);
        
        cout << "El numero escogido tiene " << acc << "digitos";
        
        return 0;
        
    }