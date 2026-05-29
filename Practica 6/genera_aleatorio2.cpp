#include <iostream>
#include <ctime>
using namespace std;

int pide_valor_al_usuario (int inferior, int superior); 
int dame_numero_aleatorio (int inferior, int superior);

int main() 
{ 
 int inferior;
 int superior;
 int i; 
 
 inferior=pide_valor_al_usuario (0,99); 
 superior=pide_valor_al_usuario (inferior,100);
 srand (time (NULL));
 
 for (i = 0; i<10; i++) 
    {
     cout <<  dame_numero_aleatorio (inferior, superior) << endl;
    }
 return 0;  
}

int pide_valor_al_usuario (int inferior, int superior)
{
    int num;
    cout << "Elija un número natural menor o igual a 100\n";
    cin >> num;
    
     while (num<inferior || num>superior)
     {
         cout << "Elija otro valor: \n";
         cin >> num;
     }
        
    return num;
}

int dame_numero_aleatorio (int inferior, int superior)
{
    int x, a, b, c;
    a = rand();
    b = (superior - inferior + 1);
    c = a % b;
    x = (c + inferior);
    
    return x;
}