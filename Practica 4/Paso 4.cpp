/* Mateo Guijarro Pardo y Javier Diaz Sanz
 	Fecha: 10/10/2023	*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
int i, n ;
float   aproximacion;
cout << "Introduzca la cantidad n primeros terminos con las que quieres que aproxime: ";
cin >> n;
aproximacion=0 ;
for (i = 0; i < n; i++)
{
if (i%2==0)
	aproximacion = aproximacion + 1.0/(2.0*i+1) ;
else if (i%2==1)
	aproximacion = aproximacion - 1.0/(2.0*i+1) ;
}
cout << "La aproximacion a pi con " << n << " terminos segun la formula de Leibnitz es: " << 4.0*aproximacion <<endl;
return 0;
}