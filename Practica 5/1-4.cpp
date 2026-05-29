#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    
float valor;

do
{
    
cout << "Introduzca el valor (0 para acabar): ";
cin >> valor;

if (valor != 0)
    cout << "Su cuadrado es: " << valor * valor << endl;
    
}

while (valor != 0);

return 0;

}