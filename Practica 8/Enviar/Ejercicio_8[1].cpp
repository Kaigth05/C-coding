/* Mateo Guijarro Pardo y Javier Diaz Sanz
			Fecha:05/11/2023 				*/
#include<iostream>
#include<fstream>
using namespace std;
void funcion1(ofstream & );
void funcion2(ifstream &, ofstream &);
void funcion3(ifstream &, ofstream &);

int main()
{
	ifstream f;
	ofstream x;
	
	funcion1 (x);
	funcion2 (f,x);
	funcion3 (f,x);
	return 0;
}

void funcion1(ofstream & x)
{
	int n, m, i;
	x.open ("datos.txt");
	
	if (!x)
		cout<<"Algún fichero no se ha podido abrir"<<endl;
	else 
	{
		for (i=1; i<=5; i++)
		{
			
			cout<<"Introduce una pareja de numeros enteros menores que 1000"<<endl;
			cin>>n;
			cin>>m;
		
			if(n>=1000 || m>=1000)
			{
				cout<<"valores no validos, vuelve a introducir"<<endl;
				i--;
			}	
			
			x<<n<<"   "<<m<<endl;
			
		}
		x.close();
	}
}

void funcion2 (ifstream & f, ofstream & x)
{
	int a, b, c;
	f.open("datos.txt");
	x.open ("division.bin", ios::binary);
	
	if (!f)
		cout<<"Algún fichero no se ha podido abrir"<<endl;
	if (!x)
		cout<<"Algún fichero no se ha podido abrir"<<endl;
	if (f&& x)
	{
		while (f>>a>>b)
		{
			c=a/b;
			x.write ((char *)(&c), sizeof(c));
		}
	}
	f.close();
	x.close();
}

void funcion3 (ifstream & f, ofstream & x)
{
	int a,b,c;
	ifstream f1;
	f.open ("datos.txt");
	f1.open("division.bin", ios::binary);
	x.open ("todo.txt");
	
	if (!f)
		cout<<"Algún fichero no se ha podido abrir"<<endl;
	if (!f1)
		cout<<"Algún fichero no se ha podido abrir"<<endl;
	if (!x)
		cout<<"Algún fichero no se ha podido abrir"<<endl;
	if (f&&f1&&x)
	{
		x<<"Numero"<<"       "<<"Numero"<<"       "<<"Resultado"<<endl;
		while (f>>a>>b&& f1.read((char *)(&c), sizeof (c)))
		{
			x<<a<<"    	    "<<b<<"   	    "<<c<<endl;	
		}
	}
	cout<<endl<<"Prueba a abrir los correpondientes archivos";
	
	f.close();
	f1.close();
	x.close();	 
}
