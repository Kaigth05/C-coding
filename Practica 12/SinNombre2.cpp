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
	bool victoria;
    Disparos disps;
};

const int MAX_PARTIDAS = 1000;
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
bool ProcesarDisparo(int,int,const MatrizBooleanos,MatrizEnteros,int,int);

Configuracion generarConfiguracionPorDefecto();
Configuracion pedirConfiguracion();

void visualizarDisparos(Disparos);
void guardarDisparosEnFichero(Disparos);
Disparos leerDisparosDeFichero();

bool anyadirPartida(Partidas&,Partida);
void visualizarPartidas(Partidas);
void guardarPartidasEnFichero(Partidas);
Partidas leerPartidasDeFichero();

Partida JugarPartida();
void JugarPartidaDep();
void UltPartida ();
Configuracion EditarConf ();
void MostrarConf (Partida);
void MostrarData ();
int LeerNp();
void GuardarNp(Partidas);

int main
{
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    
    int num;
    Partida game;
    Partidas games;
    
    games.np = LeerNp ();
    do
    {
        cout << "Introduzca la opcion que prefiera";
        
        cout << "1.- Jugar partida\n";
        cout << "2.- Jugar en modo depuracion\n";
        cout << "3.- Reproducir última partida\n";
        cout << "4.- Editar la configuracion del juego\n";
        cout << "5.- Mostrar la configuracion del juego\n";
        cout << "6.- Mostrar estadisticas\n";
        cout << "7.- Salir del juego\n";
        
        switch num
        {
            case 1 :
                games.historial[games.np] = JugarPartida();
                guardarPartidasEnFichero(games);
                games.np ++;
                break;
            case 2 :
                JugarPartidaDep();
                break;
            case 3 :
                UltPartida (game);
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
                GuardarNp (Partidas);
                break;
            default :
                cout << "Introduzca otro valor\n";
        }

    }
    while (num != 7);
    
    system ("pause");
    
    return 0;
}

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

void MostrarNp (games)
{
    ofstream f;
    
    f.open("np.txt");
    if (!f)
        cout << "No se pudo abrir np.txt" << endl;
    else
    {
        f << games.np;
        f.close();
    }
    
    return 0;
}

Partida JugarPartida()
{
    Partida game;
    MatrizBooleanos barcos_usuario,barcos_ordenador; // Nos declaramos dos matrices para almacenar las posiciones de los barcos
    MatrizEnteros disparos_usuario,disparos_ordenador; // Nos declaramos dos matrices para almacenar la información sobre los disparos efectuados
	int nmovimientos; // para almacenar el número de barcos y el número de jugadas realizadas
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
    
    game.usada = generarConfiguracionPorDefecto();
    
    cout <<
    
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
	        if (acierto == true)
	        {
		        aciertos_ordenador++;
		        cout << "BINGO!"<<endl;
	        } else
	            cout << "AGUA!"<<endl;
		    
		} else{
			// La partida ha acabado. Borramos pantalla y volvemos a visualizar el estado del tablero, preparando la salida del bucle principal
	        system("cls");
		    VisualizarTableros(disparos_usuario,disparos_ordenador,nfilas,ncolumnas);
		}
	    
    } // fin del bucle principal
	
	if (aciertos_usuario == nbarcos)
        cout << "Enhorabuena, has ganado la partida con " << nmovimientos << " disparos " << endl;
    else    
       cout << "Vaya, el ordenador ha conseguido vencerte con " << nmovimientos << " disparos " <<  endl;
    return 0;
}

void JugarPartidaDep()
{
    Partida game;
    MatrizBooleanos barcos_usuario,barcos_ordenador; // Nos declaramos dos matrices para almacenar las posiciones de los barcos
    MatrizEnteros disparos_usuario,disparos_ordenador; // Nos declaramos dos matrices para almacenar la información sobre los disparos efectuados
	int nmovimientos; // para almacenar el número de barcos y el número de jugadas realizadas
    int aciertos_usuario, aciertos_ordenador; // para anotar el número de aciertos de cada uno
    int fila, columna;
    int menu; 
    bool acierto;
    
    srand(time(NULL)); // para que cada vez sean distintos
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

	// Inicializamos variables
	aciertos_usuario=0;
	aciertos_ordenador=0;
	nmovimientos=0;

	InicializarDisparos(disparos_usuario,game.usada.filas,game.usada.columnas);  // rellenamos la matriz disparos_usuario con valores -1
	InicializarDisparos(disparos_ordenador,game.usada.filas,game.usada.columnas); // rellenamos la matriz disparos_ordenador con valores -1
	
    PosicionarBarcosAleatoriamente(barcos_ordenador,game.usada.filas,game.usada.columnas, game.usada.barcos, game.usada.filas,game.usada.columnas); // ponemos barcos_ordenador a true donde están los barcos y a false donde hay agua. 
																				// La posición de los barcos se calcula aleatoriamente
																				
    PedirPosicionesDeBarcos(barcos_usuario,nfilas,ncolumnas,nbarcos); // ponemos barcos_usuario a true donde están los barcos y a false donde hay agua   
    																  // La posición de los barcos se solicita al usuario
    
    system("cls"); // borramos pantalla
	VisualizarPosicionBarcos(barcos_usuario,barcos_ordenador, nfilas,ncolumnas); // Se visualiza la posición de los barcos. Esto es solamente para depuración. Cuando se juegue
                                                                                 // de verdad esta línea debe desparecer.
		
    while (aciertos_usuario<nbarcos && aciertos_ordenador<nbarcos)   // Mientras no se acabe la partida
    {
        game.turnos++; // se aumenta el número de disparos
		    
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
	        if (acierto == true)
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
	
	if (aciertos_usuario == nbarcos)
        cout << "Enhorabuena, has ganado la partida con " << nmovimientos << " disparos " << endl;
    else    
       cout << "Vaya, el ordenador ha conseguido vencerte con " << nmovimientos << " disparos " <<  endl;
    return 0;
}

void UltPartida ()
{
    ifstream f, g;
    int i, n, t;
    int filas, barcos;
    MatrizBooleanos m1, m2;
    
    g.open("confi.txt")
    if (!f)
        cout << "No se pudo abrir confi.txt" << endl;
    else
    {
        g >> filas;
        g >> columnas;
        
        f.open("ultima_partida.txt");
    
        if (!f)
            cout << "No se pudo abrir ultima_partida.txt" << endl;
        else
        {
            f >> t;
            for (i = 0; i < t; i++)
                f >> x;
                f >> y;
                f >> distancia;
                VisualizarTableros2(m1, m2, filas, columnas);
                system("pause");
        }
        
        f.close();
    }
    
    g.close();
    
    return 0;
    
}

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
    
    return 0;
}

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
    
    cout << "Hay " << 
    
    return 0;
}