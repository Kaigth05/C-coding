#include <iostream>
#include <cmath>
using namespace std;

const short MAX = 21;

typedef unsigned long long Vector [MAX];

void Calc21Primos (Vector);

int main ()
{
    Vector vector;
    int i;
    unsigned long long suma = 0;
    
    Calc21Primos (vector);
    
    for (i = 0; i < MAX; i++)
        suma += vector [i];
        
    cout << "La suma de los 21 primeros primos superiores";
    cout << " a diez mil billones dos mil cien es : " <<  suma  <<  endl;
    
    return 0;
}

void Calc21Primos (Vector v)
{
    short acc = 0;
    unsigned long long i;
    unsigned long long cuadr, num = 10000000000002100;
    unsigned long long suma = 0;
    bool primosuma = false;
    unsigned long long sumap = 0;
    short j;
    
    while (acc < MAX)
    {
        cuadr = sqrt (num);
        for (i = 1; i <= cuadr; i++)
        {
            if (num % i == 0)
                suma += i;
        }
        
        if (suma == 1)
        {
            v [acc] = num;
            acc ++;
        }
        
        suma = 0;
        num ++; 
    }
    
    while (!primosuma)
    {
        cuadr = sqrt (suma);
        for (i = 1; i <= cuadr; i++)
        {
            if (num % i == 0)
                sumap += i;
        }
        
        if(sumap == 1)
            primosuma = true;
            
        else
        {
            for (j = 0; j < MAX-1; j++)
                v[j] = v [j+1];
            
            num = v[MAX-1] + 1;
            
            while (acc < MAX+1)
            {
                cuadr = sqrt (num);
                for (i = 1; i <= cuadr; i++)
                {
                    if (num % i == 0)
                        suma += i;
                }
                
                if (suma == 1)
                {
                    v [acc] = num;
                    acc ++;
                    cout << num << endl;
                }
                
                suma = 0;
                num ++; 
            }
        }
    }
    
    return; 
}
