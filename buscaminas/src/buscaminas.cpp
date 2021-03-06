#include "campominas.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool AnalizarComando(char *texto, Campominas &campominas){
  char *palabras[100];
  int i = 0;
  palabras[0] = texto;
  int contador = 1;
  while(texto[i] != '\0'){
    texto[i] = tolower(texto[i]);
    if(isspace(texto[i])){
      palabras[contador]= texto+i+1;
      texto[i] = '\0';
      contador++;
    }
    i++;
  }

  if(strcmp(palabras[0],"a") == 0 || strcmp(palabras[0],"abrir") == 0){
    campominas.AbrirCasilla(atoi(palabras[1]),atoi(palabras[2]));
    campominas.Imprime(cout);
}
  else if(strcmp(palabras[0],"m") == 0 || strcmp(palabras[0],"marcar") == 0){
    campominas.MarcarCasilla(atoi(palabras[1]),atoi(palabras[2]));
    campominas.Imprime(cout);
}
  else if(strcmp(palabras[0],"s") == 0 || strcmp(palabras[0],"salvar") == 0){
    campominas.SalvarTablero(palabras[1]);
  }
  else if(strcmp(palabras[0],"e") == 0 || strcmp(palabras[0],"exit") == 0){
    return false;
  }
  else{
    cout << "Error, introduzca la orden de nuevo!\n";
    return true;
  }
  return true;
}


int main(int argc, char *argv[]) {

	srand (time(NULL));

	int filas, columnas, bombas;
	char accion[100];
    Campominas campominas (1, 1, 1);

    if(argc==4){
        filas = atoi(argv[1]);
        columnas = atoi(argv[2]);
        bombas = atoi(argv[3]);

        if (filas >= 4 && columnas >= 4 && 0 < bombas && bombas < columnas*filas/2){
            Campominas tablero (bombas, filas, columnas);
            campominas = tablero;
        }
        else{
          cout << "Has puesto muy pocas filas y /o columnas (debe haber al menos 4) o has puesto muchas bombas" << endl;
          return 0;
          }
    }

    else if(argc==2){
        campominas.LeerTablero(argv[1]);
    }
    else{
        cout << "Introduzca 3 parámetros (filas, columnas, bombas) o un parámetro (nombre de la partida guardada)(a parte del comando de ejecucion)" << endl;
        return 0;
    }

	campominas.Imprime(cout);

	while(!campominas.PartidaGanada() && !campominas.MinaExplosion()){
		cout << "Introduzca una accion ('m', 'a', 's', 'e') y sus parámetros: \n	a abre una casilla: tiene 3 parámetros(a,fila,columna) \n	m marca una casilla: tiene 3 parámetros(m,fila,columna) \n	s salva la partida: tiene 2 parámetros(s,nombre del archivo donde se va a guardar la partida) \n        e para salir" << endl;
		cin.getline(accion,100);
		if (!AnalizarComando(accion, campominas))
      return 0;

	if (campominas.MinaExplosion()){
		cout << endl << "Perdiste la partida ;(" << endl;
		campominas.ImprimeTrampas(cout);
		cout << endl;
	}

	if (campominas.PartidaGanada())
		cout << endl <<  "¡¡Ganaste!! ;)" << endl;
	}
}
