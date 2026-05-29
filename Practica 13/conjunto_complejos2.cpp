/******************************
 Autores: Javier Díaz Sanz y Mateo Guijarro Pardo
 Fecha de realización: 30-11-2023
 Objetivo: 
******************************/

#include <iostream>
#include <string>
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

struct ConjuntoComplejos 
{
	int n_elementos;
	VectorComplejos valores;
};

Complejo introducirComplejo (void);
void mostrarComplejo (Complejo);
void mostrarVectorComplejos (ConjuntoComplejos);
ConjuntoComplejos introducirVectorComplejos ();
bool escribeEstructuraAFichero (string, ConjuntoComplejos);
bool leerFicheroDeComplejos (string, ConjuntoComplejos&);
Complejo calcularMediaVectorComplejos (ConjuntoComplejos);

int main (void)
{
    ConjuntoComplejos numeros;
    int n;
    string datafile, datatxt;
    Complejo media;
    
    // Establecer el idioma a español
    setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    
    // Introducimos los números complejos de los que calcularemos la media
	numeros = introducirVectorComplejos();
	
	// Mostramos los números complejos introducidos
    cout << "Números complejos introducidos: " << endl;
    mostrarVectorComplejos (numeros);
        
    // Calculamos la media
    media = calcularMediaVectorComplejos(numeros);
    
	// Mostramos la media
    cout << "La media de los complejos es "<<endl;
    mostrarComplejo(media);
    
    cout << "\nEscriba el nombre del fichero en el que quiere guardar sus datos" << endl;
    cin >> datafile;
    
    datatxt = datafile + ".txt";

    if (escribeEstructuraAFichero (datatxt, numeros))
    {
        cout << "Hemos podido introducir los vectores en: ";
        cout << datatxt << endl;
        if (leerFicheroDeComplejos (datatxt, numeros))
        {
            cout << "Hemos introducido mas vectores en: ";
            cout << datatxt << endl; 
        }
        else
            cout << "No se pudo abrir el fichero" << endl;
    }
    
    else
        cout << "No se ha podido abrir el fichero" << endl;
        
    return 0;
}




/******************************
 Entrada: ninguna
 Salida: Complejo
 Objectivo: Función que pide al usuario un número complejo
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



bool escribeEstructuraAFichero (string datatxt, ConjuntoComplejos numeros)
{
    ofstream f;
    bool apertura;
    int i;
    
    f.open (datatxt, ios::app);
    
    if (!f)
        apertura = false;
    
    else
    {
        apertura = true;
        for (i = 0; i < numeros.n_elementos; i++)
        {
            if (numeros.valores[i].real == 0 && numeros.valores[i].imag == 0)
                f << 0 << endl;
            else
	       {    
    	       if (numeros.valores[i].real == 0)
    	           f << numeros.valores[i].imag << "j" << endl;
                   
    	       else   
    	       {
    	            f << numeros.valores[i].real;
        		    if (numeros.valores[i].imag > 0 )
        	           f << "+" << numeros.valores[i].imag << "j" << endl;
        	        else
    	               if (numeros.valores[i].imag < 0)
    		              f << numeros.valores[i].imag << "j" << endl;
    		    }
	     
            } 
        }
    }
    
    f.close();
    
    return apertura;
}



bool leerFicheroDeComplejos (string datatxt, ConjuntoComplejos & numeros)
{
    ifstream f;
    bool apertura;
    int i;
    char acepta;
    
    f.open (datatxt, ios::app);
    
    if (!f)
        apertura = false;
    
    else
    {
        do
        {
            cout << "¿Quieres meter mas datos? Escribe s para continuar" << endl;
            cin >> acepta;
            if (acepta == 's')
            {
                ConjuntoComplejos aux = introducirVectorComplejos ();
                escribeEstructuraAFichero (datatxt, aux);
            }
        }
        while (acepta == 's');
    }
    
    f.close ();
    
    return apertura;
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
	   if (x.real == 0)
	     cout << x.imag << "j" << endl;
	   else   
	   {
	      cout << x.real;
		  if (x.imag > 0 )
	         cout << "+" << x.imag << "j" ;
	      else
	         if (x.imag < 0)
		        cout << x.imag << "j";
		}
	     
    }

    return;
}

/**********************************************************
 Entrada: ninguna
 Salida: ConjuntoComplejos cjto
 Objetivo: Introducir todos los vectores que queramos en el ConjuntoComplejos cjto
 y asignarles un valor a su parte real e imaginaria.
 ***********************************************************/
ConjuntoComplejos introducirVectorComplejos ()
{
    int i;
    ConjuntoComplejos cjto;
    do
    {
        cout << "Cuántos números complejos quieres introducir: "<<endl;
        cin >> cjto.n_elementos;
    } 
    while (cjto.n_elementos < 1 || cjto.n_elementos > N);

    for (i = 0; i < cjto.n_elementos; i++)
        cjto.valores[i] = introducirComplejo();
        
    return cjto;
}




/**********************************************************
 Entrada: Conjunto de vectores de complejos denominado "ConjuntoComplejos numeros"
 Salida: ninguna
 Objetivo: sacar por pantalla cada uno de los vecotres contenidos en ConjuntoComplejos numeros
***********************************************************/
void mostrarVectorComplejos (ConjuntoComplejos numeros)
{
    int i;

    for (i = 0; i < numeros.n_elementos; i++)
    {
        mostrarComplejo (numeros.valores[i]);
        cout << endl;
    }
    return;
}

/******************************************************************
Entrada: Conjunto de vectores de complejos denominado "ConjuntoComplejos numeros"
int n: cantidad de complejos que vamos a declarar en introducirVectorComplejos
dentro de un ConjuntoComplejos y denominado "n_elementos"
Salida: La media aritmética de las partes reales y las partes imaginarias de v 
expresada en un nuevo número complejo
Objetivo: Calcula la media aritmética de los números complejos suministrados
como parámetro
******************************************************************/
Complejo calcularMediaVectorComplejos (ConjuntoComplejos numeros)
{
    Complejo resultado; // me declaro variable resultado del tipo de retorno especificado en la cabecera 
    int i;
	resultado.imag = 0.0;
    resultado.real = 0.0;
    
    for (i = 0; i < numeros.n_elementos; i++)
    {
        resultado.real += numeros.valores[i].real;
        resultado.imag += numeros.valores[i].imag;
    }
    
	resultado.real = resultado.real / numeros.n_elementos;
    resultado.imag = resultado.imag / numeros.n_elementos;
    
    return resultado; // devuelve resultado
}
