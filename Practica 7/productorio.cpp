#include <iostream>
using namespace std;

long long productorio (int a, int b);

int main ()
{
    int a, b, res;
    a = 8;
    b = 12;
    res = productorio (a, b);
    
    cout << a << " y " << b << " son " << res << endl;
    return 0;
}

long long productorio (int a, int b)
{
    long long res;
    
    if(b == a)
    {
        res = a;
    }
    
    else 
        if (b>a)
        {
            res = b * productorio (a, b-1);
        }
        else
            cout << "No podemos calcular cunado a>b";
            
    return res;
}