/******************************
 Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
 Fecha de realización: 30-11-2023
 Objetivo: 
******************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <clocale> // para poder cambiar el idioma del teclado y consola
#include <windows.h>
using namespace std;

struct Complejo
{
    float real;
    float imag;
};

//Definimos un vector de N variables de tipo Complejo
const int N = 30;
typedef Complejo VectorComplejos[N];

Complejo introducirComplejo (void);
void mostrarComplejo (Complejo);
void introducirVectorComplejos (VectorComplejos, int&);
void mostrarVectorComplejos (const VectorComplejos, int);
Complejo calcularMediaVectorComplejos (const VectorComplejos, int);

int main (void)
{
    VectorComplejos numeros;
    int n;
    ofstream f;
    Complejo media;
    
    // Establecer el idioma a español
    setlocale(LC_ALL, "spanish"); // Cambiar local - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    
    // Introducimos los números complejos de los que calcularemos la media
	introducirVectorComplejos (numeros,n);
	
	// Mostramos los números complejos introducidos
    cout << "Números complejos introducidos: " << endl;
    mostrarVectorComplejos (numeros,n);
    
    // Calculamos la media
    media = calcularMediaVectorComplejos(numeros,n);
    
	// Mostramos la media
    cout << "La media de los complejos es "<<endl;
    mostrarComplejo(media);

    return 0;
}

/******************************
 Entrada: ninguna
 Salida: Complejo
 Objetivo: Función que pide al usuario un número complejo
 ******************************/
Complejo introducirComplejo(void)
{
    Complejo num;
    cout << "Parte real" << endl;
    cin >> num.real;
    cout << "Parte imaginaria" << endl;
    cin >> num.imag;
    
    return num;
}


/**********************************************************
 Entrada: Complejo
 Salida: Ninguna
 Objetivo: Función que muestra por pantalla un número de tipo Complejo
***********************************************************/
void mostrarComplejo (Complejo x)
{
    if (x.real == 0 && x.imag == 0)
       cout << 0;
    else
	{    
	   if (x.real==0)
	     cout << x.imag << "j";
	   else   
	   {
	      cout << x.real;
		  if (x.imag > 0 )
	         cout << "+" << x.imag << "j";
	      else
	         if (x.imag < 0)
		        cout << x.imag << "j";
		}
	     
    }

    return;
}


/**********************************************************
 Entrada: Ninguna
 Salida: VectorComplejos 
 Objetivo: Función que solicita al usuario que introduzca n números complejos
 y los almacena en un vector
 ***********************************************************/
void introducirVectorComplejos (VectorComplejos vect, int &n)
{
    int i;

    do
    {
        cout << "Cuántos números complejos quieres introducir: "<<endl;
        cin >> n;
    } while (n < 1 || n > N);

    for (i = 0; i < n; i++)
        vect[i] = introducirComplejo();
    return;
}


/**********************************************************
 Entrada: VectorComplejos (vector de números Complejos)
 Salida: ninguna
 Objetivo: Función que muestra por pantalla los números complejos guardados 
 en el vector suministrado como parámetro
***********************************************************/
void mostrarVectorComplejos (const VectorComplejos vec, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        mostrarComplejo (vec[i]);
        cout << endl;
    }
    return;
}

/******************************************************************
Entrada: Vector de complejos v
int n: cantidad de complejos que vamos a tener dentro de v
Salida: La media aritmética de las partes reales y las partes imaginarias de v 
expresada en un nuevo número complejo
Objetivo: Calcula la media aritmética de los números complejos suministrados
como parámetro
******************************************************************/
Complejo calcularMediaVectorComplejos (const VectorComplejos v, int n)
{
    Complejo resultado; // me declaro variable resultado del tipo de retorno especificado en la cabecera 
    int i;
	resultado.imag= 0.0;
    resultado.real= 0.0;
    
    for (i=0; i < n; i++)
    {
        resultado.real += v[i].real;
        resultado.imag += v[i].imag;
    }
    
	resultado.real = resultado.real / n;
    resultado.imag = resultado.imag / n;
    
    return resultado; // devuelve resultado
}