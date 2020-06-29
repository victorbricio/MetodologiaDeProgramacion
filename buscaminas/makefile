CXX= g++
INC= includes/
CXXFLAGS= -Wall -I$(INC)
SRC= src/
OBJ= obj/
BIN= ejecutables/

all: buscaminas

$(OBJ)tablero.o : $(INC)tablero.h $(SRC)tablero.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)tablero.o $(SRC)tablero.cpp

$(OBJ)campominas.o: $(SRC)campominas.cpp $(INC)campominas.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)campominas.o $(SRC)campominas.cpp

buscaminas: $(SRC)buscaminas.cpp  $(OBJ)campominas.o $(OBJ)tablero.o
	$(CXX) $(CXXFLAGS) $(OBJ)campominas.o $(OBJ)tablero.o -o $(BIN)buscaminas $(SRC)buscaminas.cpp

clean:
	echo "Limpiando . . ."
	rm $(OBJ)*.o 

