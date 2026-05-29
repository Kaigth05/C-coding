#include <iostream>
#include <fstream>
using namespace std;

int main (void) 
{ 
     ofstream f;
     char c;
     
     f.open ("caracteres.bin", ios::binary);
     
     if (!f)
        cout << "Error abriendo fichero";
     else
     { 
         for (c = 'a'; c <= 'z'; c++)
         f.write ( (char *)(&c), sizeof (c) ); 
         f.close ();
     } 
     
     system ("PAUSE");
     
     return 0;
} 