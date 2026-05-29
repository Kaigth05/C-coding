/* Mateo Guijarro Pardo y Javier Diaz Sanz
		Fecha: 03/10/2023			 */
#include <iostream>
using namespace std;
int main()
{	float valor_x;
	float valor_y;
cout<<"dame el valor x"<<endl;
cin>>valor_x;
cout<<"dame el valor y"<<endl;
cin>>valor_y;

if ((valor_x<0.5)&&(valor_x>-0.5)&&(valor_y<0.5)&&(valor_y>-0.5))
	cout<<"esta dentro del cuadrado";
else
	cout<<"esta fuera del cuadrado";
return 0;
}