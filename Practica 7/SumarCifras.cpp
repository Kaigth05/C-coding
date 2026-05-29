/****************************************
    Autores: Jacier Díaz Sanz y Mateo Guijarro Pardo
    Fecha : 31-10-2023
****************************************/

#include <iostream>
#include <cmath>
using namespace std;

int ContarCifras (int);
int SumarDigitos (int, int);

int main()
{
    int num, dig, suma;
    cout << "Introduzca un valor entero: \n";
    cin >> num;
    
    dig = ContarCifras (num);
    suma = SumarDigitos (num, dig);
    
    cout << "La suma de los digitos de " << num << " es " << suma << endl;
    
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

int SumarDigitos (int num, int dig)
{
    int cociente, resto, acc;
    
    if (dig == 0)
    {
        acc = 0;
    }
    
    else
    {
        cociente = num / pow (10, dig - 1);
        resto = num - cociente * pow (10, dig -1 );
        acc = cociente + SumarDigitos (resto, dig - 1);
    }
    
    return acc;
}