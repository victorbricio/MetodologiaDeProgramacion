#include "tablero.h"
#include <iostream>
#include <fstream>

using namespace std;
struct CeldaPosicion {
	int filas;
	int columnas;
	CeldaPosicion *siguiente;
};

class Campominas{
private:

Tablero tablero;

int NumeroBombas (const int& filas, const int& columnas);

public:

Campominas (const int& bomba, const int& fila, const int& columna);

int Filas ();

int Columnas ();

bool MinaExplosion ();

bool PartidaGanada ();

bool MarcarCasilla (const int& i, const int& j);

bool AbrirCasilla (const int& i, const int& j);

bool SalvarTablero(const char nombre[100]);
    
bool LeerTablero(const char nombre[100]);

bool Imprime(std::ostream& os);

bool ImprimeTrampas(std::ostream& os);

};
