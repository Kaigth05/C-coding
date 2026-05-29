/****************************************
    Autores: Jacier Díaz Sanz y Mateo Guijarro Pardo
    Fecha : 31-10-2023
****************************************/

#include <iostream>
#include <fstream>
using namespace std;

void MostrarMatriz (ifstream& f);

int main (void)
{ 
     ifstream f1,f2;
     
     f1.open("matriz1.dat"); 
     f2.open("matriz2.dat"); 
     
     if (!f1)
     cout << "El fichero matriz1.dat no se ha podido abrir";
     
     if (!f2)
     cout << "El fichero matriz2.dat no se ha podido abrir";
     
     if (f1 && f2)
     { 
     cout << "La primera matriz en matriz1.dat es "<<endl;
     MostrarMatriz (f1);
     cout << "La segunda matriz en matriz2.dat es "<<endl;
     MostrarMatriz (f2);
     } 
     
     f1.close();
     f2.close();
     
     system ("PAUSE");
     return 0;
} 
 
void MostrarMatriz (ifstream& f) 
{ 
     int i, j;
     int x, y, matriz;
     
     f >> x;
     f >> y;
     i = 0;

     while (i < x)
     {
         for (j = 0; j < y; j++)
         {
                f >> matriz;
                cout << matriz << " ";
         }
         cout << endl;
         i++;
     }
} 