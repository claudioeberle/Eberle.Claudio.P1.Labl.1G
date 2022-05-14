#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarPosicionPorIdServicio(eServicio array[], int cant_array, int id, int* pPosicion)
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

void mostrarDescripcionServicio( eServicio servicios[], int cant_servicios, int servicioId)
{
	for(int i = 0; i < cant_servicios; i++){

		if(servicios[i].id == servicioId){

			printf("%s\n", servicios[i].descripcion);
		}
	}

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarServicio(eServicio elemento)
{
	printf("%d\n", elemento.id);
	printf("%s\n", elemento.descripcion);
	printf("$%.2f\n", elemento.precio);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarServicioFila(eServicio elemento)
{
	printf("  %d  %15s    $%7.2f\n", elemento.id, elemento.descripcion, elemento.precio);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void listarServicios(eServicio array[], int cant_array)
{
	int flag = 0;

	if(array != NULL && cant_array > 0)
	{
		printf("\n\n---------------------------------------");
		printf("\n    SERVICIOS         \n");
		printf("---------------------------------------\n");
		printf("   ID       DESCRIPCION       PRECIO  \n");
		printf("---------------------------------------\n");
		for(int i = 0; i < cant_array; i++)
		{
			mostrarServicioFila(array[i]);
			flag = 1;
		}

		if(!flag){

			printf("No hay destinos para mostrar\n\n");
		}
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


