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

int main(void) {
	puts("Bienvenido... \nEl mapa inicial de la ciudad es:");
	char ciudad[TAM_CIUDAD][TAM_CIUDAD];
	InicializarMatriz(ciudad);
	int i, j;
	for ( i = 0 ; i < N_ANTENAS ; i++ ) {
		if ( 1 == ValidarEntrada(antenas, i)) {
			int fila;
			for ( j = 0 ; j < 1 ; j++ ) {
				int columna;
				fila = antenas[i][j];  // obtenemos el valor de la fila para la matriz de la ciudad
				columna = antenas[i][j+1]; // obtenemos el valor de la columna para la matriz de la ciudad
				ciudad[fila][columna] = 'x';
				fila = 0;
				columna = 0;
			}
		}
	}
	ImprimirMatriz(ciudad);
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
	for ( j = 0; j < 4 ; ++j ) {
		if (j == 0) {
			f = array[fila][j];
			c = array[fila][j+1];
			if (f >= 0 && f < TAM_CIUDAD && c >= 0 && c < TAM_CIUDAD) {
				//Las coordenadas de la antena  son validas
				bandPosicion = 1;
			}
			else {
				bandPosicion = 0;
				break;
			}
		}
		else if (j == 2) {
			if ( array[fila][j] >= 0 && array[fila][j] <= 3 ) {
				//La antena tiene una zona de cobertura valida
				bandDireccion = 1;
			}
			else {
				bandDireccion = 0;
				break;
			}
		}
		else if ( j == 3 ) {
			if ( array[fila][j] > 0 ) {
				//La antena  tiene una potencia valida
				bandPotencia = 1;
			}
			else{
				bandPotencia = 0;
				break;
			}
		}
	}
	int valido = 0;
	if ( bandPosicion == 1 && bandDireccion == 1 && bandPotencia == 1 ) {
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
	puts("El mapa es:");
	int i, j;
	for ( i = 0 ; i < TAM_CIUDAD ; i++ ) {
		for ( j = 0; j < TAM_CIUDAD ; j++ ) {
			if (j == TAM_CIUDAD -1 ) {
				printf("|%c|", matriz[i][j]);
			}
			else
			{
			printf("|%c", matriz[i][j]);
			};
		}
		printf("\n");
	}
}
