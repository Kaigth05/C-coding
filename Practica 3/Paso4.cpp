/* Mateo Guijarro Pardo y Javier Diaz Sanz
		Fecha: 03/10/2023			 */
#include <iostream>
using namespace std;
int main()
{ float valor;
cout<<"dame la nota de tu asignatura"<<endl;
cin>>valor;
 if(valor==10)
	cout<<"Matricula de honor";
else if(valor>=9&&valor<10)
	cout<<"Sobresaliente";
else if(valor>=7&&valor<10)
	cout<<"Notable";
else if(valor>=5&&valor<10)
	cout<<"Aprobado";
else if(valor>=0&&valor<10)
	cout<<"Suspenso";
else
	cout<<"No es una nota valida";
	
	return 0;
}