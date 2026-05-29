#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{ 
 int distancia; 
 float precio;
 char vuelta; // vuelta es de tipo carácter
 cout << "Ida y vuelta (s/n): ";
 cin >> vuelta; // Se espera que el usuario introduzca el carácter ‘s’ o ‘n’
 cout << "Introduce distancia a destino en km: ";
 cin >> distancia;
 precio = distancia * 0.12;
 if (distancia > 800)
 precio = 0.85 * precio;
 else
 if (distancia > 400)
 precio = 0.90 * precio;
 
 
 if (vuelta == 's' || vuelta == 'S') // Entrará en el if si el usuario introdujo una ‘s’ 
 precio = 1.5 * precio; // como respuesta a la primera pregunta (mayúscula o 
 // minúscula)
 
 cout << "El precio es de " << precio << " euros"<< endl;
 system ("pause");
 return 0;
} 
