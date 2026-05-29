#include <iostream>
using namespace std;
#include <string>
#include <clocale>
#include <windows.h>
int main (void)
{
	int i;
	string archivo,nombre,extension;
	
	cout<<"Dame el nombre de tu archivo: ";
	getline(cin,archivo);	
	
	i = archivo.find(".");
	nombre = archivo.substr(0,i);
	extension = archivo.substr(i,archivo.length() - i);
	
	cout<<"nombre: "<<nombre<<endl;
	cout<<"extension: "<<extension<<endl;
	
	return 0;
	


}