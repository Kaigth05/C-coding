/*********************************************************/
/* Autor : Javier Díaz Sanz y Mateo Guijarro Pardo*/
/* Fecha: 02/10/2023 */
/* Proposito : Edad necesaria para participar */
/*********************************************************/

#include <iostream>
using namespace std;
int main()
{ 
     int edad;
     
     cout << "Introduzca la edad del participante" << endl;
        cin >> edad; 
     if ( (edad < 18) || (edad > 65) )
        cout << "Este participante no puede concursar" << endl;
     else
        cout << "Este participante puede concursar" << endl;
        
     return 0;
} 