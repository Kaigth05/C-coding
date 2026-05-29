/* Mateo Guijarro Pardo y Javier Diaz Sanz
 	Fecha: 10/10/2023	*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
int primero, ultimo;
long suma;
cout << "introduzca el primer numero del intervalo en el que desea sumar impares: ";
cin >> primero;
cout << "introduzca el ultimo numero del intervalo: ";
cin >> ultimo;
suma = 0;
for (primero; primero <= ultimo; primero++)
{
		if (primero%2==1)
	suma = suma + primero;
}
cout << "La suma de todos los numeros impares en dicho intervalo es "<< suma << endl;
system("pause");
return 0;
}