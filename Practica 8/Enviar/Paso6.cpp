/****************************************
    Autores: Jacier Díaz Sanz y Mateo Guijarro Pardo
    Fecha : 31-10-2023
****************************************/

#include <iostream>
using namespace std;
#include <fstream>

int main ( )
{
    ifstream f, g;
    ofstream f1, g1;
    
    int x;
    double a;
    
    f.open("secuencia_ints.dat", ios::binary);
    f1.open("secuencia_ints.txt");
    g.open("secuencia_doubles.dat", ios::binary);
    g1.open("secuencia_doubles.txt");
    
    if (!f || !g )
    {
        cout << "Alguno de los ficheros no se ha podido abrir" << endl;
    }
    
    else
    {
       while (f.read ( (char *)(&x), sizeof (x) ) )
        {
            f1 << x << endl;
        }
        while (g .read ( (char *)(&a), sizeof (a) ) )
        {
            g1 << a << endl;
        }
    }
    
    f.close ();
    f1.close ();
    g.close ();
    g1.close ();
    
}