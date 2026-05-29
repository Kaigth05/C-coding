#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{ 
 int mes;
 cout << "Introduce un mes como numero: ";
 cin >> mes;
 switch (mes)
 { 
 case 1:
 cout << "Enero" << endl;

 case 2:
 cout << "Febrero" << endl;

 case 3:
 cout << "Marzo" << endl; 

 case 4:
 cout << "Abril" << endl; 

 case 5:
 cout << "Mayo" << endl; 
 
 case 6:
 cout << "Junio" << endl; 

 case 7:
 cout << "Julio" << endl; 

 case 8:
 cout << "Agosto" << endl; 

 case 9:
 cout << "Septiembre" << endl; 

 case 10:
 cout << "Octubre" << endl; 
 
 case 11:
 cout << "Noviembre" << endl; 

 case 12:
 cout << "Diciembre" << endl; 

 default:
 cout << "Mes incorrecto" << endl;
 } 
 system("pause");
 return 0;
} 