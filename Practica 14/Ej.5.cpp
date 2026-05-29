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

struct Configuracion
{
    unsigned short filas;
    unsigned short columnas;
    unsigned short barcos;	
};

struct Partida
{
	Configuracion usada;
	bool victoria;
    int boom ;
};

const int MAX_PARTIDAS = 1000;
typedef Partida Vector[MAX_PARTIDAS];

struct Partidas
{
    Vector historial;
    int n;
};

bool anyadirPartida(Partidas&,Partida);
void visualizarPartidas(Partidas);
void guardarPartidasEnFichero(Partidas);
Partidas leerPartidasDeFichero();

int main ()
{
	Partidas parts;
	Partida part;
	
    parts.n = 0;
    part.usada.filas = 5;
    part.usada.columnas = 5;
    part.usada.barcos = 10;
	part.boom = 12;
    part.victoria = false;
	
	anyadirPartida (parts,part);
	visualizarPartidas (parts);
	guardarPartidasEnFichero (parts);
	parts = leerPartidasDeFichero();
	visualizarPartidas (parts);
            
}

bool anyadirPartida(Partidas& parts, Partida part)
{
	bool max;
    
    parts.historial[parts.n].usada.filas = part.usada.filas;
    parts.historial[parts.n].usada.columnas = part.usada.columnas;
    parts.historial[parts.n].usada.barcos = part.usada.barcos;
    parts.historial[parts.n].victoria = part.victoria;
    parts.historial[parts.n].boom = part.boom;
    parts.n ++;
    
	if(parts.n <= MAX_PARTIDAS)                  
		max = true;
	else
		max = false;
	
	return(max);
}

void visualizarPartidas(Partidas parts)
{
	int i;
	
	for(i = 0; i < parts.n; i++)
	{
		cout<< "La configuracion de la partida " << parts.n << " fue: "; 
        cout << parts.historial[i].usada.filas << " x " << parts.historial[i].usada.columnas;
        cout << ", y un total de barcos de: " << parts.historial[i].usada.barcos << endl;
        
        if (parts.historial[i].victoria)
            cout << "El usuario gano la partida" << endl;
        else
            cout << "El usuario perdio la partida" << endl;
            
        cout << "El usuario disparo: " << parts.historial[i].boom << " veces \n";
	}
	
	return;
}

void guardarPartidasEnFichero(Partidas parts)
{
	int i;
	
	partida_escribir.open("info_partidas.txt", ios::app);
	if (!partida_escribir)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_escribir << parts.n << endl;
		
		for(i = 0; i < parts.n; i++)
		{
			partida_escribir << parts.historial[i].usada.filas << " " << parts.historial[i].usada.columnas;
            partida_escribir << " " << parts.historial[i].usada.barcos << " ";
            partida_escribir << parts.historial[i].boom << " ";
            
            if (parts.historial[i].victoria)
                partida_escribir << 1 << " " << endl;
            else 
                partida_escribir << 0 << " " << endl;
            
		}
	}
}

Partidas leerPartidasDeFichero()
{
	Partidas parts;
	int i;
	
	partida_leer.open("info_partidas.txt", ios::app);
	if (!partida_leer)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_leer >> parts.n;

		
		for(i = 0; i < parts.n; i++)
		{
			partida_leer >> parts.historial[i].usada.filas >> parts.historial[i].usada.columnas;
            partida_leer >> parts.historial[i].usada.columnas >> parts.historial[i].boom;
            partida_leer >> parts.historial[i].victoria;
		}
	}
	
	return parts;
}