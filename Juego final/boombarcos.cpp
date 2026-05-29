/***************************************
Autor/a: Javier Díaz Sanz y Mateo Guijarro Pardo
Fecha de realización: 12-12-2023
Objetivo: Acabar to
***************************************/
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <fstream>
#include <windows.h>

const int N = 20;
const int M = 20;
typedef bool MatrizBooleanos[N][M];
typedef int MatrizEnteros[N][M];

struct Configuracion
{
    unsigned short filas;
    unsigned short columnas;
    unsigned short barcos;	
};

struct Disparo
{
	int x;
	int y;
	int distancia;

};

const int MAX_DISPARO = 200;
typedef Disparo D_Vector[MAX_DISPARO];

struct Disparos
{
	D_Vector disparo;
	int nd;
};

struct Partida
{
    int turnos;
	Configuracion usada;
	int victoria;
    Disparos disps;
};

const int MAX_PARTIDAS = 100;
typedef Partida P_Vector[MAX_PARTIDAS];

struct Partidas
{
    P_Vector historial;
    int np;
};

int PedirValorEnRango(int, int);
void InicializarDisparos(MatrizEnteros,int,int);
bool PosicionarBarcosAleatoriamente(MatrizBooleanos,int,int,int,int,int);
bool PedirPosicionesDeBarcos(MatrizBooleanos,int,int, int);
void VisualizarTableros(const MatrizEnteros,const MatrizEnteros,int,int);
void VisualizarPosicionBarcos(const MatrizBooleanos, const MatrizBooleanos,int,int);
int ProcesarDisparo(int,int,const MatrizBooleanos,MatrizEnteros,int,int);
void CirculoManhattan (Partida&, MatrizEnteros);

Configuracion pedirConfiguracion();
Configuracion leerConf();
void visualizarConfiguracion(Configuracion);

void guardarDisparosEnFichero(Disparos);

void guardarPartidasEnFichero(Partidas);
Partidas leerPartidasDeFichero();

Partida JugarPartida();
void JugarPartidaDep();
void UltPartida ();
void EditarConf ();
void MostrarConf ();
void MostrarData ();
int LeerNp();
void GuardarNp(int);

int main ()
{
    srand(time(NULL)); // para que cada vez sean distintos
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    int num;
    Partidas games;
    do
    {
        cout << "Introduzca la opcion que prefiera\n" << endl;
        
        cout << "1.- Jugar partida\n" << endl;
        cout << "2.- Jugar en modo depuracion\n" << endl;
        cout << "3.- Reproducir ultima partida\n" << endl;
        cout << "4.- Editar la configuracion del juego\n" << endl;
        cout << "5.- Mostrar la configuracion del juego\n" << endl;
        cout << "6.- Mostrar estadisticas\n" << endl;
        cout << "7.- Salir del juego\n" << endl;
        
        cin >> num;
        switch (num)
        {
            case 1 :
                games = leerPartidasDeFichero();
                games.np = LeerNp ();
                games.historial[games.np] = JugarPartida();
                guardarDisparosEnFichero(games.historial[games.np].disps);
                guardarPartidasEnFichero(games);
                games.np ++;
                GuardarNp (games.np);
                break;
                
            case 2 :
                JugarPartidaDep();
                break;
                
            case 3 :
                UltPartida ();
                break;
                
            case 4 :
                EditarConf ();
                break;
                
            case 5 :
                MostrarConf ();
                break;
                
            case 6 :
                MostrarData ();
                break;
            case 7 :
                cout << "El juego se cerrara en breves instantes :D\n";
                break;
                
            default :
                cout << "Introduzca otro valor\n";
        }
        cout << endl;
        
        system ("pause");
        system("cls");
    }
    while (num != 7);
    
    return 0;
}

/***************************************************************************************
int LeerNp ()
Entradas:
    Ninguna 
	 
Salidas:
    int Np

Objetivo:
    Abre el archivo donde tenemos guardado Np (el numero de partidas) lo lee y te lo devuelve
***************************************************************************************/

int LeerNp ()
{
    ifstream f;
    int np;
    
    f.open("np.txt");
    if (!f)
        cout << "No se pudo abrir np.txt" << endl;
    else
    {
        f >> np;
        f.close();
    }
    
    return np;   
}

/***************************************************************************************
void GuardarNp (int n)
Entradas:
    int Np 
	 
Salidas:
    Ninguna

Objetivo:
    Guarda int Np en el archivo correspondiente
***************************************************************************************/

void GuardarNp (int n)
{
    ofstream f;
    
    f.open("np.txt");
    if (!f)
        cout << "No se pudo abrir np.txt" << endl;
    else
    {
        f << n;
    }
    
    f.close();
    return;
}

/***************************************************************************************
Partidas leerPartidasDeFichero()
Entradas:
    Ninguna 
	 
Salidas:
    Partidas partidas

Objetivo:
    Lee toda la informacion sobre las partidas anteriores en dicho archivo y la devuelve en el struct partidas
***************************************************************************************/

Partidas leerPartidasDeFichero()
{
	Partidas parts;
    ifstream f;
	
	f.open("historial_partidas.txt");
	if (!f)
    {
        cout << "No se pudo abrir el fichero de entrada\n";
    }
	else
	{
		while (f >> parts.np)
		{
			f >> parts.historial[parts.np].turnos >> parts.historial[parts.np].usada.filas;
            f >> parts.historial[parts.np].usada.columnas >> parts.historial[parts.np].usada.barcos;
            f >> parts.historial[parts.np].victoria;
		}
	}
	
	return parts;
}

/***************************************************************************************
void guardarPartidasEnFichero(Partidas parts)
Entradas:
    Partidas partidas 
	 
Salidas:
    Ninguna

Objetivo:
    guarda toda la informacion del struct en el fichero para poder leerla mas tarde
***************************************************************************************/

void guardarPartidasEnFichero(Partidas parts)
{
	int i;
    ofstream f;
	
	f.open("historial_partidas.txt");
	if (!f)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		for (i = parts.np; i >= 0; i--)
		{
            f << i << endl;
			f << parts.historial[i].turnos << endl << parts.historial[i].usada.filas;
            f << " " << parts.historial[i].usada.columnas << " ";
            f << parts.historial[i].usada.barcos << endl;
            f << parts.historial[i].victoria << endl;
		}
	}
}

/***************************************************************************************
Partida JugarPartida()
Entradas:
    Ninguna 
	 
Salidas:
    Partida partida

Objetivo:
    Ejecuta el juego "normal", y devuelve toda la informacion usada en el struct para poder guardarla en un fichero
***************************************************************************************/

Partida JugarPartida()
{
    Partida game;
    MatrizBooleanos barcos_usuario,barcos_ordenador;
    MatrizEnteros disparos_usuario,disparos_ordenador;
    int aciertos_usuario, aciertos_ordenador;

	aciertos_usuario = 0;
	aciertos_ordenador = 0;
	game.turnos = 0;
    game.disps.nd = 0;
    
    game.usada = leerConf();

	InicializarDisparos(disparos_usuario,game.usada.filas,game.usada.columnas);
	InicializarDisparos(disparos_ordenador,game.usada.filas,game.usada.columnas);
	
    PosicionarBarcosAleatoriamente(barcos_ordenador,game.usada.filas,game.usada.columnas, 
    game.usada.barcos,game.usada.filas,game.usada.columnas);
																				
    PedirPosicionesDeBarcos(barcos_usuario,game.usada.filas,game.usada.columnas,
    game.usada.barcos);
    
    system("cls");
		
    while (aciertos_usuario < game.usada.barcos && aciertos_ordenador < game.usada.barcos)
    {
        game.turnos ++;
		do 
        {
		   	cout << "Introduzca la fila del disparo (max="<<game.usada.filas<<"): ";
	    	game.disps.disparo[game.disps.nd].x = PedirValorEnRango(1, game.usada.filas);
	    	cout << "Introduzca la columna del disparo (max="<<game.usada.columnas<<"): ";
	    	game.disps.disparo[game.disps.nd].y = PedirValorEnRango(1, game.usada.columnas);
	    	game.disps.disparo[game.disps.nd].x--; 
	        game.disps.disparo[game.disps.nd].y--; 
	    	if (disparos_usuario[game.disps.disparo[game.disps.nd].x][game.disps.disparo[game.disps.nd].y]!=-1) 
	    	   cout << "Ahí ya había disparado anteriormente. Deme una nueva coordenada."<<endl;
	    } 
        while (disparos_usuario[game.disps.disparo[game.disps.nd].x][game.disps.disparo[game.disps.nd].y]!=-1); 
	    
	    game.disps.disparo[game.disps.nd].distancia = ProcesarDisparo(game.disps.disparo[game.disps.nd].x,
        game.disps.disparo[game.disps.nd].y,barcos_ordenador,disparos_usuario,game.usada.filas,game.usada.columnas);
	    if (game.disps.disparo[game.disps.nd].distancia == 0)  
	    {
		   aciertos_usuario++;
		   cout << "BINGO!"<<endl;
		}  
        else
	         cout << "AGUA!"<<endl;
		
	    
	    if (aciertos_usuario < game.usada.barcos)   
	    {   
            game.disps.nd ++;
            
            if(game.disps.nd != 1 && game.disps.disparo[game.disps.nd - 2].distancia != 0)
            {
                CirculoManhattan (game, disparos_ordenador);                            
		    }
            
            else
            {
                do 
                {
    		  	 	game.disps.disparo[game.disps.nd].x = rand();
    				game.disps.disparo[game.disps.nd].x = (game.disps.disparo[game.disps.nd].x % game.usada.filas) + 1;
    				game.disps.disparo[game.disps.nd].y = rand();
    				game.disps.disparo[game.disps.nd].y = (game.disps.disparo[game.disps.nd].y % game.usada.columnas) + 1;
    	   		} 
                while (disparos_ordenador[game.disps.disparo[game.disps.nd].x][game.disps.disparo[game.disps.nd].y]!=-1);                
            }
            
            
	        game.disps.disparo[game.disps.nd].distancia = ProcesarDisparo(game.disps.disparo[game.disps.nd].x,
            game.disps.disparo[game.disps.nd].y,barcos_usuario,disparos_ordenador,game.usada.filas,game.usada.columnas);
	        
			system("cls");
            
	        VisualizarTableros(disparos_usuario,disparos_ordenador,game.usada.filas,game.usada.columnas);
		    
	        cout << "El ordenador ha disparado en fila " << game.disps.disparo[game.disps.nd].x+1 << ", columna ";
            cout << game.disps.disparo[game.disps.nd].y+1 <<endl;
	        if (game.disps.disparo[game.disps.nd].distancia == 0)
	        {
		        aciertos_ordenador++;
		        cout << "BINGO!"<<endl;
	        } else
	            cout << "AGUA!"<<endl;
		} 
        else
        {
	        system("cls");
		    VisualizarTableros(disparos_usuario,disparos_ordenador,game.usada.filas,game.usada.columnas);
		}
	    
        game.disps.nd ++;
    }
	
	if (aciertos_usuario == game.usada.barcos)
    {
        game.victoria = 1;
        cout << "Enhorabuena, has ganado la partida con " << game.turnos << " disparos " << endl;
    }
    else
    {
        game.victoria = 0;
        cout << "Vaya, el ordenador ha conseguido vencerte con " << game.turnos << " disparos " <<  endl;
    }
       
    return game;
}

Configuracion leerConf()
{
    ifstream f;
    Configuracion c;
    f.open("confi.txt");
    
    if (!f)
        cout << "No se pudo abrir el documento confi.txt" << endl;
    else
    {
        f >> c.filas;
        f >> c.columnas;
        f >> c.barcos;
    }
    
    f.close ();
    
    return c;
}

/***************************************************************************************
int PedirValorEnRango(int minimo, int maximo)
Entradas:
    int minimo. El límite inferior
	int maximo. El límite superior
	 
Salidas:
    El valor introducido por el usuario

Objetivo:
    Pedir al usuario un valor en un rango. La función pedirá el valor hasta que se encuentre
    en el intervalo cerrado [minimo maximo]
***************************************************************************************/
int PedirValorEnRango(int minimo, int maximo)
{
	 int resultado;
	 do {
     	 cin >> resultado;
     	 if (resultado > maximo || resultado < minimo)
     	 {
     	    cout <<	"El valor debe estar entre " << minimo << " y " << maximo <<". Por favor, introduzca un valor en este rango: " ; 
		 }
	   } while (resultado > maximo || resultado < minimo); 
	return resultado;
}
/***************************************************************************************
void InicializarDisparos(MatrizEnteros m, int filas, int columnas)
Entradas:
    MatrizEnteros m. La matriz con las distancias
    int filas: número de filas que tiene la matriz
    int columnas: número de columnas que tiene la matriz  
	
	 
Salidas:
    Ninguna

Objetivo:
    Inicializa la matriz con todos los valores a -1, indicando que no ha habido ningún
    disparo aún
***************************************************************************************/
void InicializarDisparos(MatrizEnteros m, int filas, int columnas)
{
	int i,j;
	for (i = 0;i<filas;i++)
	  for (j = 0;j<columnas;j++)
	  	m[i][j]=-1;  
	
}
/***************************************************************************************
bool PedirPosicionesDeBarcos(MatrizBooleanos m,int filas,int columnas, int nbarcos)
Entradas:
    
Entradas:
    int filas: número de filas que tiene la matriz
    int columnas: número de columnas que tiene la matriz
    int nbarcos: número de valores que debemos poner a true para indicar la posición de los barcos


Salidas:
    Matriz m: La matriz a inicializar
    Resultado de la función: true si la ha sido posible realizar la inicialización,
                            y false si el número de barcos especificado supera el
                            tamaño de la matriz
    
Objetivo:
    Inicializar la matriz con nbarcos valores verdaderos y el resto falsos. Las posiciones 
	de los valores verdaderos (las posiciones de los barcos) se le pedirán al usuario.
	Si el número de barcos especificado supera el tamaño de la matrix, se devuelve 
    la matriz con todos sus elementos inicializados a verdadero.
***************************************************************************************/
bool PedirPosicionesDeBarcos(MatrizBooleanos m, int filas, int columnas, int nbarcos)
{
    bool resultado;
    int i,j,k;
	
	if (nbarcos > filas * columnas)
	{
	
	  resultado = false;
	  for (i = 0; i < filas; i++)
	     for (j = 0; j< columnas; j++)
	        m[i][j] = true;
    } 
	else 
    {
        resultado = true;
        
        for (i=0;i<filas;i++)
	       for (j=0;j<columnas;j++)
	          m[i][j]=false;
        
    	for (i = 0; i < nbarcos; i++)
    	{
            cout << "dame la fila donde quieras que se ubice tu barco: " << i+1 << ": ";
			j = PedirValorEnRango(1, filas);
			cout << "dame la columna donde quieras que se ubice tu barco: " << i+1 << ": ";
			k = PedirValorEnRango(1, columnas);
			j--; 
			k--;
            
            if (m[j][k]==false)  // si el valor que contenía ya era verdadero, no hacemos nada
	    		m[j][k]=true;
                
			else  // si el valor que contenía ya era verdadero, no hacemos nada
	    	{
	    		while (m[j][k] == true)
        	    {
        	        cout << "dame la game.disps.disparo[game.disps.nd].x donde quieras que se ubice tu barco: " << i+1 << ": ";
        			j = PedirValorEnRango(1, filas);
        			cout << "dame la columna donde quieras que se ubice tu barco: " << i+1 << ": ";
        			k = PedirValorEnRango(1, columnas);
        			j--; 
        			k--;
        		}
                m[j][k] = true;
			}
                  
		}
    	
	}
	return resultado;
}
/***************************************************************************************
bool PosicionarBarcosAleatoriamente(MatrizBooleanos m,int filas,int columnas, int nbarcos)
Entradas:
    
Entradas:
    int filas: número de filas que tiene la matriz
    int columnas: número de columnas que tiene la matriz
    int nbarcos: número de valores que debemos poner a true para indicar la posición de los barcos


Salidas:
    Matriz m: La matriz a inicializar
    Resultado de la función: true si la ha sido posible realizar la inicialización,
                            y false si el número de barcos especificado supera el
                            tamaño de la matriz
    
Objetivo:
    Inicializar la matriz con nbarcos valores verdaderos y el resto falsos. Si el 
    número de barcos especificado supera el tamaño de la matrix, se devuelve 
    la matriz con todos sus elementos inicializados a verdadero.
***************************************************************************************/
bool PosicionarBarcosAleatoriamente(MatrizBooleanos m, int filas,int columnas, int nbarcos, int nfilas, int ncolumnas)
{
    bool resultado;
    int i,j, barco = 0;
	
	if (nbarcos > filas*columnas)
	{
	
	  resultado=false;
	  for (i=0;i<filas;i++)
	     for (j=0;j<columnas;j++)
	        m[i][j]=true;
    } 
	else 
    {
        resultado=true;
        
        for (i = 0; i < filas; i++)
	       for (j = 0;j < columnas; j++)
	          m[i][j]=false;
        
        while (barco < nbarcos)
        {
            filas = rand();
    		filas = (filas % nfilas);
    		columnas = rand();
    		columnas = (columnas % ncolumnas);   
            
            if (m[filas][columnas] == false)	    	
            {
	    		m[filas][columnas] = true;  
	    		barco++;   
			}
        }          
	}
	return resultado;
}
/***************************************************************************************
boolean ProcesarDisparo(int fila_disparo, int columna_disparo, const MatrizBooleanos barcos,MatrizEnteros disparos, int nfilas,int ncolumnas)
    
Entradas:
    int fila_disparo, int columna_disparo: posición del disparo
    const MatrizBooleanos barcos: matriz booleana con las posiciones de los barcos (valor true donde hay barcos)
    
    int filas: número de filas que tiene la matriz
    int columnas: número de columnas que tiene la matriz
    
    

Salidas:
    MatrizEnteros disparos: modifica la matriz para indicar en la posición del disparo la distancia de Manhattan al barco más cercano
    La función devuelve true si el disparo fué certero y false en caso contrario


Nota: se asume el mismo tamaño para las matrices barcos y disparos

Objetivo:
    Procesar un disparo. Comprueba si el disparo fue certero, calcula la distancia al barco más cercano y la introduce en la matriz de disparos
***************************************************************************************/
int ProcesarDisparo(int fila_disparo, int columna_disparo,const MatrizBooleanos barcos,MatrizEnteros disparos,int nfilas,int ncolumnas)
{
    int i,j;
	int minimaDistancia=nfilas+ncolumnas+1;  
	int distancia;
	
	if (barcos[fila_disparo][columna_disparo ]== true) // Si el disparo ha sido certero
	{
	    disparos[fila_disparo][columna_disparo] = 0;
        minimaDistancia = 0;
    }
	else // el disparo ha ido al agua
	{
		for (i = 0; i < nfilas;i++)
	    	for (j = 0;j < ncolumnas;j++)
	    		if (barcos[i][j] == true) 
	        	{
	            	distancia = abs(fila_disparo - i) + abs(columna_disparo - j);  
	            	if (distancia < minimaDistancia) 
	                minimaDistancia = distancia; 
		    	}  
	  disparos[fila_disparo][columna_disparo] = minimaDistancia;	// TO DO: COMPLETAR ESTA PARTE DEL PROGRAMA
    }
    return minimaDistancia;  
}
/***************************************************************************************
void VisualizarTableros(const MatrizEnteros m1, const MatrizEnteros m2, int filas, int columnas)
Entradas:
    const MatrizEnteros m1: La matriz de disparos del usuario
    const MatrizEnteros m2: La matriz de disparos del ordenador
    int filas: número de filas que tiene la matriz
    int columnas: número de columnas que tiene la matriz
    Nota: se asume el mismo tamaño para ambas matrices
    

Salidas:
    No tiene. Solo muestra por pantalla
    
Objetivo:
    Visualizar las matrices de distancias mínimas una al lado de la otra, mostrando solo los valores
    correspondientes a las casillas en las que se hayan producido disparos
    
    Para cada casilla: 
	    Para las casillas sobre las que se ha producido un disparo, se mostrará la distancia al barco más cercano
		Si no se ha disparado sobre ella no se mostrará nada (un espacio)
		Si el valor es mayor que 9, se mostrará el símbolo >
		
	    
***************************************************************************************/
void VisualizarTableros(const MatrizEnteros m1, const MatrizEnteros m2, int filas, int columnas)
{
    
	int i,j;

	// Lo primero las cabeceras
	cout << "DISPAROS USUARIO";
	for (i=0;i<columnas-6;i++)
	   cout <<" ";
	cout << "DISPAROS ORDENADOR" <<endl;
	
	
	// Luego una línea con los numeros de las columnas
	cout <<"   "; // tres espacios antes de los números (para dejar el hueco correspondiente a los números de las filas)
	for (i=0;i<columnas;i++) // ahora los números de las columnas de la primera matriz
	{
      if (i<9)  
	    cout <<i+1;
	  else   // si el número a mostrar tiene más de una cifra, mostrar un punto en su lugar
	    cout << ".";
    }
	cout <<"        "; // 8 espacios para separar las matrices
    
    for (i=0;i<columnas;i++) // ahora los números de las columnas de la segunda matriz	
	{
	
      if (i<9)
	    cout <<i+1;
	  else  
	    cout << ".";
    }
    cout << endl; // la primera game.disps.disparo[game.disps.nd].x ya está completa
    
    
	// Primera game.disps.disparo[game.disps.nd].x de guiones: dos espacios, columnas+2 guiones, 6 espacios de separación y otras columnas+2 guiones (el +2 es para los bordes, y los dos espacios 
	// es para dejar el hueco correspondiente a los números de las filas en la visualización de la matriz)
    cout <<"  "; // dos espacios
	for (i=0;i<columnas+2;i++)	// columnas+2 guiones 
      cout <<"-";
      
	cout <<"      "; // 6 espacios
    
    for (i=0;i<columnas+2;i++)	// columnas+2 guiones
      cout <<"-";
    
    cout << endl;
    
    // vamos con las filas
    for (i=0;i<filas;i++) // para cada game.disps.disparo[game.disps.nd].x	
    {
       // primero el número de game.disps.disparo[game.disps.nd].x de la primera matriz
	   if (i<9) // para mantener la estética, cuando el número a mostrar tiene una cifra, le ponemos un espacio delante
         cout << " " << i+1;
       else
	     if (i<99) 
		    cout << i+1;
		 else  // si tiene más de dos cifras, reemplazamos el número por ..
		    cout << "..";	 
	   cout << "|"; 	// Después ponemos una barra vertical (el borde izquierdo de la primera matriz)
	   for (j=0;j<columnas;j++)	// recorremos toda la game.disps.disparo[game.disps.nd].x i de la primera matriz y mostramos una x o un espacio, dependiendo de si es true o false
	   {
	   	   
		   if (m1[i][j]<0)
	   	     cout << " "; // no se ha disparo aquí aún
	   	   else
	   	     if (m1[i][j]==0) 
	   	        cout << "*"; // Distancia cero. Fué un acierto
	   	     else
				if (m1[i][j]<10) // Distancia de un solo dígito, la ponemos
				   cout <<  m1[i][j];
				else   
				   cout <<  ">";  // distancia mayor que 10
	   }
       cout << "|"; 	// El borde derecho de la primera matriz
	   cout <<"    ";   // los espacios de separación
	   // mostramos el número de game.disps.disparo[game.disps.nd].x de la segunda matriz
	   if (i<9)
         cout << " " << i+1;
       else
	     if (i<99)
		    cout << i+1;
		 else 
		    cout << ".."; 
       cout << "|"; 	// El borde izquierdo de la segunda matriz
       for (j=0;j<columnas;j++)	// recorremos toda la game.disps.disparo[game.disps.nd].x i de la segunda matriz y mostramos una x o un espacio, dependiendo de si es true o false
	   {
	   	   
		   if (m2[i][j]<0)
	   	     cout << " "; // no se ha disparo aquí aún
	   	   else
	   	     if (m2[i][j]==0) 
	   	        cout << "*"; // Distancia cero. Fué un acierto
	   	     else
				if (m2[i][j]<10) // Distancia de un solo dígito, la ponemos
				   cout <<  m2[i][j];
				else   
				   cout <<  ">";  // distancia mayor que 10
	   }
       cout << "|"<< endl; 	// El borde izquierdo de la segunda matriz y el salto de línea
   }
   // y ahora la última línea, que es idéntica a la segunda:
    cout <<"  "; 
	for (i=0;i<columnas+2;i++)	
      cout <<"-";
      
	cout <<"      ";
    
    for (i=0;i<columnas+2;i++)	
      cout <<"-";
    
    cout << endl;	
}

/***************************************************************************************
void CirculoManhattan (Partida& game, MatrizEnteros disparos_ordenador)
Entradas:
    Partida game y MatrizEnteros disparos_ordenador
    
Salidas:
    El disparo que calcula el progama optimo (se pasa por referencia)
    Y el valor distancia en la MatrizEnteros (se pasa por referencia)
    
Objetivo:
    Crea disparos aleatorios del ordenador que cumple dos condiciones:
    - Que no haya disparado previamente ahi el ordenador
    - Que la diferencia entre las posiciones x, y del disparo calculado y el anterior sean menor
		 o iguales a la distancia que se encontraba el ultimo disparo del barco más cercano (por eso el -2)
		
	    
***************************************************************************************/

void CirculoManhattan (Partida& game, MatrizEnteros disparos_ordenador)
{
    do 
    {
  	 	game.disps.disparo[game.disps.nd].x = rand();
		game.disps.disparo[game.disps.nd].x = (game.disps.disparo[game.disps.nd].x % game.usada.filas) + 1;
		game.disps.disparo[game.disps.nd].y = rand();
		game.disps.disparo[game.disps.nd].y = (game.disps.disparo[game.disps.nd].y % game.usada.columnas) + 1;
	} 
    while ( (disparos_ordenador[game.disps.disparo[game.disps.nd].x][game.disps.disparo[game.disps.nd].y]!=-1) 
    || (abs(game.disps.disparo[game.disps.nd].x - game.disps.disparo[game.disps.nd - 2].x)
    + abs(game.disps.disparo[game.disps.nd].y - game.disps.disparo[game.disps.nd - 2].y) > 
    game.disps.disparo[game.disps.nd - 2].distancia) );
    
    return;
}

/***************************************************************************************
void JugarPartidaDep()
Entradas:
    Ninguna
    
Salidas:
    Ninguna (ya que las estadisticas en este modo de juego no importan)
    
Objetivo:
    Ejecuta el juego "depurado", en el que puedes ver la posicion de los barcos de ordenador.
***************************************************************************************/

void JugarPartidaDep()
{
    Partida game;
    MatrizBooleanos barcos_usuario,barcos_ordenador;
    MatrizEnteros disparos_usuario,disparos_ordenador;
    int aciertos_usuario, aciertos_ordenador;

	aciertos_usuario = 0;
	aciertos_ordenador = 0;
	game.turnos = 0;
    game.disps.nd = 0;
    
    game.usada = leerConf();

	InicializarDisparos(disparos_usuario,game.usada.filas,game.usada.columnas);
	InicializarDisparos(disparos_ordenador,game.usada.filas,game.usada.columnas);
	
    PosicionarBarcosAleatoriamente(barcos_ordenador,game.usada.filas,game.usada.columnas, game.usada.barcos,game.usada.filas,game.usada.columnas);
																				
    PedirPosicionesDeBarcos(barcos_usuario,game.usada.filas,game.usada.columnas,game.usada.barcos);
    
    system("cls");
	VisualizarPosicionBarcos(barcos_usuario,barcos_ordenador, game.usada.filas,game.usada.columnas); // Se visualiza la posición de los barcos. Esto es solamente para depuración. Cuando se juegue
                                                                                 // de verdad esta línea debe desparecer.
		
    while (aciertos_usuario < game.usada.barcos && aciertos_ordenador < game.usada.barcos)
    {
        game.turnos ++;
		do 
        {
		   	cout << "Introduzca la fila del disparo (max="<<game.usada.filas<<"): ";
	    	game.disps.disparo[game.disps.nd].x = PedirValorEnRango(1, game.usada.filas);
	    	cout << "Introduzca la columna del disparo (max="<<game.usada.columnas<<"): ";
	    	game.disps.disparo[game.disps.nd].y = PedirValorEnRango(1, game.usada.columnas);
	    	game.disps.disparo[game.disps.nd].x--; 
	        game.disps.disparo[game.disps.nd].y--; 
	    	if (disparos_usuario[game.disps.disparo[game.disps.nd].x][game.disps.disparo[game.disps.nd].y]!=-1) 
	    	   cout << "Ahí ya había disparado anteriormente. Deme una nueva coordenada."<<endl;
	    } 
        while (disparos_usuario[game.disps.disparo[game.disps.nd].x][game.disps.disparo[game.disps.nd].y]!=-1); 
	    
	    game.disps.disparo[game.disps.nd].distancia = ProcesarDisparo(game.disps.disparo[game.disps.nd].x,
        game.disps.disparo[game.disps.nd].y,barcos_ordenador,disparos_usuario,game.usada.filas,game.usada.columnas);
	    if (game.disps.disparo[game.disps.nd].distancia == 0)  
	    {
		   aciertos_usuario++;
		   cout << "BINGO!"<<endl;
		}  
        else
	         cout << "AGUA!"<<endl;
		
	    
	    if (aciertos_usuario < game.usada.barcos)   
	    {   
            game.disps.nd ++;
            
            if(game.disps.nd != 1 && game.disps.disparo[game.disps.nd - 2].distancia != 0)
            {
                CirculoManhattan (game, disparos_ordenador);                            
		    }
            
            else
            {
                do 
                {
    		  	 	game.disps.disparo[game.disps.nd].x = rand();
    				game.disps.disparo[game.disps.nd].x = (game.disps.disparo[game.disps.nd].x % game.usada.filas) + 1;
    				game.disps.disparo[game.disps.nd].y = rand();
    				game.disps.disparo[game.disps.nd].y = (game.disps.disparo[game.disps.nd].y % game.usada.columnas) + 1;
    	   		} 
                while (disparos_ordenador[game.disps.disparo[game.disps.nd].x][game.disps.disparo[game.disps.nd].y]!=-1);                
            }
            
			
	        game.disps.disparo[game.disps.nd].distancia = ProcesarDisparo(game.disps.disparo[game.disps.nd].x,
            game.disps.disparo[game.disps.nd].y,barcos_usuario,disparos_ordenador,game.usada.filas,game.usada.columnas);												      
	        
			system("cls");
	        VisualizarPosicionBarcos(barcos_usuario,barcos_ordenador, game.usada.filas,game.usada.columnas); // Se visualiza la posición de los barcos. Esto es solamente para depuración. Cuando se juegue
                                                                                         // de verdad esta línea debe desparecer.
	        VisualizarTableros(disparos_usuario,disparos_ordenador,game.usada.filas,game.usada.columnas);
		    
	        if (game.disps.disparo[game.disps.nd].distancia == 0)
	        {
		        aciertos_ordenador++;
		        cout << "BINGO!"<<endl;
	        } else
	            cout << "AGUA!"<<endl;
		} 
        else
        {
	        system("cls");
		    VisualizarTableros(disparos_usuario,disparos_ordenador,game.usada.filas,game.usada.columnas);
		}
	    
        game.disps.nd ++;
    }
	
	if (aciertos_usuario == game.usada.barcos)
    {
        game.victoria = 1;
        cout << "Enhorabuena, has ganado la partida con " << game.turnos << " disparos " << endl;
    }
    else
    {
        game.victoria = 0;
        cout << "Vaya, el ordenador ha conseguido vencerte con " << game.turnos << " disparos " <<  endl;
    }
    return;
}

/***************************************************************************************
void VisualizarPosicionBarcos(const Matriz m1, const Matriz m2, int filas, int columnas)
Entradas:
    
Entradas:
    int MatrizBooleanos m1: La primera matriz (con los barcos del usuario marcados)
    int MatrizBooleanos m2: La segunda matriz (con los barcos del ordenador marcados)
    int filas: número de filas que tiene la matriz
    int columnas: número de columnas que tiene la matriz
    Nota: se asume el mismo tamaño para ambas matrices
    

Salidas:
    No tiene. Solo muestra por pantalla
    
Objetivo:
    Visualizar las matrices booleanas una al lado de la otra, mostrando los valores
    falsos como espacios y los verdaderos como una 'x'
***************************************************************************************/
void VisualizarPosicionBarcos(const MatrizBooleanos m1, const MatrizBooleanos m2, int filas, int columnas)
{
	int i,j;
 
	cout << "BARCOS USUARIO ";
	for (i=0;i<columnas-6;i++)
	   cout <<" ";
	cout << " BARCOS ORDENADOR" <<endl;
	
	cout <<"   "; 
	for (i=0;i<columnas;i++) 
	{
      if (i<9)  
	    cout <<i+1;
	  else   
	    cout << ".";
    }
	cout <<"        "; 
    
    for (i=0;i<columnas;i++) 	
	{
	
      if (i<9)
	    cout <<i+1;
	  else  
	    cout << ".";
    }
    cout << endl; 
    
    cout <<"  "; 
	for (i=0;i<columnas+2;i++) 
      cout <<"-";
      
	cout <<"      "; 
    
    for (i=0;i<columnas+2;i++)
      cout <<"-";
    
    cout << endl;
    
    // vamos con las filas
    for (i=0;i<filas;i++)	
    {
	   if (i<9) 
         cout << " " << i+1;
       else
	     if (i<99) 
		    cout << i+1;
		 else  
		    cout << "..";	 
	   cout << "|"; 
	   for (j=0;j<columnas;j++)	
	   {
	   	   if (m1[i][j]==true)
	   	     cout << "+";
	   	   else
	   	     cout << " ";
	   }
       cout << "|"; 	
	   cout <<"    ";   
	   if (i<9)
         cout << " " << i+1;
       else
	     if (i<99)
		    cout << i+1;
		 else 
		    cout << ".."; 
       cout << "|"; 	
       for (j=0;j<columnas;j++)	
	   {
	   	   if (m2[i][j]==true)
	   	     cout << "+";
	   	   else
	   	     cout << " ";
	   }
       cout << "|"<< endl; 	
   }
    cout <<"  "; 
	for (i=0;i<columnas+2;i++)	
      cout <<"-";
      
	cout <<"      ";
    
    for (i=0;i<columnas+2;i++)	
      cout <<"-";
    
    cout << endl;
    
    return;
}

/***************************************************************************************
void guardarDisparosEnFichero(Disparos D)
Entradas:
    Los disparos realizados
    
Salidas:
    Ninguna
    
Objetivo:
    Guarda en el fichero los disparos realizados
***************************************************************************************/

void guardarDisparosEnFichero(Disparos D)
{
	int i;
	ofstream f;
    
	f.open("ultima_partida.txt");
	if (!f)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{;
		
		for(i = 0; i < D.nd; i++)
		{
			f << i << " " << endl;
            f << D.disparo[i].x << " " << D.disparo[i].y << " " << D.disparo[i].distancia << endl;
		}
	}
    
    f.close();
    
    return;
}

/***************************************************************************************
void UltPartida ()
Entradas:
    Ninguna
    
Salidas:
    Ninguna
    
Objetivo:
    Lee todos los datos de la ultima partida en sus correspondientes ficheros para poder reproducirla
***************************************************************************************/

void UltPartida ()
{
    ifstream f, g, h;
    int np;
    int t, x, y, distancia;
    int t1, x1, y1, distancia1;
    int filas, columnas;
    MatrizEnteros disparos_usuario,disparos_ordenador;
    
    system("cls");
    
    f.open("confi.txt");
    if (!f)
        cout << "No se pudo abrir confi.txt" << endl;
    else
    {
        f >> filas;
        f >> columnas;
        
        g.open("ultima_partida.txt");
    
        if (!g)
            cout << "No se pudo abrir ultima_partida.txt" << endl;
        else
        {
            h.open("np.txt");
            if (!h)
                cout << "No se pudo abrir np.txt" << endl;
            else
            {
                h >> np;
                if (np == 0)
                    cout << "Lo inexistente no puede existir, juega alguna partida" << endl;
                else
                {
                    InicializarDisparos(disparos_ordenador, filas, columnas);
                    InicializarDisparos(disparos_usuario, filas, columnas);
                    while (g >> t)
                    {
                        g >> x;
                        g >> y;
                        g >> distancia;
                        g >> t1;
                        g >> x1;
                        g >> y1;
                        g >> distancia1;
                        disparos_usuario[x][y] = distancia;
                        disparos_ordenador[x1][y1] = distancia1;
                        VisualizarTableros(disparos_usuario, disparos_ordenador,filas,columnas);
                        
                        system("pause");
                        system("cls");
                    }
                }
            }
            h.close();
        }
        g.close();
    }
    f.close();
    
    return;
}

/***************************************************************************************
void EditarConf ()
Entradas:
    Ninguna
    
Salidas:
    Ninguna
    
Objetivo:
    Se llama a esta funcion en el caso de que quieras editar la configuracion de la partida, 
    asi que esta guarda en el fichero la nueva configuracion que deseas
***************************************************************************************/

void EditarConf ()
{
    ofstream f;
    Configuracion c = pedirConfiguracion();
    visualizarConfiguracion(c);
    
    f.open("confi.txt");
    
    if(!f)
        cout << "No se pudo abrir confi.txt" << endl;
    else
    {
        f << c.filas << endl;
        f << c.columnas << endl;
        f << c.barcos << endl;
    }
    
    f.close();
    
    return;
}

/***************************************************************************************
void visualizarConfiguracion(Configuracion res)
Entradas:
    Configuracion con la que estas jugando
    
Salidas:
    Ninguna
    
Objetivo:
    te enseña por pantala la Configuracion con la que estas jugando
***************************************************************************************/

void visualizarConfiguracion(Configuracion res)
{
    
    cout << "El numero de barcos con los que jugaras son: "; 
    cout << res.barcos << endl;
    cout << "Y el tamanyo del tablero es: " << res.filas;
    cout << "x" << res.columnas << endl;
    
    return;
}

/***************************************************************************************
Configuracion pedirConfiguracion()
Entradas:
    Ninguna
    
Salidas:
    La configuracion de la partida que le has introducido
    
Objetivo:
    te pide la configuracion con la que deseas ejecutar las partidas
***************************************************************************************/

Configuracion pedirConfiguracion()
{
    Configuracion pide;
    
    cout << "\nDame cuantas filas quieres: ";
    do
    {
        cin >> pide.filas;
        
        if (pide.filas < 5 || pide.filas > 20)
            cout << "Por favor, de una valor entre 5 y 20, ambos incluidos :D \n";
    }
    while (pide.filas < 5 || pide.filas > 20);
    
    cout << "Dame cuantas columnas quieres: ";
    do
    {
        cin >> pide.columnas;
        
        if (pide.columnas < 5 || pide.columnas > 20)
            cout << "Por favor, de una valor entre 5 y 20, ambos incluidos :D \n";
    }
    while (pide.columnas < 5 || pide.columnas > 20);
    
    cout << "Dame cuantos barcos quieres: ";
    cin >> pide.barcos;
    
    return pide;
    
}

/***************************************************************************************
void MostrarConf ()
Entradas:
    Ninguna
    
Salidas:
    Ninguna
    
Objetivo:
    lee del fichero la configuracion actual de la partida y la muestra por pantalla
***************************************************************************************/


void MostrarConf ()
{
    ifstream f;
    int filas, columnas, barcos;
    
    f.open("confi.txt");
    
    if(!f)
        cout << "No se pudo abrir confi.txt" << endl;
    else
    {
        f >> filas;
        f >> columnas;
        f >> barcos;
    }
    
    f.close();
    
    cout << "Los parametros actuales del juego son estos \n" << endl ;
    cout << "Numero de filas del tablero: " << filas << endl;
    cout << "Numero de columnas tablero: " << columnas << endl;
    cout << "Numero de barcos del tablero: " << barcos << endl;
    
    return;
}

/***************************************************************************************
void MostrarData ()
Entradas:
    Ninguna
    
Salidas:
    Ninguna
    
Objetivo:
    lee de los ficheros la informacion necesaria para las estadisticas de 
    las partidas registradas, las calcula y las muestra.
***************************************************************************************/

void MostrarData ()
{
    ifstream f, g;
    int i, partidas;
    int turnos, filas, columnas, barcos, victoria;
    float acc_victoria = 0, acc_derrota = 0, acc_turnosv = 0, acc_turnosp = 0;
    int minv = 200, maxv = 0;
    int minp = 200, maxp = 0;
    float acc_casillas = 0, acc_barcos = 0;
    
    f.open("historial_partidas.txt");
    
    if(!f)
        cout << "No se pudo abrir historial_partidas.txt" << endl;
    else
    {
        g.open("np.txt");
        if (!g)
            cout << "No se pudo abrir np.txt" << endl;
        else
        {
            g >> partidas;
            
            while (f >> i)
            {
                f >> turnos;
                f >> filas;
                f >> columnas;
                f >> barcos;
                f >> victoria;
                
                if (victoria == 1)
                {
                    acc_victoria ++;
                    acc_turnosv += turnos;
                    if (turnos > maxv)
                        maxv = turnos;
                    if (turnos < minv)
                        minv = turnos;
                }
                
                else 
                {
                   acc_derrota ++;
                    acc_turnosp += turnos;
                    if (turnos > maxp)
                        maxp = turnos;
                    if (turnos < minp)
                        minp = turnos; 
                }
                
                acc_casillas += filas * columnas;
                acc_barcos += barcos;
            }
            
            g.close(); 
        }
        
    }
    
    f.close();
    
    if (partidas != 0)
    {
        cout  << "Numero de partidas jugadas: " << partidas << endl;
        cout  << "Numero de partidas ganadas: " << acc_victoria << endl;
        cout  << "Numero de partidas perdidas: " << acc_derrota << endl;
        cout  << "Porcentaje de partidas ganadas: " << acc_victoria / partidas * 100;
        cout  << endl;
        
        if (acc_victoria == 0)
            cout << "No has ganado aun, mejora" << endl;
        else
        {
            cout  << "Media numero de turnos en partidas ganadas: "; 
            cout  << acc_turnosv / acc_victoria << endl;
            cout  << "Maximo numero de turnos en partidas ganadas: " << maxv << endl;
            cout  << "Minimo numero de turnos en partidas ganadas: " << minv << endl;
        }
        
        if (acc_derrota == 0)
            cout << "No has perdido aun, juega una partida mas" << endl;
        else
        {
            cout  << "Media numero de turnos en partidas perdidas: ";
            cout  << acc_turnosp / acc_derrota << endl;
            cout  << "Maximo numero de turnos en partidas perdidas: " << maxp << endl;
            cout  << "Minimo numero de turnos en partidas perdidas: " << minp << endl;
        }
        
        cout  << "Media del tamanyo del tablero (casillas): ";
        cout  << acc_casillas / partidas << endl;
        cout  << "Media de numeros de barcos: " << acc_barcos / partidas << endl;
    }
    
    else
        cout << "Lo inexistente no puede existir, juega alguna partida" << endl;
        
    return;
}