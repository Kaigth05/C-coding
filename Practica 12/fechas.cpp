#include <iostream>
using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anyo;
};

Fecha IntroducirFecha (void);
void MostrarFecha (Fecha);
bool EsAnterior (Fecha, Fecha);

int main (void)
{
    Fecha f1, f2;

    f1 = IntroducirFecha ();
    f2 = IntroducirFecha ();
    if (EsAnterior (f1, f2) )
    {
        cout << "Fecha ";
        MostrarFecha (f1);
        cout << " es anterior a ";
        MostrarFecha (f2);
    }
    else
    {
        cout<< "Fecha ";
        MostrarFecha (f2);
        cout << " es anterior a ";
        MostrarFecha (f1);
    }

    return 0;
}
// Entrada: Ninguna		Salida: una variable tipo struct
Fecha IntroducirFecha (void)
{
	Fecha f;
	
	cout<< "Dame el dia: ";
	cin>> f.dia;
	cout<< "Dame el mes: ";
	cin>> f.mes;
	cout<< "Dame el anyo: ";
	cin>> f.anyo;
	cout<< endl;
	
	return f;
}
// Entrada: una variable tipo struct		Salida: Nada
void MostrarFecha (Fecha f)
{
	cout<< f.dia << "/" << f.mes << "/" << f.anyo;
	
	return;
}
// Entrada: dos variable tipo struct		Salida: un bool que posteriormente indicara cual de las dos es menor
bool EsAnterior (Fecha f1, Fecha f2)
{
	bool ok;
	int f1completo, f2completo;
	
	f1completo = f1.anyo*10000+f1.mes*100+f1.dia;
	f2completo = f2.anyo*10000+f2.mes*100+f2.dia;
	
	if (f1completo < f2completo)
		ok=true;
	else
		ok=false;
	
	return ok;
}