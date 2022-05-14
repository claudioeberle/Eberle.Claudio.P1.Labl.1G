#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ingresarFecha(eFecha* pFecha, int minDia, int maxDia, int minMes, int maxMes, int minAnio, int maxAnio){

	int retorno = 0;
	int dia;
	int mes;
	int anio;

	if(pFecha != NULL)
	{
		if((get_int("Ingrese Dia: (XX)", "Dato Incorrecto.\n", minDia, maxDia, &dia)) &&
		   (get_int("Ingrese Mes: (XX)", "Dato Incorrecto.\n", minMes, maxMes, &mes)) &&
		   (get_int("Ingrese Anio (XXXX): ", "Dato Incorrecto.\n", minAnio, maxAnio, &anio)))
		{
			pFecha ->dia = dia;
			pFecha->mes = mes;
			pFecha->anio = anio;
			retorno = 1;
		}
		else
		{
			printf("\n\n-----------------------------------\n");
			printf(" No se ha podido tomar el dato.\n");
			printf("-----------------------------------\n\n");
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

