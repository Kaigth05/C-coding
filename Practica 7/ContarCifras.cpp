/****************************************
    Autores: Jacier Díaz Sanz y Mateo Guijarro Pardo
    Fecha : 31-10-2023
****************************************/

#include <iostream>
#include <cmath>
using namespace std;

int ContarCifras (int);

int main()
{
    int num, dig;
    cout << "Introduzca un valor entero: \n";
    cin >> num;
    
    dig = ContarCifras (num);
    
    cout << "La cantidad de digitos de " << num << " es " << dig << endl;
    
    return 0;
}

int ContarCifras (int num)
{
    int acc;
    
    if (num == 0)
    {
        acc = 0;
    }
    
    else
    {
        acc = 1 + ContarCifras (num/10);
    }
    
    return acc;
}
