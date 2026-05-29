#include <iostream>
using namespace std;
#include <cstdlib>

bool IntroducirCantidad (int & dinero); // devuelve true si la cantidad es divisible por 10
void NumBilletes (int dinero, int & b500, int & b200, int & b100, int & b50, int & b20, int & b10);
void MostrarBilletes(int b500, int b200, int b100, int b50, int b20, int b10);

int main(void)
{ 
 int dinero, b500, b200, b100, b50, b20, b10;
 dinero = 0;
 
 if (IntroducirCantidad(dinero))
 { 
     NumBilletes(dinero,b500, b200, b100, b50, b20, b10);
     cout << b500 << endl;
     MostrarBilletes(b500, b200, b100, b50, b20, b10);
 } 
 else
    cout << "No te puedo dar esa cantidad"<<endl;
 
 return 0;
} 

bool IntroducirCantidad (int & dinero) 
{
    bool res;
    cout << "Dame tu dinero: " << endl;
    cin >> dinero;
    
    if (dinero % 10 == 0)
    {
        res = true;
    }
    
    else
        res = false;
    
    return res;
}

void NumBilletes (int dinero, int & b500, int & b200, int & b100, int & b50, int & b20, int & b10)
{
    cout << dinero << endl;
    
        b500 = dinero / 500;
        dinero = dinero % 500;

        b200 = dinero / 200;
        dinero = dinero % 200;

        b100 = dinero / 100;
        dinero = dinero % 100;

        b50 = dinero / 50;
        dinero = dinero % 50;

        b20 = dinero / 20;
        dinero = dinero % 20;

        b10 = dinero / 10;
        dinero = dinero % 10;

    return;
}

void MostrarBilletes(int b500, int b200, int b100, int b50, int b20, int b10)
{
    
    cout << b500 << " billetes de 500 euros" << endl;
    cout << b200 << " billetes de 200 euros" << endl;
    cout << b100 << " billetes de 100 euros" << endl;
    cout << b50 << " billetes de 50 euros" << endl;
    cout << b20 << " billetes de 20 euros" << endl;
    cout << b10 << " billetes de 10 euros" << endl;
      
    return;
}