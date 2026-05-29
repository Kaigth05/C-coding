#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main (void)
{ 
 int i, x;
 
 for (i = 0; i < 5; i++)
 { 
 srand (time (NULL) );
 x = rand ();
 
 cout << "Valor aleatorio: " << x << endl;
 } 
 
 return 0;
}