#include <iostream>
using namespace std;

#include <cstdlib>
#include <cmath>

int main(void)
{ 
 float diam_a, diam_b, precio_a, precio_b, precio_a_uni, precio_b_uni;
 float area_a, area_b; 
 cout << "Dame el diametro (cm) y el precio de la pizza A (Euros): " << endl;
 cin >> diam_a >> precio_a; 
 
 cout << "Dame el diametro (cm) y el precio de la pizza B (Euros): " << endl;
 cin >> diam_b >> precio_b; 
 area_a = (diam_a / 2) * (diam_a / 2) * M_PI;
 precio_a_uni = precio_a / area_a; 
 area_b = (diam_b / 2) * (diam_b / 2) * M_PI;
 precio_b_uni = precio_b / area_b; 
 
 if (precio_a_uni < precio_b_uni)
 cout << "La pizza A es la mejor compra relacion precio/tamanyo" << endl;
 else
 cout << "La pizza B es la mejor compra relacion precio/tamanyo" << endl;
 
 system ("PAUSE");
 return 0;
}