#include "campominas.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


	Campominas::Campominas (const int& bomba, const int& fila, const int& columna):
		tablero(fila, columna)
	{
		for (int i = 0; i < fila; i++){
			for (int j = 0; j < columna; j++){
				Casilla Vacia = tablero.Elemento(i,j);
				Vacia.bomba = false;
				Vacia.abierta = false;
				Vacia.marcada = false;

				tablero.Modificar(i,j,Vacia);
			}
		}
		// Generación de las minas en tablero.

		int b = 0;

		while(b < bomba){
			int i = rand()%fila;
			int j = rand()%columna;

			if (!tablero.Elemento(i,j).bomba){
				Casilla Bomba = tablero.Elemento(i,j);

				Bomba.bomba = true;
				Bomba.abierta = tablero.Elemento(i,j).abierta;
				Bomba.marcada = tablero.Elemento(i,j).marcada;

				tablero.Modificar(i,j,Bomba);
				b++;
			}
		}
}

	int Campominas::Filas (){
		return tablero.Filas();
	}

	int Campominas::Columnas (){
		return tablero.Columnas();
	}

	bool Campominas::MinaExplosion (){
		for (int i = 0; i < tablero.Filas(); i++){
			for (int j = 0; j < tablero.Columnas(); j++){
				if (tablero.Elemento(i,j).bomba && tablero.Elemento(i,j).abierta)
					return true;
				}
			}
		return false;
	}

	bool Campominas::PartidaGanada (){
		if (!MinaExplosion()){
			for (int i = 0; i < tablero.Filas(); i++){
				for (int j = 0; j < tablero.Columnas(); j++){
					if(!(tablero.Elemento(i,j).abierta || tablero.Elemento(i,j).bomba))
						return false;
				}
			}
			return true;
		}
		return false;
	}

	bool Campominas::MarcarCasilla (const int& i, const int& j){
			if (!tablero(i,j).abierta){
				if (tablero(i,j).marcada){
					Casilla marcada = tablero(i,j);
					marcada.marcada = false;

					tablero.Modificar(i,j,marcada);
				}
				else{
					Casilla marcada = tablero(i,j);
					marcada.marcada = true;

					tablero.Modificar(i,j,marcada);
				}
			return true;
			}
		return false;
	}

	bool Campominas::AbrirCasilla (const int& fila, const int& columna){
			CeldaPosicion *pend = new CeldaPosicion;
			pend->filas = fila;
			pend->columnas = columna;
			pend->siguiente = NULL;

			while(pend != NULL){
				int fil = pend->filas;
				int col = pend->columnas;

				if (tablero.Elemento(fil,col).marcada)
					return false;

				Casilla abierta = tablero.Elemento(fil,col);
				abierta.abierta = true;
				tablero.Modificar(fil,col,abierta);

				CeldaPosicion *auxiliar = pend;
				pend = pend->siguiente;
				delete auxiliar;

				if(NumeroBombas(fil,col) == 0){
					for (int i = fil - 1; i <= fil + 1; i++){
						for (int j = col - 1; j <= col + 1; j++){
							if ((i >= 0) && (i < tablero.Filas()) && (j >= 0) && (j < tablero.Columnas())){
							if (!(tablero.Elemento(i,j).abierta || tablero.Elemento(i,j).marcada)){
								CeldaPosicion *auxiliar = new CeldaPosicion;
								auxiliar->filas = i;
								auxiliar->columnas = j;
								auxiliar->siguiente = pend;
								pend = auxiliar;
							}
							}
					}
				}
			}
		}
		return true;
	}

	int Campominas::NumeroBombas(const int& nfilas, const int& ncolumnas){
		int nbombas = 0;
		for (int i = nfilas - 1; i <= nfilas + 1; i++){
			for (int j = ncolumnas - 1; j <= ncolumnas + 1; j++){
				if ((nfilas >= 0) && (nfilas < tablero.Filas()) && (ncolumnas >= 0) && (ncolumnas < tablero.Columnas())){
				if (!(i == nfilas && j == ncolumnas)){
					if (tablero.Elemento(i,j).bomba)
						nbombas++;
					}
				}
			}
		}
		return nbombas;
	}

    bool Campominas::SalvarTablero(const char nombre[100]){
        ofstream f(nombre, ios::out);
        f<< "#MP−BUSCAMINAS−V1" << endl;
        f<<tablero;
        f.close();
        return true;
    }

    bool Campominas::LeerTablero(const char nombre[100]){

	ifstream f(nombre, ios::in);
        if(f){
	    int filas, columnas;
            char basura[100];
            Casilla casilla_copia;
            f>>basura;
            f>>filas;
            f>>columnas;
            Tablero tablero_copia(filas, columnas);
            for(int fila = 0; fila < filas; fila++){
                for (int columna = 0; columna < columnas; columna ++) {
                    f>>casilla_copia.abierta;
                    f>>casilla_copia.marcada;
                    f>>casilla_copia.bomba;
                    tablero_copia.Modificar(fila,columna, casilla_copia);
                }
            }
            f.close();
            tablero = tablero_copia;
        }
        return true;
    }

	bool Campominas::Imprime (ostream& os=cout){
		for (int i = 0; i < tablero.Columnas(); i++){
			if (i==0)
			  os << "   ";
		 	if(i<10)
				os << i << "  ";
			else
				os << i <<" ";
		}
		os << endl;
		for (int i = 0; i < tablero.Columnas(); i++){
			if (i==0)
				os << "  -";
			os << "---";
		}
		for (int i = 0; i < tablero.Filas(); i++){
			os << endl;
			if(i<10)
				os << i << " |";
			else{
				os << i <<"|";
			}

				for (int j = 0; j < tablero.Columnas(); j++){

					if (tablero.Elemento(i,j).marcada)
						os << "? |";

					else if (!tablero.Elemento(i,j).abierta)
						os << "* |";

					else if (tablero.Elemento(i,j).bomba)
						os << "X |";

					else if (NumeroBombas(i,j) == 0)
						os << "  |";

					else
						os << NumeroBombas(i,j) << " |";
				}
			}
		os << endl;
		for (int i = 0; i < tablero.Columnas(); i++){
			if (i==0)
				os << "  -";
			os << "---";
		}
		os << endl;
	return true;
	}

	bool Campominas::ImprimeTrampas (ostream& os=cout) {
		for (int i = 0; i < tablero.Columnas(); i++){
			if (i==0)
			  os << "   ";
		 	if(i<10)
				os << i << "  ";
			else
				os << i <<" ";
		}
		os << endl;
		for (int i = 0; i < tablero.Columnas(); i++){
			if (i==0){
				os << "  -";
				os << "---";
			}
		}
		for (int i = 0; i < tablero.Filas(); i++){
			os << endl;
			if(i<10)
				os << i << " |";
			else{
				os << i <<"|";
			}
			
				for (int j = 0; j < tablero.Columnas(); j++){
					if (tablero.Elemento(i,j).marcada)
						os << "? |";

					else if (tablero.Elemento(i,j).bomba)
						os << "X |";

					else if (NumeroBombas(i,j) == 0 && tablero(i,j).abierta)
						os << "  |";

					else if (tablero.Elemento(i,j).abierta)
						os << NumeroBombas(i,j) << " |";

					else
						os << "*" << " |";
			}
		}
		os << endl;

		for (int i = 0; i < tablero.Columnas(); i++){
			if (i==0)
				os << "  -";
			os << "---";
		}
		os << endl;
	return true;
	}
