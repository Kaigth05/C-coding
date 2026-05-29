/****************************************
    Autores: Jacier Díaz Sanz y Mateo Guijarro Pardo
    Fecha : 31-10-2023
****************************************/

#include <iostream>
#include <cmath>
using namespace std;

void IntroducirCoordenadasCartesianas (float&,float&);
void Cart2Polar (float&, float&);
void MostrarResultadosEnPolares (float&, float&);

int main(void)
{
	float x, y;

	IntroducirCoordenadasCartesianas (x, y);
	Cart2Polar (x, y);
	MostrarResultadosEnPolares(x, y);

	return 0;
} 

void IntroducirCoordenadasCartesianas (float &x, float &y)
{
	cout <<"dame las coordenadas x, y: \n";
	cin >> x >> y;
    
}

void Cart2Polar (float &x, float &y)
{
	float i, j, pi;
    
	pi = M_PI;
	i = x;
	j = y;
	x = sqrt(pow(i, 2) + pow (j, 2) );
	y = atan(j / i);
    
    if (i < 0 && j <0)
    {
        y = y - pi;
    }
    
    if (i < 0 && j >0)
    {
        y = y + pi;
    }
    
	while (y > pi)
		y = y - pi;
	while (y < -pi)
		y = y + pi;
}

void MostrarResultadosEnPolares (float &x, float &y)
{
	cout << "dichas coordenadas en polares serian: ("<<x<<", "<<y<< " radianes)" <<endl;

}