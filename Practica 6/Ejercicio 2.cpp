#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
int main ()
{
float x, y;
char operacion;
cout << "dame los valores a y b:"<<endl;
cin>> x;
cin>> y;
cout<< "dime el tipo de operacion que quiere que realice, a, b, c, d, e, f: ";
cin >> operacion;
switch (operacion){
	case 'a':  cout << "el resultado es: "<< sqrt(labs(x+y))<<endl;
		break;
	case 'b':  cout << "el resultado es: "<< floor(x/y)<<endl;
		break;
	case 'c':  cout << "el resultado es: "<< exp(y)<<endl;
		break;
	case 'd':  cout << "el resultado es: "<< tan(x)<<endl;
		break;
	case 'e':  cout << "el resultado es: "<< atan(x)<<endl;
		break;
	case 'f':  cout << "el resultado es: "<< log(y)<<endl;
		break;
	}
return 0;
}