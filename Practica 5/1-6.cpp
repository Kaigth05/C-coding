#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    
long suma;
float media;
int i, valores, numero;

cout << "Introduzca el numero de valores: ";
cin >> valores;
suma = 0;

for (i = 0; i < valores; i++)
{
    
cout << "Introduzca un entero positivo: ";
    cin >> numero;
suma = suma + numero;

}

media = suma / float (valores);
cout << "Media " << media << endl;

system ("pause");

return 0;

}