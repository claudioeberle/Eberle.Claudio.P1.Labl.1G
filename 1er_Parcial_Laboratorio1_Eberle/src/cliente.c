
#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarPosicionPorIdCliente(eCliente array[], int cant_array, int id, int* pPosicion)
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

void mostrarNombreCliente( eCliente clientes[], int cant_clientes, int clienteId)
{
	for(int i = 0; i < cant_clientes; i++){

		if(clientes[i].id == clienteId){

			printf("%s", clientes[i].nombre);
			break;
		}
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarCliente(eCliente cliente)
{
	char sexo[12];

	if(cliente.sexo == 'm')
	{
		strcpy(sexo, "Masculino");
	}
	else if(cliente.sexo == 'f')
	{
		strcpy(sexo, "Femenino");
	}
	else
	{
		strcpy(sexo, "No Binario");
	}

	printf("ID: %d\n", cliente.id);
	printf("NOMBRE: %s\n", cliente.nombre);
	printf("SEXO: %s\n", sexo);

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void mostrarClienteFila(eCliente cliente)
{
	char sexo[12];

	if(cliente.sexo == 'm')
	{
		strcpy(sexo, "Masculino");
	}
	else if(cliente.sexo == 'f')
	{
		strcpy(sexo, "Femenino");
	}

	printf(" %4d     %-15s  %-10s\n", cliente.id, cliente.nombre, sexo);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarClientes(eCliente array[], int cant_array)
{
	int retorno = 0;
	int flag = 0;

	if(array != NULL && cant_array > 0)
	{
		printf("\n\n-------------------------------------");
		printf("\n  CLIENTES     \n");
		printf("-------------------------------------\n");
		printf("  ID      NOMBRE           SEXO \n");
		printf("-------------------------------------\n");
		for(int i = 0; i < cant_array; i++)
		{
			mostrarClienteFila(array[i]);
			flag = 1;
			retorno = 1;
		}

		if(!flag){

			printf("No hay Clientes para mostrar\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarCliente(eCliente clientes[], int cant_clientes, int clienteId)
{
	int retorno = 0;

	if(clientes != NULL && cant_clientes > 0)
	{
		for(int i = 0; i < cant_clientes; i++)
		{
			if(clientes[i].id == clienteId)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
