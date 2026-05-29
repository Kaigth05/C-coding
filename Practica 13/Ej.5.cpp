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
int leerNp();
void guardarNp (int);

int main ()
{
	Partidas parts;
	Partida part;
	
    parts.n = leerNp();
    part.usada.filas = 5;
    part.usada.columnas = 5;
    part.usada.barcos = 10;
	part.boom = 12;
    part.victoria = false;
	
	if (anyadirPartida (parts,part))
    {
        guardarPartidasEnFichero (parts);
        parts.n ++;
        guardarNp (parts.n); 
    	parts = leerPartidasDeFichero();
        visualizarPartidas(parts);
    }
	else
            cout << "No se pueden guardar mas";
            
    return 0;
}

int leerNp ()
{
    ifstream f;
    int np;
    
    f.open("np.txt");
    if (!f)
        cout << "No se pudo abrir np.txt" << endl;
    else
    {
        f >> np;
        f.close();
    }
    
    return np;   
}

bool anyadirPartida(Partidas& parts, Partida part)
{
	bool max;
    
	if(parts.n < MAX_PARTIDAS)
    {               
		max = true;
        parts.historial[parts.n].usada.filas = part.usada.filas;
        parts.historial[parts.n].usada.columnas = part.usada.columnas;
        parts.historial[parts.n].usada.barcos = part.usada.barcos;
        parts.historial[parts.n].victoria = part.victoria;
        parts.historial[parts.n].boom = part.boom;
    }
	else
		max = false;
	
	return max;
}

void guardarPartidasEnFichero(Partidas parts)
{
	partida_escribir.open("info_partidas.txt", ios::app);
	if (!partida_escribir)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
        partida_escribir << parts.n << endl;
		partida_escribir << parts.historial[parts.n].usada.filas << " " << parts.historial[parts.n].usada.columnas;
        partida_escribir << " " << parts.historial[parts.n].usada.barcos << " ";
        partida_escribir << parts.historial[parts.n].boom << " ";
        
        if (parts.historial[parts.n].victoria)
            partida_escribir << 1 << " " << endl;
        else 
            partida_escribir << 0 << " " << endl;
	}
}

Partidas leerPartidasDeFichero()
{
	Partidas parts;
	int i;
	
    parts.n = leerNp ();
    
	partida_leer.open("info_partidas.txt", ios::app);
	if (!partida_leer)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		
		while(partida_leer >> i )
		{
			partida_leer >> parts.historial[i].usada.filas >> parts.historial[i].usada.columnas;
            partida_leer >> parts.historial[i].usada.barcos >> parts.historial[i].boom;
            partida_leer >> parts.historial[i].victoria;
            
            if (parts.historial[i].victoria == 1)
                parts.historial[i].victoria = true;
            else
                parts.historial[i].victoria = false;
		}
	}
	
	return parts;
}

void visualizarPartidas(Partidas parts)
{
	int i;
	
	for(i = 0; i < parts.n; i++)
	{
		cout<< "La configuracion de la partida " << i << " fue: "; 
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

void guardarNp (int n)
{
    ofstream f;
    
    f.open("np.txt");
    if (!f)
        cout << "No se pudo abrir np.txt" << endl;
    else
    {
        f << n;
    }
    
    f.close();
    
    return;
}