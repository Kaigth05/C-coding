/*
    Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
    Fecha: 26/09/2023
*/

#include <iostream>
    using namespace std;


int main (void)
{
    int km;
    float consum, plitro;
    
        cout << "Introduzca la cantidad de km del viaje: ";
            cin >> km;
        cout << "Introduzca el consumo/100 km del coche: ";
            cin >> consum;
        cout << "Introduzca a cuanto esta el litro de gasoil: ";
            cin >> plitro;
            
        cout << "Ha gastado en el viaje un total de: " << km/100.0*consum*plitro << " euros" << endl;
        
    return 0;
            
}