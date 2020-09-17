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

int main(void) {
	puts("Bienvenido... \nEl mapa de la ciudad es:");
	char ciudad[TAM_CIUDAD][TAM_CIUDAD];
	InicializarMatriz(ciudad);
	int i, j;
	for ( i = 0 ; i < N_ANTENAS ; i++ ) {
		int fila;
		for ( j = 0 ; j < 1 ; j++ ) {
			int columna;
			fila = antenas[i][j];
			columna = antenas[i][j+1];
			ciudad[fila][columna] = 'x';
			fila = 0;
			columna = 0;
		}
	}
	puts("La matriz es:");
	for ( i = 0 ; i < TAM_CIUDAD ; i++ ) {
		for ( j = 0; j < TAM_CIUDAD ; j++ ) {
			if (j == TAM_CIUDAD -1 ) {
				printf("|%c|", ciudad[i][j]);
			}
			else
			{
			printf("|%c", ciudad[i][j]);
			};
		}
		printf("\n");
	}
}

/*
Funcion que inicializa una matriz de caracteres dada, llenando cada celda con un "-".
NO retorna parametros.
Recibe la matriz de caracteres.
*/
void InicializarMatriz(char matriz[TAM_CIUDAD][TAM_CIUDAD]) {
	int i, j;
	for ( i = 0 ; i < TAM_CIUDAD ; i++ ) {
		for ( j = 0 ; j < TAM_CIUDAD ; j++ ) {
			matriz[i][j] = '-';
		}
	}
	for ( i = 0 ; i < TAM_CIUDAD ; i++ ) {
		for ( j = 0; j < TAM_CIUDAD ; j++ ) {
			if (j == TAM_CIUDAD -1 ) {
				printf("|%c|", matriz[i][j]);
			}
			else
			{
				printf("|%c", matriz[i][j]);
			}
		}
		printf("\n");
	}
}

