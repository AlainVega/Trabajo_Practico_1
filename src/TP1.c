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
#include "Antenas.h"

void InicializarMatriz(char matriz[TAM_CIUDAD][TAM_CIUDAD]);
int ValidarEntrada(int array[N_ANTENAS][4], int fila);
void ImprimirMatriz(char matriz[TAM_CIUDAD][TAM_CIUDAD]);
void OcuparEspacios(int indice, char ciudad[TAM_CIUDAD][TAM_CIUDAD]);


void OcuparEspacios(int indice, char ciudad[TAM_CIUDAD][TAM_CIUDAD]) {
	// Recibe el indice de una antena ya validada y cambia los valores en la matriz.
	int fila = antenas[indice][0];
	int columna = antenas[indice][1];
	int direccion = antenas[indice][2];
	int potencia = antenas[indice][3];
	int direccion_fila, direccion_columna;
	switch (direccion) {
		// Decidir los multiplicadores en la direccion para usarlos despues
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
	int i, j;
	int reduccion = 0;
	int bandera_excedio_matriz = 0;
	for (i = 0; i < potencia; i++) { // Recorrer por fila
		for (j = 0; j < potencia - reduccion; j++) { // La cantidad de columnas recorridas disminuye con fila
			// Las variables de direccion se utilizan para multiplicar por los iteradores y asi moverse hacia arriba o abajo o izquierda o derecha
			if ((fila + i * direccion_fila >= TAM_CIUDAD || fila + i * direccion_fila < 0) || (columna + j * direccion_columna >= TAM_CIUDAD || columna + j * direccion_columna < 0)) {
				bandera_excedio_matriz = 1;
				continue;
			}
			if (ciudad[fila + i * direccion_fila][columna + j * direccion_columna] == 'C') {
				ciudad[fila + i * direccion_fila][columna + j * direccion_columna] = '-';
			}
			else {
				ciudad[fila + i * direccion_fila][columna + j * direccion_columna] = 'C';
			}
		}
		reduccion++;
	}
	if (bandera_excedio_matriz == 1) {
		printf("Cuidado: la señal de la antena %d excedio el rango de la ciudad.\n", indice);
	}
}

int main(void) {
	int i;
	char ciudad[TAM_CIUDAD][TAM_CIUDAD];
	InicializarMatriz(ciudad);
	for (i = 0; i < N_ANTENAS; ++i) {
		if (ValidarEntrada(antenas, i) == 1) {
			OcuparEspacios(i, ciudad);
		}
	}
	puts("Resultado:");
	ImprimirMatriz(ciudad);
}

/*
Funcion que inicializa una matriz de caracteres dada, llenando cada celda con un "-".
NO retorna parametros.
Recibe la matriz de caracteres.
*/
void InicializarMatriz(char matriz[TAM_CIUDAD][TAM_CIUDAD]) {
	int i, j;
	for (i = 0; i < TAM_CIUDAD; i++) {
		for (j = 0; j < TAM_CIUDAD; j++) {
			matriz[i][j] = '-';
		}
	}
}

/*
Funcion ValidarEntrada, verifica si la antena que se quiere verificar es valida o no
Recibe 2 parametros el primero: un array bidimensional, el segundo: la fila la cual se desea verificar de ese array.
Retorna un valor entero, 1 si esa antena es valida, 0 si esa antena no es valida.
*/
int ValidarEntrada(int array[N_ANTENAS][4], int fila) {
	//verificamos primero si las coordenadas de la antena son validas
	int j, f, c;
	int bandPosicion = 0;
	int bandDireccion = 0;
	int bandPotencia = 0;
	for (j = 0; j < 4; ++j) {
		if (j == 0) {
			f = array[fila][j];
			c = array[fila][j+1];
			if (f >= 0 && f < TAM_CIUDAD && c >= 0 && c < TAM_CIUDAD) {
				//Las coordenadas de la antena son validas
				bandPosicion = 1;
			}
			else {
				bandPosicion = 0;
				printf("Se descarto la antena numero: %d, por coordenada no valida.\n", fila);
				break;
			}
		}
		else if (j == 2) {
			if (array[fila][j] >= 0 && array[fila][j] <= 3) {
				//La antena tiene una zona de cobertura valida
				bandDireccion = 1;
			}
			else {
				bandDireccion = 0;
				printf("Se descarto la antena numero: %d, por zona de cobertura no valida.\n", fila);
				break;
			}
		}
		else if (j == 3) {
			if (array[fila][j] > 0) {
				//La antena  tiene una potencia valida
				bandPotencia = 1;
			}
			else {
				bandPotencia = 0;
				printf("Se descarto la antena numero: %d, por potencia no valida.\n", fila);
				break;
			}
		}
	}
	int valido = 0;
	if (bandPosicion == 1 && bandDireccion == 1 && bandPotencia == 1) {
		//La antena es valida
		valido = 1;
	}
	else {
		//La antena no es valida
		valido = 0;
	}
	return valido;
}

/*
Funcion ImprimirMatriz, imprime una matriz de caracteres
No retorna nada
Recibe la matriz de caracteres a ser imprimida
*/
void ImprimirMatriz(char matriz[TAM_CIUDAD][TAM_CIUDAD]) {
	int i, j;
	for (i = 0; i < TAM_CIUDAD; i++) {
		for (j = 0; j < TAM_CIUDAD; j++) {
			if (j == TAM_CIUDAD - 1) {
				printf("|%c|", matriz[i][j]);
			}
			else {
				printf("|%c", matriz[i][j]);
			}
		}
		printf("\n");
	}
}
