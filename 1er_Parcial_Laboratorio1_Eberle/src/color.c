#include "color.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarPosicionPorIdColor(eColor array[], int cant_array, int id, int* pPosicion)
{
	int retorno = 0;
	if(array != NULL && pPosicion != NULL && cant_array > 0)
	{
		for(int i = 0; i < cant_array; i++)
		{
			if(array[i].id == id)
			{
				*pPosicion = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarDescripcionColor( eColor colores[], int cant_colores, int colorId)
{
	for(int i = 0; i < cant_colores; i++){

		if(colores[i].id == colorId){

			printf("%s", colores[i].descripcion);
			break;
		}
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarColor(eColor color)
{
	printf("ID: %d\n", color.id);
	printf("DESCRIPCION: %s\n", color.descripcion);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarColorFila(eColor color)
{
	printf("  %d     %s\n", color.id, color.descripcion);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarColores(eColor array[], int cant_array)
{
	int retorno = 0;
	int flag = 0;

	if(array != NULL && cant_array > 0)
	{
		printf("\n\n-------------------------");
		printf("\n  COLORES     \n");
		printf("-------------------------\n");
		printf("   ID      DESCRIPCION   \n");
		printf("-------------------------\n");
		for(int i = 0; i < cant_array; i++)
		{
			mostrarColorFila(array[i]);
			flag = 1;
			retorno = 1;
		}

		if(!flag){

			printf("No hay Colores para mostrar\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarColor(eColor colores[], int cant_colores, int colorId)
{
	int retorno = 0;

	if(colores != NULL && cant_colores > 0)
	{
		for(int i = 0; i < cant_colores; i++)
		{
			if(colores[i].id == colorId)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
