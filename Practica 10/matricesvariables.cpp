/***************************************
Autor/a: Javier Díaz Sanz y Mateo Guijarro Pardo
Fecha de realización: 14-11-2023
Objetivo: 
***************************************/
#include <iostream>
using namespace std;

const int N = 100;
const int M = 100;
typedef int Matriz[N][M];

void introducirMatriz (Matriz, int &, int&);
void mostrarMatriz (const Matriz, int, int);

int main (void)
{
    Matriz mat;
    int n,m;

    introducirMatriz (mat, n, m);
    mostrarMatriz (mat, n, m);
    
    system ("pause");
    return 0;
}

/*************************************
void introducirMatriz (Matriz mat, int & n, int & m)
Entradas:
Salidas:
    int n: numero de files de la matriz
    int m: número de columnas de la matriz
    Matriz mat: matriz de enteros
Objetivo:
    Pedir al usuario el tamaño y los elementos de una matriz 
    variable n x m 
**************************************/
void introducirMatriz (Matriz mat, int & n, int & m)
{
    int i, j;
    
     while (n <= 0 || n > N)
    {
        cout << "Introduzca el numero de filas de su matriz: ";
        cin >> n;
    }
    
    while (m <= 0 || m > M)
    {
        cout << "Introduzca el numero de columnas de su matriz: ";
        cin >> m;
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <  m; j++)
        {
            cout << "Introduzca el elemento " << i << " " << j << ": ";
            cin >> mat [i][j];
        }
    }
    return;
}
/*************************************
void mostrarMatriz (const Matriz mat, int n, int m)
Entradas:
    Matriz mat: matriz nxm
    int n: número de filas de la matriz
    int m: número de columnas de la matriz
Salidas:
Objetivo:
    Mostrar la matriz por pantalla
**************************************/
void mostrarMatriz (const Matriz mat, int n, int m)
{
    int a, b;
    
    for (a = 0; a < n; a++)
    {
        for (b = 0; b <  m; b++)
        {
            cout << mat [a][b] << " ";
        }
        cout << endl;
    }
    return;
}

