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
ofstream partida_escribir;
ifstream partida_leer;

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
typedef Disparo Vector[MAX_DISPARO];

struct Disparos
{
	Vector disparo;
	int n = 0;
};

struct Partida
{
	Configuracion usada;
	bool victoria;
    int boom ;
};

const int MAX_PARTIDAS = 1000;
typedef Partida Vector[MAX_PARTIDAS];

struct Partidas
{
    Vector historial;
    int n;
};

int PedirValorEnRango(int, int);
void InicializarDisparos(MatrizEnteros,int,int);
bool PosicionarBarcosAleatoriamente(MatrizBooleanos,int,int,int,int,int);
bool PedirPosicionesDeBarcos(MatrizBooleanos,int,int, int);
void VisualizarTableros(const MatrizEnteros,const MatrizEnteros,int,int);
void VisualizarPosicionBarcos(const MatrizBooleanos, const MatrizBooleanos,int,int);
bool ProcesarDisparo(int,int,const MatrizBooleanos,MatrizEnteros,int,int);

Configuracion generarConfiguracionPorDefecto();
Configuracion pedirConfiguracion();
void visualizarConfiguracion(Configuracion);

bool anyadirDisparo(Disparos&,Disparo);
void visualizarDisparos(Disparos);
void guardarDisparosEnFichero(Disparos);
Disparos leerDisparosDeFichero();

bool anyadirPartida(Partidas&,Partida);
void visualizarPartidas(Partidas);
void guardarPartidasEnFichero(Partidas);
Partidas leerPartidasDeFichero();

int main (void)
{
    MatrizBooleanos barcos_usuario,barcos_ordenador; // Nos declaramos dos matrices para almacenar las posiciones de los barcos
    MatrizEnteros disparos_usuario,disparos_ordenador; // Nos declaramos dos matrices para almacenar la información sobre los disparos efectuados
    int nfilas,ncolumnas; // para almacenar el tamaño del tablero
	int nbarcos,nmovimientos; // para almacenar el número de barcos y el número de jugadas realizadas
    int aciertos_usuario, aciertos_ordenador; // para anotar el número de aciertos de cada uno
    int fila, columna; 
    bool acierto;
    
    srand(time(NULL)); // para que cada vez sean distintos
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

	// Inicializamos variables
	aciertos_usuario=0;
	aciertos_ordenador=0;
	nmovimientos=0;
    
    // Introducimos los parámetros del juego:
	cout << "Introduzca el número de filas del tablero (max="<<N<<"):    ";
	nfilas=PedirValorEnRango(1, N);
	cout << "Introduzca el número de columnas del tablero (max="<<M<<"): ";
	ncolumnas=PedirValorEnRango(1, M);
	cout << "Introduzca el número de barcos (max="<<nfilas*ncolumnas/2<<"): ";
	cin >> nbarcos;

	InicializarDisparos(disparos_usuario,nfilas,ncolumnas);  // rellenamos la matriz disparos_usuario con valores -1
	InicializarDisparos(disparos_ordenador,nfilas,ncolumnas); // rellenamos la matriz disparos_ordenador con valores -1
	
    PosicionarBarcosAleatoriamente(barcos_ordenador,nfilas,ncolumnas, nbarcos,nfilas,ncolumnas); // ponemos barcos_ordenador a true donde están los barcos y a false donde hay agua. 
																				// La posición de los barcos se calcula aleatoriamente
																				
    PedirPosicionesDeBarcos(barcos_usuario,nfilas,ncolumnas,nbarcos); // ponemos barcos_usuario a true donde están los barcos y a false donde hay agua   
    																  // La posición de los barcos se solicita al usuario
    
    system("cls"); // borramos pantalla
	VisualizarPosicionBarcos(barcos_usuario,barcos_ordenador, nfilas,ncolumnas); // Se visualiza la posición de los barcos. Esto es solamente para depuración. Cuando se juegue
                                                                                 // de verdad esta línea debe desparecer.
		
    while (aciertos_usuario<nbarcos && aciertos_ordenador<nbarcos)   // Mientras no se acabe la partida
    {
        nmovimientos++; // se aumenta el número de disparos
		    
		// Turno del usuario. Preguntamos hasta que nos de una coordenada en la que no haya disparado antes
		do {
		   	cout << "Introduzca la fila del disparo (max="<<nfilas<<"): ";
	    	fila = PedirValorEnRango(1, nfilas);
	    	cout << "Introduzca la columna del disparo (max="<<ncolumnas<<"): ";
	    	columna = PedirValorEnRango(1, ncolumnas);
	    	fila--; // para poner el valor en el rango [0..nfilas-1]
	        columna--; // para poner el valor en el rango [0..ncolumnas-1]
	    	if (disparos_usuario[fila][columna]!=-1) // TO DO: COMPLETAR ESTA CONDICIÓN
	    	   cout << "Ahí ya había disparado anteriormente. Deme una nueva coordenada."<<endl;
	    } while (disparos_usuario[fila][columna]!=-1); // TO DO: COMPLETAR ESTA CONDICIÓN
	    
	    // Aquí sabemos que las coordenadas (fila,columna) son correctas, ya que hemos salido del while
	    acierto=ProcesarDisparo(fila,columna,barcos_ordenador,disparos_usuario,nfilas,ncolumnas); // se procesa el disparo, actualizando la matriz de disparos poniendo en la posición (fila,columna) 
	    																						  // la distancia al barco más cercano
	    if (acierto==true)  // Mostramos si se ha acertado o no
	    {
		   aciertos_usuario++;
		   cout << "BINGO!"<<endl;
		}  else
	         cout << "AGUA!"<<endl;
		
	       
	    
		// Turno del ordenador
	    if (aciertos_usuario<nbarcos) // Si no, la partida se ha acabado y no hay que dejar ya jugar al ordenador   
	    {
	    	do {
		  	 	fila = rand();
				fila = (fila % nfilas) + 1;	// Computar una coordenada para el disparo del ordenador, controlando que no hay tirado ya antes en esa casilla
				columna = rand();
				columna = (columna % ncolumnas) + 1;	// TO DO: Incluir el código necesario para generar la coordenada de disparo del ordenador, y ponerla en las variables fila y columna
	   		} while (disparos_ordenador[fila][columna]!=-1);
			
	        acierto=ProcesarDisparo(fila,columna,barcos_usuario,disparos_ordenador,nfilas,ncolumnas); // se procesa el disparo, actualizando la matriz de disparos poniendo en la posición (fila,columna) 
	    																						      // la distancia al barco más cercano
	    																						      
	        // borramos pantalla y volvemos a visualizar el estado del tablero
			system("cls");
	        VisualizarPosicionBarcos(barcos_usuario,barcos_ordenador, nfilas,ncolumnas); // Se visualiza la posición de los barcos. Esto es solamente para depuración. Cuando se juegue
                                                                                         // de verdad esta línea debe desparecer.
	        VisualizarTableros(disparos_usuario,disparos_ordenador,nfilas,ncolumnas);
		    
	        cout << "El ordenador ha disparado en fila " << fila+1 << ", columna " << columna+1 <<endl;
	        if (acierto==true)
	        {
		        aciertos_ordenador++;
		        cout << "BINGO!"<<endl;
	        } else
	            cout << "AGUA!"<<endl;
		    
		} else{
			// La partida ha acabado. Borramos pantalla y volvemos a visualizar el estado del tablero, preparando la salida del bucle principal
	        system("cls");
	        VisualizarPosicionBarcos(barcos_usuario,barcos_ordenador, nfilas,ncolumnas); // Se visualiza la posición de los barcos. Esto es solamente para depuración.
                                                                                 //  Cuando se juegue de verdad esta línea debe desparecer.
		    VisualizarTableros(disparos_usuario,disparos_ordenador,nfilas,ncolumnas);
		}
	    
    } // fin del bucle principal
	
	if (aciertos_usuario==nbarcos)
        cout << "Enhorabuena, has ganado la partida con " << nmovimientos << " disparos " << endl;
    else    
       cout << "Vaya, el ordenador ha conseguido vencerte con " << nmovimientos << " disparos " <<  endl;
    return 0;
    system("pause");
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
	for (i=0;i<filas;i++)
	  for (j=0;j<columnas;j++)
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
        	        cout << "dame la fila donde quieras que se ubice tu barco: " << i+1 << ": ";
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
bool ProcesarDisparo(int fila_disparo, int columna_disparo,const MatrizBooleanos barcos,MatrizEnteros disparos,int nfilas,int ncolumnas)
{
    bool resultado;
    int i,j;
	int minimaDistancia=nfilas+ncolumnas+1;  
	int distancia;
	
	if (barcos[fila_disparo][columna_disparo]==true) // Si el disparo ha sido certero
	{
	  resultado=true;
	  disparos[fila_disparo][columna_disparo]=0;
    }
	else // el disparo ha ido al agua
	{
		resultado=false;	
	  
		for (i=0;i<nfilas;i++)
	    	for (j=0;j<ncolumnas;j++)
	    		if (barcos[i][j]==true) 
	        	{
	            	distancia=abs(fila_disparo-i)+abs(columna_disparo-j);  
	            	if (distancia<minimaDistancia) 
	                minimaDistancia=distancia; 
		    	}  
	  disparos[fila_disparo][columna_disparo]=minimaDistancia;	// TO DO: COMPLETAR ESTA PARTE DEL PROGRAMA
    }
    return resultado;  
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
 
	// Lo primero las cabeceras
	cout << "BARCOS USUARIO ";
	for (i=0;i<columnas-6;i++)
	   cout <<" ";
	cout << " BARCOS ORDENADOR" <<endl;
	
	
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
    cout << endl; // la primera fila ya está completa
    
    
	// Primera fila de guiones: dos espacios, columnas+2 guiones, 6 espacios de separación y otras columnas+2 guiones (el +2 es para los bordes, y los dos espacios 
	// es para dejar el hueco correspondiente a los números de las filas en la visualización de la matriz)
    cout <<"  "; // dos espacios
	for (i=0;i<columnas+2;i++)	// columnas+2 guiones 
      cout <<"-";
      
	cout <<"      "; // 6 espacios
    
    for (i=0;i<columnas+2;i++)	// columnas+2 guiones
      cout <<"-";
    
    cout << endl;
    
    // vamos con las filas
    for (i=0;i<filas;i++) // para cada fila	
    {
       // primero el número de fila de la primera matriz
	   if (i<9) // para mantener la estética, cuando el número a mostrar tiene una cifra, le ponemos un espacio delante
         cout << " " << i+1;
       else
	     if (i<99) 
		    cout << i+1;
		 else  // si tiene más de dos cifras, reemplazamos el número por ..
		    cout << "..";	 
	   cout << "|"; 	// Después ponemos una barra vertical (el borde izquierdo de la primera matriz)
	   for (j=0;j<columnas;j++)	// recorremos toda la fila i de la primera matriz y mostramos una x o un espacio, dependiendo de si es true o false
	   {
	   	   if (m1[i][j]==true)
	   	     cout << "x";
	   	   else
	   	     cout << " ";
	   }
       cout << "|"; 	// El borde derecho de la primera matriz
	   cout <<"    ";   // los espacios de separación
	   // mostramos el número de fila de la segunda matriz
	   if (i<9)
         cout << " " << i+1;
       else
	     if (i<99)
		    cout << i+1;
		 else 
		    cout << ".."; 
       cout << "|"; 	// El borde izquierdo de la segunda matriz
       for (j=0;j<columnas;j++)	// recorremos toda la fila i de la segunda matriz y mostramos una x o un espacio, dependiendo de si es true o false
	   {
	   	   if (m2[i][j]==true)
	   	     cout << "x";
	   	   else
	   	     cout << " ";
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
void VisualizarTableros(const MatrizEnteros m1, const MatrizEnteros m2, int filas, int columnas)
Entradas:
    
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
    cout << endl; // la primera fila ya está completa
    
    
	// Primera fila de guiones: dos espacios, columnas+2 guiones, 6 espacios de separación y otras columnas+2 guiones (el +2 es para los bordes, y los dos espacios 
	// es para dejar el hueco correspondiente a los números de las filas en la visualización de la matriz)
    cout <<"  "; // dos espacios
	for (i=0;i<columnas+2;i++)	// columnas+2 guiones 
      cout <<"-";
      
	cout <<"      "; // 6 espacios
    
    for (i=0;i<columnas+2;i++)	// columnas+2 guiones
      cout <<"-";
    
    cout << endl;
    
    // vamos con las filas
    for (i=0;i<filas;i++) // para cada fila	
    {
       // primero el número de fila de la primera matriz
	   if (i<9) // para mantener la estética, cuando el número a mostrar tiene una cifra, le ponemos un espacio delante
         cout << " " << i+1;
       else
	     if (i<99) 
		    cout << i+1;
		 else  // si tiene más de dos cifras, reemplazamos el número por ..
		    cout << "..";	 
	   cout << "|"; 	// Después ponemos una barra vertical (el borde izquierdo de la primera matriz)
	   for (j=0;j<columnas;j++)	// recorremos toda la fila i de la primera matriz y mostramos una x o un espacio, dependiendo de si es true o false
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
	   // mostramos el número de fila de la segunda matriz
	   if (i<9)
         cout << " " << i+1;
       else
	     if (i<99)
		    cout << i+1;
		 else 
		    cout << ".."; 
       cout << "|"; 	// El borde izquierdo de la segunda matriz
       for (j=0;j<columnas;j++)	// recorremos toda la fila i de la segunda matriz y mostramos una x o un espacio, dependiendo de si es true o false
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

int main (void)
{
    Configuracion c;
    // Establecer el idioma a español
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    
    c = generarConfiguracionPorDefecto();
    cout << "Las opciones por defecto son: " << endl;
    visualizarConfiguracion(c);
    c = pedirConfiguracion();
    cout << "\nLas opciones introducidas por el usuario son: " << endl;
    visualizarConfiguracion(c);
    return 0;
    
}

Configuracion generarConfiguracionPorDefecto()
{
    Configuracion inic;
    
    inic.filas = 10;
    inic.columnas = 10;
    inic.barcos = 3;
    
    return inic;
}

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

void visualizarConfiguracion(Configuracion res)
{
    
    cout << "El numero de barcos con los que jugaras son: "; 
    cout << res.barcos << endl;
    cout << "Y el tamanyo del tablero es: " << res.filas;
    cout << "x" << res.columnas << endl;
    
    return;
}

int main ()
{
	Disparos D;
	Disparo d;
	
	d.x=1;
	d.y=3;
	d.distancia=4;
	
	anyadirDisparo (D,d);
	visualizarDisparos (D);
	guardarDisparosEnFichero (D);
	D=leerDisparosDeFichero();
	visualizarDisparos (D);
	
	return 0;
}

bool anyadirDisparo(Disparos& D, Disparo d)
{
	bool max;

	D.disparo[D.n].x = d.x;
	D.disparo[D.n].y = d.y;
	D.disparo[D.n].distancia = d.distancia;
	D.n ++;
	
	if(D.n <= MAX_DISPARO)
		max = true;
	else
		max = false;
	
	return(max);
}

void visualizarDisparos(Disparos D)
{
	int i;
	
	for(i=0; i<D.n; i++)
	{
		cout<< "Tiene Coordenada x: " << D.disparo[i].x << ", coordenada y: " << D.disparo[i].y << ", y una distancia: " << D.disparo[i].distancia << endl;
	}
	
	return;
}

void guardarDisparosEnFichero(Disparos D)
{
	int i;
	
	partida_escribir.open("ultima_partida.txt");
	if (!partida_escribir)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_escribir << D.n << endl;
		
		for(i=0; i<D.n; i++)
		{
			partida_escribir << D.disparo[i].x << " " << D.disparo[i].y << " " << D.disparo[i].distancia << endl;
		}
	}
}

Disparos leerDisparosDeFichero()
{
	Disparos D;
	int i;
	
	partida_leer.open("ultima_partida.txt");
	if (!partida_leer)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_leer >> D.n;

		
		for(i=0; i<D.n; i++)
		{
			partida_leer >> D.disparo[i].x >> D.disparo[i].y >> D.disparo[i].distancia ;
		}
	}
	
	return (D);
}

int main ()
{
	Partidas parts;
	Partida part;
	
    parts.n = 0;
    
    part.usada.columnas = 5;
    part.usada.barcos = 10;
	part.boom = 12;
    part.victoria = false;
	
	anyadirPartida (parts,part);
	visualizarPartidas (parts);
	guardarPartidasEnFichero (parts);
	parts = leerPartidasDeFichero();
	visualizarPartidas (parts);
            
}

bool anyadirPartida(Partidas& parts, Partida part)
{
	bool max;
    
    parts.historial[parts.n].usada.filas = part.usada.filas;
    parts.historial[parts.n].usada.columnas = part.usada.columnas;
    parts.historial[parts.n].usada.barcos = part.usada.barcos;
    parts.historial[parts.n].victoria = part.victoria;
    parts.historial[parts.n].boom = part.boom;
    parts.n ++;
    
	if(parts.n <= MAX_PARTIDAS)                  
		max = true;
	else
		max = false;
	
	return(max);
}

void visualizarPartidas(Partidas parts)
{
	int i;
	
	for(i = 0; i < parts.n; i++)
	{
		cout<< "La configuracion de la partida " << parts.n << " fue: "; 
        cout << parts.historial[i].usada.filas << " x " << parts.historial[i].usada.columnas;
        cout << ", y un total de barcos de: " << parts.historial[i].usada.barcos << endl;
        
        if (parts.historial[i].victoria)
            cout << "El usuario gano la partida" << endl;
        else
            cout << "El usuario perdio la partida" << endl;
            
        cout << "El usuario disparo: " << parts.historial[i].boom << " veces \n";
	}
	
	return;
}

void guardarPartidasEnFichero(Partidas parts)
{
	int i;
	
	partida_escribir.open("info_partidas.txt", ios::app);
	if (!partida_escribir)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_escribir << parts.n << endl;
		
		for(i = 0; i < parts.n; i++)
		{
			partida_escribir << parts.historial[i].usada.filas << " " << parts.historial[i].usada.columnas;
            partida_escribir << " " << parts.historial[i].usada.barcos << " ";
            partida_escribir << parts.historial[i].boom << " ";
            
            if (parts.historial[i].victoria)
                partida_escribir << 1 << " " << endl;
            else 
                partida_escribir << 0 << " " << endl;
            
		}
	}
}

Partidas leerPartidasDeFichero()
{
	Partidas parts;
	int i;
	
	partida_leer.open("info_partidas.txt", ios::app);
	if (!partida_leer)
		cout << "No se pudo abrir el fichero de entrada\n";
	else
	{
		partida_leer >> parts.n;

		
		for(i = 0; i < parts.n; i++)
		{
			partida_leer >> parts.historial[i].usada.filas >> parts.historial[i].usada.columnas;
            partida_leer >> parts.historial[i].usada.columnas >> parts.historial[i].boom;
            partida_leer >> parts.historial[i].victoria;
		}
	}
	
	return parts;
}