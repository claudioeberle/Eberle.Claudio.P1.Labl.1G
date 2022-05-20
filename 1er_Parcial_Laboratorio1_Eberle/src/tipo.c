#include "tipo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*//////////////////////////////////////////./////////////////////////////////////////////////////////////////////*/

int buscarPosicionPorIdTipo(eTipo array[], int cant_array, int id, int* pPosicion)
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

int validarTipo(eTipo tipos[], int cant_tipos, int tipoId)
{
	int retorno = 0;

	if(tipos != NULL && cant_tipos > 0)
	{
		for(int i = 0; i < cant_tipos; i++)
		{
			if(tipos[i].id == tipoId)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarDescripcionTipo( eTipo tipos[], int cant_tipos, int tipoId)
{
	for(int i = 0; i < cant_tipos; i++){

		if(tipos[i].id == tipoId){

			printf("%s", tipos[i].descr);
			break;
		}
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarTipo(eTipo tipo)
{
	printf("ID: %d\n", tipo.id);
	printf("DESCRIPCION: %s\n", tipo.descr);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarTipoFila(eTipo tipo)
{
	printf("  %d     %s\n", tipo.id, tipo.descr);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarTipos(eTipo array[], int cant_array)
{
	int retorno = 0;
	int flag = 0;

	if(array != NULL && cant_array > 0)
	{
		printf("\n\n-------------------------");
		printf("\n  TIPOS DE BICLETA\n");
		printf("-------------------------\n");
		printf("   ID      DESCRIPCION   \n");
		printf("-------------------------\n");
		for(int i = 0; i < cant_array; i++)
		{
			mostrarTipoFila(array[i]);
			flag = 1;
			retorno = 1;
		}

		if(!flag){

			printf("No hay tipos de bicicletas para mostrar\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
