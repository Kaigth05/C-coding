#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (void)
{
    long telefono;
    string nombre;
    ifstream f;

    f.open ("guia.txt");
    if ( !f )
        cout << "Error abriendo el fichero" << endl;
    else
    {
        while ( getline (f, nombre) )
        {
            f >> telefono;
            cout << nombre << endl << telefono << endl;
        }
        f.close ();
    }
    return 0;
}

