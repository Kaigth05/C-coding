/****************
    Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
    Fecha: 17-10-2023
****************/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    
long potencia, potencia_anterior, valor;

cout << "Introduzca el limite superior: ";
    cin >> valor;
    
potencia = 1;
potencia_anterior = 0;

if(potencia < valor) 
{

while (potencia < valor)
{
    
    potencia_anterior = potencia;
    potencia = 2 * potencia;

}

cout << "La ultima potencia inferior a " << valor << " es " << potencia_anterior << endl;

}

else
    cout << "\nNo existe potencia de 2 inferior a " << valor <<  endl;

return 0;

}