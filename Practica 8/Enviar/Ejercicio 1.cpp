/* Mateo Guijarro Pardo y Javier Diaz Sanz
			Fecha:03/11/2023 				*/
#include <iostream>
#include <fstream>
using namespace std;
int main (void)
{
	ofstream billete;
	int a,b,c,d,e,f,g;
	cout<<"Introduzca numero de autobus: ";
	cin>>a;
	cout<<"Introduzca dia: ";
	cin>>b;
	cout<<"Introduzca mes: ";
	cin>>c;
	cout<<"Introduzca anyo: ";
	cin>>d;
	cout<<"horario salida (hora): ";
	cin>>e;
	cout<<"horario salida (minutos): ";
	cin>>f;
	cout<<"distancia en km: ";
	cin>>g;
	
	billete.open("billete.txt");
	if(!billete)
		cout<<"No se ha podido abrir el fichero"<<endl;
	else{
		billete<<"billete autobus lineas "<<a<<endl;
		billete<<"Salida; Valencia, "<<b<<"/"<<c<<"/"<<d<< " "<<e<<":"<<f<<endl;
		billete<<"Precio: "<<g/10<< " euros y "<<g%10<< " centimos";
	}
	billete.close();

}