/* Mateo Guijarro Pardo y Javier Diaz Sanz
 	Fecha: 17/10/2023	*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
int i, a, b , area, lado_a , lado_b;
area = 0;
a = 0;
b = 20;
for (i = 0; i <= 10; i++)
{
	a += 1;
	b -= 1;
	if (area<a*b){
		area=a*b;
		lado_a=a;
		lado_b=b;
	}
	
	
	
}
cout  << "el rectangulo con maxima area con perimetro 40 es de lado "<< lado_a << " y " << lado_b << " y area " << area << endl;
return 0;
}