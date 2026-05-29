#include <iostream>
using namespace std;

unsigned long long factorial (int);
int main (void)

{ 
    int num;
    unsigned long long fact;
    
    cout << "Dame numero: ";
    cin >> num;
    
    if (num < 0)
    cout << "No se puede calcular el factorial" << endl;
    
    else
    { 
        fact = factorial (num);
        cout << "El factorial de " << num << " es: " << fact;
    } 
    
    return 0;
} 

unsigned long long factorial (int num) 
{
    unsigned long long resultado;
    
    if(num == 0)
    {
        resultado = 1;
    }
    
    else
        resultado = num * factorial (num - 1);
        
    return resultado;
}