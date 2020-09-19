/*
 ============================================================================
 Name        : TP1.c
 Author      : Alain Vega y Mathias Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM_CIUDAD 2

// TODO: Cambiar valores de variables despues (capacidad de los vectores principalmente)
void OcuparEspacios(int antenas[3][4], char ciudad[TAM_CIUDAD][TAM_CIUDAD]) {
	int i, j, k, fila, columna, potencia, direccion, direccion_fila, direccion_columna;
	// NOTA: Poner la capacidad de rebasar la matriz despues, imprimiendo un mensaje si pasa.
	for (i = 0; i < 3; i++) { // Recorrer el array de antenas
		fila = antenas[i][0];
		columna = antenas[i][1];
		direccion = antenas[i][2];
		potencia = antenas[i][3];
		switch (direccion) {
			case 0:
				direccion_fila = 1;
				direccion_columna = -1;
				break;
			case 1:
				direccion_fila = 1;
				direccion_columna = 1;
				break;
			case 2:
				direccion_fila = -1;
				direccion_columna = 1;
				break;
			case 3:
				direccion_fila = -1;
				direccion_columna = -1;
				break;
		}
		int reduccion = 0;
		for (j = 0; j < potencia; j++) { // Hacer por fila
			for (k = 0; k < potencia - reduccion; k++) {
				printf("Posicion a cambiar (antena %d): (%d, %d)\n", i, fila + j, columna + k);
				if (abs(fila + j * direccion_fila) >= TAM_CIUDAD || abs(columna + k * direccion_columna) >= TAM_CIUDAD) {
					continue;
				}
				if (ciudad[fila + j * direccion_fila][columna + k * direccion_columna] == 'C') {
					ciudad[fila + j * direccion_fila][columna + k * direccion_columna] = '-';
				}
				else {
					ciudad[fila + j * direccion_fila][columna + k * direccion_columna] = 'C';
				}
			}
			reduccion++;
		}
	}
}

int main(void) {
	char ciudad[TAM_CIUDAD][TAM_CIUDAD] = { {' ', ' '}, {' ', ' '} };
	int antenas[3][4] = { {0, 0, 1, 2}, {1, 1, 3, 2}, {0, 1, 0, 2} };
	int i, j;
	OcuparEspacios(antenas, ciudad);
	for (i = 0; i < TAM_CIUDAD; i++) {
		for (j = 0; j < TAM_CIUDAD; j++) {
			printf("%c", ciudad[i][j]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
