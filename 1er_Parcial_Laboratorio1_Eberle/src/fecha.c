#include "fecha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ingresarFecha(eFecha* pFecha, int minDia, int maxDia, int minMes, int maxMes, int minAnio, int maxAnio){

	int retorno = 0;
	int reintentos = 2;
	int dia;
	int mes;
	int anio;

	if(pFecha != NULL)
	{
		do{
			printf("\n Fecha\n");
			printf("---------------\n\n");

			if((get_int("Ingrese Dia: ", "Dato Incorrecto.\n", minDia, maxDia, &dia)) &&
			   (get_int("Ingrese Mes: ", "Dato Incorrecto.\n", minMes, maxMes, &mes)) &&
			   (get_int("Ingrese Anio: ", "Dato Incorrecto.\n", minAnio, maxAnio, &anio)) &&
			   (validarFecha(dia, mes, anio)))
			{
				pFecha ->dia = dia;
				pFecha->mes = mes;
				pFecha->anio = anio;
				retorno = 1;
				break;
			}
			else
			{
				printf("\n\n-----------------\n");
				printf(" Dato Incorrecto\n");
				printf("-----------------\n\n");

				reintentos--;
			}

		}while(reintentos > 0);
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int anioBisiesto(int anio)
{
	int retorno = 0;

	if( (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
	{
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarFecha(int dia, int mes, int anio)
{
	int retorno = 0;

	int dias_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(anioBisiesto(anio))
	{
		dias_mes[1] = 29;
	}

	if(dia > 0 && dia <= dias_mes[mes-1] && mes >= 1 && mes <= 12)
	{
		retorno = 1;
	}


	return retorno;

}
