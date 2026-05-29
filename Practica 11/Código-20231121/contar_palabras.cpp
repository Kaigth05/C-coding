#include <iostream>
using namespace std;
#include <string>
#include <clocale>
#include <windows.h>

int ContarPalabras (string);

int main (void)
{ 
 string frase;
 int num_palabras;
 char op;
 
// Establecer el idioma a español para admitir acentos
 setlocale(LC_ALL, "spanish");
 SetConsoleCP(1252); // Cambiar STDIN - Para máquinas Windows
 SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
 
 do
 { 
 cout << "Dame una frase:" << endl;
 getline (cin, frase);
 num_palabras = ContarPalabras (frase);
 cout << "La frase tiene " << num_palabras << " palabras." << endl;
 cout << "Quieres continuar introduciendo frases (s/n)" << endl;
 cin >> op;
 cin.ignore ();
 } 
 while (op == 'S' || op == 's');
 
 return 0;
} 

/*************************************
int ContarPalabras (string s) 
Entradas: 

 
String s: La cadena de entradas
Salidas: 
 int: el número de palabras de la cadena de entrada
Objetivo: Contar las palabras en una cadena de texto sin signos de puntuación, suministrada como parámetro
**************************************/

int ContarPalabras (string s) 
{
    int resultado;
    int pos;
    pos = s.find (" ");
    
    if (pos == -1) 
    {
        resultado = 1;
    }
    else
    {
        resultado = 1;
        do 
        {
            if (isalnum(s[pos-1]))
                resultado ++;
                
            pos = s.find (" ", pos + 1);
            
        }
        while (pos != string::npos);
    }
    
    return resultado;
}