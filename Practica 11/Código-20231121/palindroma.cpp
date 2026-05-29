#include <iostream>
#include <string>
using namespace std;
bool EsPalindroma (string);
int main (void)
{
	string palabra;
	bool ok;
	char op;
	do
	{
		cout << "Dame una palabra: ";
		getline(cin,palabra);
		ok = EsPalindroma (palabra);
		if (ok)
			cout << "Es palindroma." << endl;
		else
			cout << "No es palindroma." << endl;
		cout << "Quieres introducir mas palabras (S/N)?" << endl;
		cin >> op;
	}
	while (op == 'S' || op == 's');
	system ("pause");
	return 0;
}
bool EsPalindroma (string palabra)
{
	bool ok;
	int i,largo;
	string s, palabra_sin_s, palabra_inv; //para guardar espacios
	
	s = " ";
	largo = palabra.length();
	
	while(palabra.find(" ")!=string::npos)
	{
		palabra_sin_s = palabra.erase(palabra.find(" "),1);
	}
	
	for (i=largo; i>0; i--)
	{
		palabra_inv += palabra_sin_s[i];
	}
	
	if(palabra_inv == palabra_sin_s)
		ok=true;
	else
		ok=false;
		
	return ok;
	

}