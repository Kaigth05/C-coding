#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    
long suma;
float media;
int numero,valores;

suma = 0;
valores = 0;

do
{
    
cout << "Introduzca un entero positivo (-1 para finalizar): ";
    cin >> numero;
    
if (numero != -1)
{
    
suma = suma + numero;
valores++;

}

}
while (numero != -1);

media = suma / float (valores);
    cout << "Media " << media << endl;
    
system ("pause");

return 0;

}