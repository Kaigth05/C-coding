#include <iostream>
using namespace std;

void maxmin (float a, float b, float&max, float&min);

int main ()
{
    float a, b, max, min;
    a = 3.5;
    b = 3.7;
    maxmin (a, b, max, min);
    
    cout << max << " y " << min << " son max y min " << endl;
    return 0;
}

void maxmin (float a, float b, float&max, float&min)
{
    if (a>b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
}