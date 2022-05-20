#include "trabajo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicleta.h"
#include "color.h"
#include "fecha.h"
#include "input.h"
#include "servicio.h"
#include "tipo.h"

/*/////////////////////////////////////////////.//////////////////////////////////////////////////////////////////*/

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

int altaTrabajo(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, int* pProximoTrabajo)
{
	int retorno = 0;
	eTrabajo nuevoTrabajo;
	int indice;
	char confirmacion;

	if(trabajos != NULL && colores != NULL && tipos != NULL && cant_trabajos > 0 && bicicletas != NULL && cant_bicicletas > 0 && servicios != NULL && cant_servicios > 0 && clientes != NULL && cant_clientes > 0 && pProximoTrabajo != NULL)
	{
		if(buscarTrabajoLibre(trabajos, cant_trabajos, &indice))
		{
			nuevoTrabajo.id = *pProximoTrabajo;

			system("clear");
			printf("\n-----------------------------------\n");
			printf("       ALTA    DE    TRABAJO       \n");
			printf("-----------------------------------\n");

			listarServicios(servicios, cant_servicios);

			if((get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 20000, 20100, &nuevoTrabajo.idServicio)) &&
			   (validarServicio(servicios, cant_servicios, nuevoTrabajo.idServicio)))
			{
				system("clear");
				printf("\n-----------------------------------\n");
				printf("       ALTA    DE    TRABAJO       \n");
				printf("-----------------------------------\n");

				listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);

				if((get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 3000, 3100, &nuevoTrabajo.idBicicleta)) &&
					(validarBicicleta(bicicletas, cant_bicicletas, nuevoTrabajo.idBicicleta)))
				{
					system("clear");
					printf("\n-----------------------------------\n");
					printf("       ALTA    DE    TRABAJO       \n");
					printf("-----------------------------------\n");

					if((ingresarFecha(&nuevoTrabajo.fecha, 1, 31, 1, 12, 2022, 2050)) &&
					   (validarFecha(nuevoTrabajo.fecha.dia, nuevoTrabajo.fecha.mes, nuevoTrabajo.fecha.anio)))
					{
						system("clear");
						printf("\n-----------------------------------\n");
						printf("       ALTA    DE    TRABAJO       \n");
						printf("-----------------------------------\n");

						mostrarTrabajo(nuevoTrabajo, bicicletas, cant_bicicletas, servicios, cant_servicios, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);

						printf("---------------------------------------------\n");

						getCharacter("\nConfirmar alta (s): ", "Dato Incorrecto", &confirmacion);

						system("clear");
						if(confirmacion == 's')
						{

							nuevoTrabajo.inactivo = 0;

							trabajos[indice] = nuevoTrabajo;

							retorno = 1;

							(*pProximoTrabajo)++;

							printf("\n\n----------------------------\n");
							printf("  ->    ALTA EXITOSA    <- \n");
							printf("----------------------------\n\n");
						}

					}
					else
					{
						system("clear");
						printf("Fecha inválida\n\n");
					}

				}
				else
				{
					system("clear");
					printf("No existe ninguna bicicleta con ese ID\n\n");
				}
			}
			else
			{
				system("clear");
				printf("No existe ningún servicio con ese ID\n\n");
			}
		}
	}
	if(!retorno)
	{
		printf("\n\n----------------------------\n");
		printf("  ->   ALTA CANCELADA   <- \n");
		printf("----------------------------\n\n");
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

int mostrarTrabajo(eTrabajo elemento, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int indiceBici;

	if(bicicletas != NULL && servicios != NULL &&  colores != NULL && tipos != NULL && cant_bicicletas > 0 && cant_servicios > 0 && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		printf("\n\nNUEVO TRABAJO:\n");
		printf("--------------------------\n");
		printf("-ID: %d\n\n", elemento.id);
		printf("-BICICLETA: \n");
		printf("--------------------------");
		buscarPosicionPorIdBicicleta(bicicletas, cant_bicicletas, elemento.idBicicleta, &indiceBici);
		mostrarBicicleta(bicicletas[indiceBici], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
		printf("--------------------------\n\n");
		printf("-SERVICIO: ");
		mostrarDescripcionServicio(servicios, cant_servicios, elemento.idServicio);
		printf("\n");
		printf("-FECHA: %d/%d/%d\n", elemento.fecha.dia, elemento.fecha.mes, elemento.fecha.anio);

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

		printf(" %4d   %6d        %-15s  %02d/%02d/%4d \n", elemento.id, elemento.idBicicleta, descServicio, elemento.fecha.dia, elemento.fecha.mes, elemento.fecha.anio);
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
		printf("\n\n-------------------------------------------------\n");
		printf("  TRABAJOS          \n");
		printf("-------------------------------------------------\n");
		printf("  ID     BICICLETA    SERVICIO           FECHA     \n");
		printf("-------------------------------------------------\n");


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

int hardcodearTrabajos(eTrabajo trabajos[], int cant_trabajos, int cantidad, int* pProximotrabajo)

{
	int retorno = 0;
	int indice;

	if(trabajos != NULL && cant_trabajos > 0 && pProximotrabajo != NULL && cantidad > 0)
	{
		if(cantidad <= 30)
		{
			eTrabajo listado[30] =
			{
				{0, 3000, 20000, {2,8,2022}, 0},
				{0, 3000, 20003, {1,3,2023}, 0},
				{0, 3000, 20001, {5,12,2022}, 0},
				{0, 3000, 20003, {15,7,2022}, 0},
				{0, 3001, 20000, {2,8,2022}, 0},
				{0, 3001, 20002, {1,8,2022}, 0},
				{0, 3002, 20000, {5,12,2022}, 0},
				{0, 3002, 20000, {10,10,2022}, 0},
				{0, 3002, 20002, {2,11,2022}, 0},
				{0, 3002, 20003, {12,1,2022}, 0},
				{0, 3003, 20002, {5,12,2022}, 0},
				{0, 3003, 20001, {3,11,2022}, 0},
				{0, 3004, 20001, {2,8,2022}, 0},
				{0, 3004, 20003, {1,12,2022}, 0},
				{0, 3004, 20003, {5,12,2022}, 0},
				{0, 3004, 20000, {2,8,2022}, 0},
				{0, 3005, 20003, {1,7,2022}, 0},
				{0, 3006, 20002, {21,11,2022}, 0},
				{0, 3006, 20003, {2,2,2023}, 0},
				{0, 3006, 20000, {2,2,2023}, 0},
				{0, 3007, 20001, {2,2,2023}, 0},
				{0, 3007, 20002, {2,2,2023}, 0},
				{0, 3007, 20003, {12,12,2021}, 0},
				{0, 3007, 20002, {12,12,2021}, 0},
				{0, 3007, 20002, {05,07,2021}, 0},
				{0, 3008, 20000, {22,3,2022}, 0},
				{0, 3008, 20003, {11,7,2022}, 0},
				{0, 3008, 20001, {11,7,2022}, 0},
				{0, 3008, 20003, {20,2,2022}, 0},
				{0, 3009, 20000, {1,1,2022}, 0}
			};

			for(int i = 0; i < cantidad; i++)
			{
				if(buscarTrabajoLibre(trabajos, cant_trabajos, &indice))
				{
					trabajos[indice] = listado[i];

					trabajos[indice].id = *pProximotrabajo;

					(*pProximotrabajo)++;

					retorno = 1;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			printf("\n\nLa cantidad de datos deseados no debe ser superior a 30\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
