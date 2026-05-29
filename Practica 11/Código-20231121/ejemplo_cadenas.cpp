#include <iostream>
using namespace std;
#include <string>
#include <clocale>
#include <windows.h>

int main (void)
{
    string nombre, apellido1, apellido2;
    string nombre_t, cad;
    size_t pos;
    
	// Establecer el idioma a español para admitir acentos
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    
    cout << "Dame el nombre" << endl;
    getline (cin, nombre);
    cout << "Dame el primer apellido" << endl;
    getline(cin, apellido1);
    cout << "Dame el segundo apellido" << endl;
    getline(cin, apellido2);
    nombre_t = nombre + " " + apellido1 + " " + apellido2;
    cout << nombre_t << endl;
        
    cad = " ";
    pos = nombre_t.find (cad);
    do 
    {
        cout << pos << endl;
        pos = nombre_t.find (cad, pos + 1);
    }
    while (pos != string::npos);
    
    system("pause");
    return 0;
}

