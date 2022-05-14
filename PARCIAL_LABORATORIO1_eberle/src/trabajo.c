#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "fecha.h"
#include "input.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarTrabajoLibre(eTrabajo trabajos[], int max_trabajos, int* pIndice){
	int retorno = 0;
	int flag = 0;

	if(trabajos != NULL && pIndice != NULL && max_trabajos > 0){

		for(int i = 0; i < max_trabajos; i++){

			if(trabajos[i].inactivo == 1){

				*pIndice = i;
				flag = 1;
				retorno = 1;
				break;
			}
		}

		if(!flag){

			*pIndice = -1;

			printf("No hay espacio disponible para cargar nuevos trabajos.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int inicializarTrabajos(eTrabajo trabajos[], int max_trabajos){

	int retorno = 0;

	if(trabajos != NULL && max_trabajos > 0){
		for (int i = 0; i < max_trabajos; i++){

			trabajos[i].inactivo = 1;
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int altaTrabajo(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, int* pProximoTrabajo)
{
	int retorno = 0;

	eTrabajo nuevoTrabajo;
	int indice;

	if(trabajos != NULL && colores != NULL && tipos != NULL && cant_trabajos > 0 && bicicletas != NULL && cant_bicicletas > 0 && servicios != NULL && cant_servicios > 0 && pProximoTrabajo != NULL)
	{
		if(buscarTrabajoLibre(trabajos, cant_trabajos, &indice))
		{
			nuevoTrabajo.id = *pProximoTrabajo;

				listarServicios(servicios, cant_servicios);
				if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 20000, 20003, &nuevoTrabajo.idServicio))
				{
					listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos);
					if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 30000, 31000, &nuevoTrabajo.idBicicleta))
					{
						ingresarFecha(&nuevoTrabajo.fecha, 1, 31, 1, 12, 2022, 2024);

						nuevoTrabajo.inactivo = 0;

						trabajos[indice] = nuevoTrabajo;

						retorno = 1;

						(*pProximoTrabajo)++;
					}
				}
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarPosicionPorIdTrabajo(eTrabajo array[], int cant_array, int id, int* pPosicion)
{
	int retorno = 0;
	if(array != NULL && id > 0 && pPosicion != NULL && cant_array > 0)
	{
		for(int i = 0; i < cant_array; i++)
		{
			if(array[i].inactivo == 0 && array[i].id == id)
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

int mostrarTrabajo(eTrabajo elemento, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios)
{
	int retorno = 0;

	if(bicicletas != NULL && servicios != NULL && cant_bicicletas > 0 && cant_servicios > 0)
	{

		printf("ID: %d\n", elemento.id);
		printf("BICICLETA: %d", elemento.idBicicleta);
		printf("SERVICIO: ");
		mostrarDescripcionServicio(servicios, cant_servicios, elemento.idServicio);
		printf("FECHA: %d/%d/%d\n", elemento.fecha.dia, elemento.fecha.mes, elemento.fecha.anio);

		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarTrabajoFila(eTrabajo elemento, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios)
{
	int retorno = 0;
	int posServicio;
	char descServicio[20];

	if(bicicletas != NULL && servicios != NULL && cant_bicicletas > 0 && cant_servicios > 0)
		{

			buscarPosicionPorIdServicio(servicios, cant_servicios, elemento.idServicio, &posServicio);
			strcpy(descServicio, servicios[posServicio].descripcion);

			printf(" %4d  %d  %s  %2d/%2d/%4d \n", elemento.id, elemento.idBicicleta, descServicio, elemento.fecha.dia, elemento.fecha.mes, elemento.fecha.anio);
			retorno = 1;
		}
		return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarTrabajos(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios)
{
	int retorno = 0;
	int flag = 0;

	if(trabajos != NULL && bicicletas != NULL && servicios != NULL && cant_bicicletas > 0 && cant_servicios > 0)
	{
		printf("\n\n----------------------------------------\n");
		printf("  TRABAJOS          \n");
		printf("----------------------------------------\n");
		printf("  ID   BICICLETA   SERVICIO   FECHA  \n");
		printf("----------------------------------------\n\n");


		for(int i = 0; i < cant_trabajos; i++)
		{
			if(trabajos[i].inactivo == 0){

				mostrarTrabajoFila(trabajos[i], bicicletas, cant_bicicletas, servicios, cant_servicios);
				flag = 1;
				retorno = 1;
			}
		}

		if(!flag){

			printf("No hay trabajos para mostrar\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
