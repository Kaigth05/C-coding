/****************************************
    Autores: Jacier Díaz Sanz y Mateo Guijarro Pardo
    Fecha : 31-10-2023
****************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main (void)
{ 
     ifstream f1;
     ofstream f2;
     char x;
     
     f1.open("mitexto.txt"); 
     f2.open("binario.bin", ios::binary); 
     
     if (!f1)
     cout << "El fichero mitexto.txt no se ha podido abrir";
     
     else
     {
         while (f1.get (x))
         f2.write ( (char *)(&x), sizeof (x) ) ;
     } 
     
     f1.close();
     f2.close();
     
     system ("PAUSE");
     return 0;
} 