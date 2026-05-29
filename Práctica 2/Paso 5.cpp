/* Mateo Guijarro Pardo y Javier Diaz Sanz
		Fecha: 26/09/2023			 */
#include <iostream>
using namespace std;
int main()
{
 float cantidad;
 int iva;
 float precio_final;

	cout << "dame el precio final" << endl;
 	cin >> precio_final;									
 	cout << "dame el porcentaje de Iva aplicado" << endl;
 	cin >> iva;
 	cout << "La cantidad de dinero antes de aplicarle el iva->" << " "<< (precio_final/(100.0+iva))*100<< endl ;
																							
 return 0;
}