#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    
float valor;
cout << "Introduzca el valor (0 para acabar): ";
    cin >> valor;
    
while (valor != 0)
{
    
cout << "Su cuadrado es: " << valor * valor << endl;
cout << "Introduzca el valor (0 para acabar): ";
cin >> valor;

};

system ("pause");

return 0;

}