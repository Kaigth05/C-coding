/******************************
 Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
 Fecha de realización: 30-11-2023
 Objetivo: 
******************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using namespace std;

ofstream partida_escribir;
ifstream partida_leer;

struct Disparo
{
	int x;
	int y;
	int distancia;

};

const int MAX_DISPARO = 200;
typedef Disparo Vector[MAX_DISPARO];

struct Disparos
{
	Vector disparo;
	int n = 0;
};

bool anyadirDisparo(Disparos&,Disparo);
void visualizarDisparos(Disparos);
void guardarDisparosEnFichero(Disparos);
Disparos leerDisparosDeFichero();

int main ()
{
	Disparos D;
	Disparo d;
	
	d.x=1;
	d.y=3;
	d.distancia=4;
	
	anyadirDisparo (D,d);
	visualizarDisparos (D);
	guardarDisparosEnFichero (D);
	D=leerDisparosDeFichero();
	visualizarDisparos (D);
	
	return 0;
}

bool anyadirDisparo(Disparos& D, Disparo d)
{
	bool max;

	D.disparo[D.n].x = d.x;
	D.disparo[D.n].y = d.y;
	D.disparo[D.n].distancia = d.distancia;
	D.n ++;
	
	if(D.n <= MAX_DISPARO)
		max = true;
	else
		max = false;
	
	return(max);
}

void visualizarDisparos(Disparos D)
{
	int i;
	
	for(i=0; i<D.n; i++)
	{
		cout<< "Tiene Coordenada x: " << D.disparo[i].x << ", coordenada y: " << D.disparo[i].y << ", y una distancia: " << D.disparo[i].distancia << endl;
	}
	
	return;
}

void guardarDisparosEnFichero(Disparos D)
{
	int i;
	
	partida_escribir.open("ultima_partida.txt");
	if (!partida_escribir)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_escribir << D.n << endl;
		
		for(i=0; i<D.n; i++)
		{
			partida_escribir << D.disparo[i].x << " " << D.disparo[i].y << " " << D.disparo[i].distancia << endl;
		}
	}
}

Disparos leerDisparosDeFichero()
{
	Disparos D;
	int i;
	
	partida_leer.open("ultima_partida.txt");
	if (!partida_leer)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_leer >> D.n;

		
		for(i=0; i<D.n; i++)
		{
			partida_leer >> D.disparo[i].x >> D.disparo[i].y >> D.disparo[i].distancia ;
		}
	}
	
	return (D);
}