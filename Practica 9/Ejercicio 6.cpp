/* Mateo Guijarro Pardo y Javier Diaz Sanz
			Fecha:09/11/2023 				*/
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cmath>
#include <fstream>

const int N = 100.0 ;
typedef int Vector[N];
void IntroducirVector (Vector, int &);
float MediaAritmetica (const Vector, int);
void MaximoMinimo (const Vector, int, int &, int &);
float DesviacionStandard(const Vector, int);

int main (void)
{
	ifstream vector;
	Vector v;
	float m, sumatorio;
	int n, max, min;
    
	cout << "Introducir datos del vector:" << endl;
	cout << "---------------------------" << endl;
    
	IntroducirVector (v, n);
	m = MediaAritmetica (v, n);
	MaximoMinimo (v, n, max, min);
	sumatorio = DesviacionStandard  (v, n);
    
	cout << "La media aritmetica es " << m << endl;
	cout << "El valor maximo es " << max << endl;
	cout << "El valor minimo es " << min << endl;
	cout << "La desviacion tipica es " << sqrt(sumatorio) << endl;
    
	return 0;
}
void IntroducirVector ( Vector v, int&N)
{
	ifstream vector;
	int i;
    
	vector.open("info_vector.txt");
	if(!vector)
		cout<<"No se ha podido abrir el fichero"<<endl;
        
	else
    {
		vector>>N;
		cout<<"tamano del vector: "<<N<<endl;
		
		for(i = 0; i < N ; i++)
		{
			vector >> v[i];
			cout << "su parametro " << i <<" : "<< v[i] << endl;
		
		}
		
	}
	vector.close();

}

float MediaAritmetica (const Vector v, int N)
{
	float m, suma;
	int i;
	suma = 0;
	
	for(i = 0; i < N; i++)
	{
		suma += v[i];
	}
	
	m = suma / N;
	
	return m;
}
void MaximoMinimo (const Vector v, int N, int& max, int& min)
{
	int i;
    
	max=v[0];
	for(i=0;i<N;i++)
	{
		if(v[i] > max)
			max = v[i];
	}
	
	min=v[0];
	for(i=0;i<N;i++)
	{
		if(v[i] < min)
			min = v[i];
	}
	
}
float DesviacionStandard(const Vector v, int N)
{
	int i;
	float sumatorio, m;
	
	m = MediaAritmetica (v, N);
	sumatorio = 0;
	
	for(i=0;i<N;i++)
	{
		sumatorio += ((pow(m-v[i],2))/N);
	}
	
	return sumatorio;
}