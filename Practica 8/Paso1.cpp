#include <iostream>
#include <fstream>
using namespace std;

int main (void) 
{ 
 ifstream f;
 int i, dato;
 f.open ("datos.txt");
 
 if (!f)
    cout << "Error abriendo fichero";
 else
 { 
     for (i = 1; i <= 10; i++)
     { 
         f >> dato;
         cout << dato << endl;
     } 
     f.close ();
 } 
 system ("PAUSE");
 return 0;
}