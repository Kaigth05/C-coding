/******************************
 Autores: 
 Fecha de realización: 
 Objetivo: 
******************************/

#include <iostream>
#include <clocale> // para poder cambiar el idioma del teclado y consola
#include <windows.h>
using namespace std;

struct Configuracion
{
    unsigned short filas;
    unsigned short columnas;
    unsigned short barcos;	
};

Configuracion generarConfiguracionPorDefecto();
Configuracion pedirConfiguracion();
void visualizarConfiguracion(Configuracion);

int main (void)
{
    Configuracion c;
    // Establecer el idioma a español
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    
    c = generarConfiguracionPorDefecto();
    cout << "Las opciones por defecto son: " << endl;
    visualizarConfiguracion(c);
    c = pedirConfiguracion();
    cout << "\nLas opciones introducidas por el usuario son: " << endl;
    visualizarConfiguracion(c);
    return 0;
    
}

Configuracion generarConfiguracionPorDefecto()
{
    Configuracion inic;
    
    inic.filas = 10;
    inic.columnas = 10;
    inic.barcos = 3;
    
    return inic;
}

Configuracion pedirConfiguracion()
{
    Configuracion pide;
    
    cout << "\nDame cuantas filas quieres: ";
    do
    {
        cin >> pide.filas;
        
        if (pide.filas < 5 || pide.filas > 20)
            cout << "Por favor, de una valor entre 5 y 20, ambos incluidos :D \n";
    }
    while (pide.filas < 5 || pide.filas > 20);
    
    cout << "Dame cuantas columnas quieres: ";
    do
    {
        cin >> pide.columnas;
        
        if (pide.columnas < 5 || pide.columnas > 20)
            cout << "Por favor, de una valor entre 5 y 20, ambos incluidos :D \n";
    }
    while (pide.columnas < 5 || pide.columnas > 20);
    
    cout << "Dame cuantos barcos quieres: ";
    cin >> pide.barcos;
    
    return pide;
    
}

void visualizarConfiguracion(Configuracion res)
{
    
    cout << "El numero de barcos con los que jugaras son: "; 
    cout << res.barcos << endl;
    cout << "Y el tamanyo del tablero es: " << res.filas;
    cout << "x" << res.columnas << endl;
    
    return;
}