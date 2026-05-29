#include <iostream>
using namespace std;
void IntroducirParametros (int , int);
int main (void)
{ 
 int a=0, b=0; 
 IntroducirParametros (a, b);
 
 cout << "Los parametros introducidos son " << a << " y " << b <<endl;
 return 0;
} 
void IntroducirParametros (int x, int y)
{ 
 cout << "Dame el valor del primer parametro: " << endl;
 cin >> x;
 cout << "Dame el valor del segundo parametro: " << endl;
 cin >> y;
 return;
} 