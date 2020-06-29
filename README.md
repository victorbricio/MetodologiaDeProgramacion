# MetodologiaDeProgramacion

Para compilar utilizar el makefile:

	- Si se añade algo al código hacer make clean.
	- Y después make all

Para ejecutar el programa, entrar en la terminal y ejecutar el archivo que hay en /ejecutables con './', el ejecutable se llama buscaminas.
Después de esto añadir los tres parámetros siguientes: número de filas, número de columnas y número de bombas.
Hay que poner más de 3 filas y más de 3 columnas, además debe haber menos bombas que la mitad de todas las casillas del tablero.
En caso de no cumplir estas condiciones el programa se quejará por la condición que no se haya cumplido y se cerrará.

Opciones después de ejecutar el programa:

	- a/abrir fila columna: abrir la casilla con las coordenadas indicadas.
	- m/marcar fila columna: marcar la casilla con las coordenadas indicadas como posible mina.
	- s/salvar archivo: guarda la partida actual en el archivo indicado (este archivo aparecerá al nivel del makefila, NO MOVERLO)
		Para reabrir la partida guardada ejecutar de forma normal, peroen lugar de poner como parámetros número de filas, número de columnas y número de 		 bombas, se debe poner el nombre del archivo en el que está guardad la partida.
	-e/exit: cierra el programa.
