/* Mateo Guijarro Pardo y Javier Diaz Sanz
			Fecha:09/11/2023 				*/
#include <iostream>
using namespace std;
#include <cstdlib>

const int N = 100.0 ;
typedef int Vector[N];
void IntroducirVector (Vector, int &);
float MediaAritmetica (const Vector, int);
void MaximoMinimo (const Vector, int, int &, int &);

int main (void)
{
	Vector v;
	float m;
	int n, max, min;
	cout << "Introducir datos del vector:" << endl;
	cout << "---------------------------" << endl;
	IntroducirVector (v, n);
	m = MediaAritmetica (v, n);
	MaximoMinimo (v, n, max, min);
	cout << "La media aritmetica es " << m << endl;
	cout << "El valor maximo es " << max << endl;
	cout << "El valor minimo es " << min << endl;
	return 0;
}
void IntroducirVector ( Vector v, int&N)
{
	int i;
	cout<<"tamano del vector: ";
	cin>>N;
	for(i=0;i<N;i++)
	{
		cout<<"dame su parametro "<<i<<" : ";
		cin>>v[i];
	}
}
float MediaAritmetica (const Vector v, int N)
{
	float m, suma;
	int i;
	suma = 0;
	
	for(i=0;i<N;i++)
	{
		suma += v[i];
	}
	
	m = suma / N;
	
	return m;
}
void MaximoMinimo (const Vector v, int N, int& max, int& min)
{
	int i;
	max=v[1];
	for(i=0;i<N;i++)
	{
		if(v[i] > max)
			max = v[i];
	}
	
	min=v[1];
	for(i=0;i<N;i++)
	{
		if(v[i] < min)
			min = v[i];
	}
	
}