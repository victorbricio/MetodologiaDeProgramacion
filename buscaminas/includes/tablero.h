#include <fstream>

struct Casilla {
	bool abierta;
	bool marcada;
    	bool bomba;
};

class Tablero {

private:

Casilla *tablero;
int filas, columnas;

public:

Tablero (const int& fila, const int& columna);

Tablero (const Tablero&);

int Filas() const;

int Columnas() const;

Casilla operator() (const int fila, const int columna) const;

Tablero operator= (const Tablero& t);

Casilla Elemento (const int& fila, const int& columna) const;

bool Modificar (const int& fila, const int& columna, const Casilla& nueva);

~Tablero();

};

std::ostream& operator<<(std::ostream& os, const Casilla& casilla);

std::ostream& operator<<(std::ostream &os, const Tablero &tablero_actual);

