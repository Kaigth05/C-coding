/***************************************
Autor/a: Javier Díaz Sanz y Mateo Guijarro Pardo
Fecha de realización: 14-11-2023
Objetivo: 
***************************************/
#include <iostream>
using namespace std;
#include <fstream>

const int N = 100;
const int M = 100;
typedef int Matriz[N][M];

void leerMatriz (ifstream & f, Matriz, int &, int &);
void escribirMatriz (ofstream &, const Matriz, int, int);
void sumarMatrices (const Matriz, const Matriz, int, int, Matriz);

int main (void)
{
    Matriz mat1, mat2, matsuma;
    int n1, m1, n2, m2;
    ifstream f1, f2;
    ofstream fout;
    
    f1.open("matriz1.txt");
    f2.open("matriz2.txt");
    if (f1 && f2)
    {
        leerMatriz(f1, mat1, n1, m1);

        leerMatriz(f2, mat2, n2, m2);

        if ((n1 == n2)&&(m1 == m2))
        {
            sumarMatrices(mat1, mat2, n1, m1, matsuma);
            fout.open("matrizSuma.txt");

            if (fout)
            {
                escribirMatriz(fout, matsuma, n1, m1);
            }
            else
            {
                cout << "Error abriendo archivo de escritura";
            }
        }
        else
        {
            cout << "No se pueden sumar matrices con diferentes dimensiones";
        }
        f1.close();
        f2.close();
        fout.close();
    }
    else
    {
        cout << "Error abriendo archivos de matrices";
    }

    system ("pause");
    return 0;
}

/*************************************
void leerMatriz (ifstream & f, Matriz mat, int & n, int & m)
Entradas:
    ifstream f: Descriptor del fichero donde estan guardados los datos de la matriz
Salidas:
    Matriz mat: matriz de nxm de enteros
    int n: numero de filas de la matriz
    int m: numero de columnes de la matriz
Objetivo:
    Leer matriz del fichero f suministrado como parámetro 
**************************************/
void leerMatriz (ifstream & f, Matriz mat, int & n, int & m)
{
    int i, j, x;
    
    f >> n;
    f >> m;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            f >> x;
            mat [i][j] = x;
        }
    }
    return;
}

/*************************************
void sumarMatrices (const Matriz mat1, const Matriz mat2, int n, int m, Matriz matsuma)
Entradas:
    Matriz mat1: matriz nxm
    Matriz mat2: matriz mxn
    int n: numero de filas de la matriz
    int m: numero de columnas de la matriz
Salidas:
    Matriz matsuma: matriz con la suma de mat1 y mat2
Objetivo:
    Sumar dos matrices
**************************************/
void sumarMatrices (const Matriz mat1, const Matriz mat2, int n, int m, Matriz matsuma)
{
    int a, b;
    
    for (a = 0; a < n; a++)
    {
       for (b = 0; b < m; b++) 
       {
            matsuma [a][b] = mat1[a][b] + mat2[a][b];
       } 
    }
    return;
}

/*************************************
void escribirMatriz (ofstream & f, const Matriz mat, int n, int m)
Entradas:
    Matriz mat: matriz nxm
    int n: numero de filas de la matriz
    int m: numero de columnas de la matriz
    ofstream f: descriptor de archivo donde escribiremos la matriz
Objetivo:
    Escribir la matriz en un fichero de texto
**************************************/
void escribirMatriz (ofstream &f, const Matriz mat, int n, int m)
{
    int x, y;
    
    f << n << endl;
    f << m << endl;
    
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < m; y++)
        {
            f << mat[x][y] << " ";
        }
        
        f << endl;
    }
    return;
}