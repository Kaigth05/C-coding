#include <iostream> 
using namespace std; 
#include <cstdlib> 

const int N = 5; 
typedef int vector[N]; 

void inicializar_vector(vector); 
void insertar_elemento(vector, int); 
void mostrar_vector(const vector); 

int main (void) 
{
    int i, a=5;
    vector v; 
    
   for (i = 0; i < N; i++ )
    {
        v[i] = 0;
    }
     
    inicializar_vector(v); 
    
    insertar_elemento(v, 7); 
    insertar_elemento(v, 9); 
    insertar_elemento(v, 2); 
    insertar_elemento(v, 4); 
    insertar_elemento(v, 10); 
    insertar_elemento(v, 8); 
    insertar_elemento(v, 5); 
    insertar_elemento(v, 1); 
    
    mostrar_vector (v); 
    cout << a;
    
    return 0; 
} 

void inicializar_vector (vector v) 
{
    int i, j, k, t;
    
    for (i = 0; i < N; i++ )
    {
        cout << "Dame un numero" 
        << endl; 
        cin >> v[i]; 
    }
    
    for (j = 0; j < N - 1; j++)
    {
        for (k = j +1; k < N ; k++)
        {
            if (v[k] > v[j])
            {
                t = v [j];
                v[j] = v[k];
                v[k] = t;
            }
        }
    }
    
    return;
}

void insertar_elemento(vector v, int num) 
{ 
    int i, j, t;
    
    if (num > v[4])
    {
        v[4] = num;
    }
        
    for (i = 0; i < N ; i++)
    {
        for (j = i+1; j < N; j++)
        {
            if (v[j] > v[i])
            {
                t = v [i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }
    return; 
}

void mostrar_vector(const vector v)
{
    int i;
    
    cout << "La secuencia queda asi: \n";
    
    for (i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
    return; 
}