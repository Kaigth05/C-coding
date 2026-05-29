#include <iostream>
using namespace std;
#include <clocale>
#include <windows.h>

struct Complejo
{
    float real;
    float imag;
};

void IntroducirComplejo (Complejo &);
void MostrarComplejo (Complejo);
Complejo SumarComplejos (Complejo, Complejo);
Complejo RestarComplejos (Complejo, Complejo);
Complejo Conjugado (Complejo);

int main (void)
{
    Complejo c1, c2, csum, cres, ccon1, ccon2;
    // Establecer el idioma a español para admitir acentos
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    cout << "Introduzca primer complejo: "<< endl;
    IntroducirComplejo (c1);
    cout << "Introduzca segundo complejo: "<< endl;
    IntroducirComplejo (c2);
    csum = SumarComplejos (c1, c2);
    cres = RestarComplejos (c1, c2);
    ccon1 = Conjugado (c1);
    ccon2 = Conjugado (c2);
    
    cout << "La suma de los dos numeros es " ;
    MostrarComplejo (csum);
    cout << endl;
    
    cout << "La resta de los dos numeros es " ;
    MostrarComplejo (cres);
    cout << endl;
    
    cout << "El conjugado del primero es " ;
    MostrarComplejo (ccon1);
    cout << endl;
    
    cout << "El conjugado del segundo es " ;
    MostrarComplejo (ccon2);
    cout << endl;
    
    return 0;
}

/*********************
Complejo IntroducirComplejo (void).

¿QUÉ HACE? Lo que hacemos es introducir la parte entera e imaginaria
que acompaña a la "i" en la expresión matemática de los números complejos.
ENTRADA: ninguna, estamos rellenando el Complejo resultado.
SALIDA: el Complejo resultado con su parte real e imaginaria ya definidas.
**********************/

void IntroducirComplejo (Complejo & resultado)
{
    cout << "Parte real: ";
    cin >> resultado.real;
    cout << "Parte imaginaria: ";
    cin >> resultado.imag;
    
    return;
}

/*********************
void MostrarComplejo (Complejo x).

¿QUÉ HACE? Lo que hacemos es mostrar la expresión matemática de los 
números complejos con la parte entera y la imaginaria que acompaña a la "i".
ENTRADA: el Complejo x.
SALIDA: ninguna, estamos mostrando x.
**********************/

void MostrarComplejo (Complejo x)
{
    if (x.real==0 && x.imag==0)
       cout << 0;
    else
	{    
	   if (x.real==0)
	     cout << x.imag << "j";
	   else   
	   {
	      cout << x.real;
		  if (x.imag>0 )
	         cout << "+" << x.imag << "j";
	      else
	         if (x.imag<0)
		        cout << x.imag << "j";
		}
	     
    }

    return;
}

/*********************
void SumarComplejos(Complejo a, Complejo b, Complejo & res)

¿QUÉ HACE? Lo que hacemos es introducir la parte entera e imaginaria que 
acompaña a la "i" en la expresión matemática de los números complejos.
ENTRADA: c1, cs (que son los números a sumar) y cres que lo pasamos por 
referencia por ser el resultado de la suma
SALIDA: ninguna, porque pasamos por referencia el resultado de la operación.
**********************/

Complejo SumarComplejos(Complejo a, Complejo b)
{
    Complejo res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;

    return res;
}

Complejo RestarComplejos(Complejo a, Complejo b)
{
    Complejo res;
    res.real = a.real - b.real;
    res.imag = a.imag - b.imag;

    return res;
}

Complejo Conjugado(Complejo a)
{
    Complejo res;
    res.real = a.real;
    res.imag = -a.imag;

    return res;
}
