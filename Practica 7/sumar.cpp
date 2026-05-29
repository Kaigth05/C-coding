#include <iostream>
using namespace std;

float sumar (float&a, float&b);

int main ()
{
    float a, b, c;
    a = 3.5;
    b = 2.7;
    c = sumar (a, b);
    
    cout << a << " y " << b << " = " << c << endl;
    return 0;
}

float sumar (float&a, float&b)
{
    float resultado;
    a = a + b;
    resultado = a;
    return resultado;
}