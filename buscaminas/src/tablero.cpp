#include "tablero.h"
#include <iostream>


	Tablero::Tablero (const int& fila, const int& columna){
		filas = fila;
		columnas = columna;

		tablero = new Casilla[filas * columnas];
		
	}

	Tablero::Tablero(const Tablero& tablero_copia){
		filas = tablero_copia.filas;
		columnas = tablero_copia.columnas;

		tablero = new Casilla[filas * columnas];
		

		for (int i = 0; i < filas; i++)
			for (int j = 0; j < columnas; j++)
				tablero[i * columnas + j] = tablero_copia(i,j);
	}

	int Tablero::Filas () const{
		return filas;
	}
	
	int Tablero::Columnas () const{
		return columnas;
	}

	Casilla Tablero::operator() (const int fila, const int columna) const{
		return tablero[fila * columnas + columna];
	}

	Tablero Tablero::operator= (const Tablero& t) {
		filas = t.filas;
		columnas = t.columnas;

		tablero = new Casilla[filas * columnas];

		for (int i = 0; i < filas; i++)
			for (int j = 0; j < columnas; j++)
				this->tablero[i * columnas + j] = t.tablero[i * columnas + j];

		return t;
	}
	
	Casilla Tablero::Elemento (const int& fila, const int& columna) const{
		Casilla error;
		error.bomba = false;
		error.abierta = false;
		error.marcada = false;

		if ((fila < Filas()) && (fila >= 0) && (columna < Columnas()) && (columna >= 0))
			return tablero[fila * columnas + columna];
		else 
			return error;
	}

	bool Tablero::Modificar (const int& fila, const int& columna, const Casilla& nueva) {
		if ((fila < Filas()) && (fila >= 0) && (columna < Columnas()) && (columna >= 0)){		
			tablero[fila * columnas + columna] = nueva;
				return true;
		}
		else
			return false;
	}

	Tablero::~Tablero(){
		delete[] tablero;
	}

	std::ostream& operator<<(std::ostream &os, const Casilla &casilla){
		os << casilla.abierta << "\n";
		os << casilla.marcada << "\n";
		os << casilla.bomba << "\n";
		return os;
	}

	std::ostream& operator<<(std::ostream &os, const Tablero &tablero){
		os << tablero.Filas() << "\n";
		os << tablero.Columnas() << "\n";
		for(int i = 0; i < tablero.Filas(); i++)
			for(int j = 0; j < tablero.Columnas(); j++)
				os << tablero(i,j);
		return os;
	}


