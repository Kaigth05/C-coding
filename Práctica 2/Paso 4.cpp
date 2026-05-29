/* Mateo Guijarro Pardo y Javier Diaz Sanz
		Fecha: 26/09/2023			 */
#include <iostream>
using namespace std;
int main()
{
 float cantidad;
 float iva;


	cout << "dame la cantidad de dinero deseada" << endl;
 	cin >> cantidad;									 // Incluye aquí las líneas que piden al usuario la cantidad y el iva
 		cout << "dame el porcentaje de Iva deseado" << endl;
 	cin >> iva;
 	cout << "El dinero tras aplicarle el Iva->" << " "<< cantidad+(cantidad*(iva/100.0))<< endl ;
																							// Escribe aquí la línea que realiza los cálculos
																							 // Escribe aquí la línea que muestra el resultado al usuario
 return 0;
}