#include <iostream>
#include <cstdlib>
using namespace std;
int main (void)
{ 
 int i, x;
 
 for (i = 0; i < 5; i++)
 { 
 x = rand ();
 
 cout << "Valor aleatorio: " << x << endl;
 } 
 
 return 0;
} 