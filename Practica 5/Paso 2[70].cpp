/* Mateo Guijarro Pardo y Javier Diaz Sanz
 	Fecha: 17/10/2023	*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
double suma;
long long denominador;
int i;
float umbral;
cout << "Introduzca el umbral que no quieres que sobrepase el ultimo termino: ";
cin >> umbral;
suma = 0;
denominador = 1;
i=1;
while ((1.0/denominador)>=umbral)
{
suma = suma + 1.0 / denominador;
denominador = denominador * i;
i++;
}
cout << "Valor de e: " << suma << endl;
system ("pause");
return 0;
}