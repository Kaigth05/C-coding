/*******************************
    Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
    Fecha: 19-09-2023
    Objetivo: Donar la benvinguda
******************************/

//Bloc de llibreries externes
#include <iostream>
using namespace std;

/* Funció principal */

int main(void)
{
    int x, y;
        
        cout << "Donam valor de x" << endl;
        cin >> x;
        cout << "Donam valor de y" << endl;
        cin >> y;
        
        cout <<"*1 Valors introducits " << x << endl << y << endl;
        /* Se dan los dos valores en líneas distintas por un salto de línea */
        cout <<"*2 Valors introducits " << x << y << endl;
        /* Se dan los dos valores contiguos */
        cout <<"*3 Valors introducits " << x << " " << y << endl;
        /* Se dan los dos valores separados por espacio */
        cout <<"*4 Valors introducits " << x << "\t" << y << endl;
        /* Se dan los dos valores espaciados por una tabulación */
        
    return 0;
}
