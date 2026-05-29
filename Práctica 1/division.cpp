/************************
    Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
    Fecha: 19-09-2023
************************/

#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    
    cout << "Introduce dos numeros enteros \n\n";
    cin >> num1;
    cin >> num2;
    
    cout << endl << "El resultado de la division entera de " << num1  << " entre " << num2 << " es  " << num1/num2 << " y el resto es "  <<num1 % num2 <<endl;
    
    return 0;
}