#include <iostream>
using namespace std;
#include <cstdlib>
#include <cmath> 
float CalculaPrecioUnitario (float diam, float precio);
int main (void)
{ 
 float diam_a, diam_b, precio_a, precio_b, precio_a_uni, precio_b_uni;
 cout << "Dame el diametro (cm) y el precio de la pizza A (Euros)" << endl;
 cin >> diam_a >>precio_a; 
 cout << "Dame el diametro (cm) y el precio de la pizza B (Euros)" << endl;
 cin >> diam_b >>precio_b; 
 precio_a_uni = CalculaPrecioUnitario (diam_a, precio_a);
 precio_b_uni = CalculaPrecioUnitario (diam_b, precio_b);
 if (precio_a_uni < precio_b_uni)
 cout << "La pizza A es la mejor compra relacion precio/tamanyo" << endl;
 else
 cout << "La pizza B es la mejor compra relacion precio/tamanyo" << endl;
 system ("PAUSE");
 return 0;
} 
float CalculaPrecioUnitario (float diam, float precio) 
{ 
 float area, precio_uni;
 area = (diam / 2) * (diam / 2) * M_PI;
 precio_uni = precio / area;
 return precio_uni;
} 