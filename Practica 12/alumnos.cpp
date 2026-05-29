#include <iostream>
#include <stdlib.h>
using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anyo;
};

struct Persona
{
    string nombre;
    Fecha fecha_nacimiento;
    char sexo;
};

struct Alumno
{
    Persona datos;
    int curso;
};

Fecha IntroducirFecha (void);
void MostrarFecha (Fecha);
bool EsAnterior (Fecha, Fecha);
Persona LeerPersona (void);
void MostrarPersona (Persona);
void LeerAlumno (Alumno &);
void MostrarAlumno (Alumno);
Alumno AlumnoMayor (Alumno, Alumno);

int main (void)
{
	Alumno a1, a2, alu_mayor;

    LeerAlumno (a1);
    LeerAlumno (a2);
    alu_mayor = AlumnoMayor (a1, a2);
    cout<< "El alumno mayor-> ";
    MostrarAlumno (alu_mayor);

    system("pause");
    return 0;
}

Fecha IntroducirFecha (void)
{
	Fecha f;
	
	cout<< "Dame el dia de nacimiento: ";
	cin>> f.dia;
	cout<< "Dame el mes: ";
	cin>> f.mes;
	cout<< "Dame el anyo: ";
	cin>> f.anyo;
	cout<< endl;
	
	return f;
}

void MostrarFecha (Fecha f)
{
	cout<< f.dia << "/" << f.mes << "/" << f.anyo;
	
	return;
}

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

Persona LeerPersona (void)
{
	Persona p;
	
	cout<< "Deme su nombre: ";
	cin>> p.nombre;
	cout<< "Deme su sexo (Hombre-> H / Mujer-> M / Otro-> 0): ";
	cin>> p.sexo;
	p.fecha_nacimiento = IntroducirFecha();
	
	return p;
}

void MostrarPersona (Persona p)
{
	cout<< "su nombre es: "<< p.nombre << ", su sexo: " << p.sexo << ", su fecha nacimiento: ";
	MostrarFecha(p.fecha_nacimiento);

	return;
}

void LeerAlumno (Alumno & a)
{
	cout << "Deme en que curso esta: ";
	cin >> a.curso;
	a.datos = LeerPersona();
		
	return;
}

void MostrarAlumno (Alumno a)
{
	MostrarPersona(a.datos);
	cout<<" y esta en el curso: "<< a.curso<<endl;
	
	return;
}

Alumno AlumnoMayor (Alumno alu1, Alumno alu2)
{
    Alumno mayor;

    if (EsAnterior(alu1.datos.fecha_nacimiento, alu2.datos.fecha_nacimiento) )
        mayor = alu1;
    else
        mayor = alu2;

    return mayor;
}

