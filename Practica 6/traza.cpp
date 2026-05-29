#include <iostream>
using namespace std;
#include <cstdlib>

int z = 3; //int z variable global
void F (int x); //int x parámetro formal

int main(void)
{
    int y, x; //int x,y variables locales
    x = 5;
    y = 10;
    cout << z; 
    F (x); 
    cout << z << endl << x << endl << y << endl;
    system ("PAUSE");
    return 0;
}

void F (int x)
{
    int y; //int y variable local
    y = 3;
    z = 6;  //asignación a variable global int z
    cout << y << endl;
    cout << x <<endl;
    return;
}