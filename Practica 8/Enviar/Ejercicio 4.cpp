/* Mateo Guijarro Pardo y Javier Diaz Sanz
			Fecha:03/11/2023 				*/
#include <iostream>
#include <fstream>
using namespace std;
int main (void)
{
	ifstream fichero;
	ofstream copia;
	char x;
	fichero.open("mifichero.txt");
	if(!fichero)
		cout<<"No se ha podido abrir el fichero"<<endl;
	else{
		copia.open("mifichero_copia.txt");
		if(!copia)
			cout<<"No se ha podido abrir el fichero"<<endl;
		else{
			while(fichero.get(x)){
				copia<<x;
			};
		}
		copia.close();	
	
	}
	fichero.close();
	return 0;
}