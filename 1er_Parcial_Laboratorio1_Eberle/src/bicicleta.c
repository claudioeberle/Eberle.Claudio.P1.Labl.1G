#include "bicicleta.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "color.h"
#include "fecha.h"
#include "input.h"
#include "servicio.h"
#include "tipo.h"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarBicicletaLibre(eBicicleta bicicletas[], int max_bicicletas, int* pIndice){
	int retorno = 0;
	int flag = 0;

	if(bicicletas != NULL && pIndice != NULL && max_bicicletas > 0){

		for(int i = 0; i < max_bicicletas; i++){

			if(bicicletas[i].inactivo == 1){

				*pIndice = i;
				flag = 1;
				retorno = 1;
				break;
			}
		}

		if(!flag){

			*pIndice = -1;

			printf("No hay espacio disponible para cargar nuevas bicicletas.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int inicializarBicicletas(eBicicleta bicicletas[], int max_bicicletas){

	int retorno = 0;

	if(bicicletas != NULL && max_bicicletas > 0){
		for (int i = 0; i < max_bicicletas; i++){

			bicicletas[i].inactivo = 1;
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int altaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, int* pProximoBicicleta)
{
	int retorno = 0;
	eBicicleta nuevoBicicleta;
	int indice;
	char confirmacion;

	if(bicicletas != NULL && cant_bicicletas > 0 && colores != NULL && cant_colores > 0 && tipos != NULL && cant_tipos > 0 && clientes != NULL && cant_clientes > 0 && pProximoBicicleta != NULL)
	{
		system("clear");
		printf("\n-----------------------------------\n");
		printf("      ALTA   DE    BICICLETA       \n");
		printf("-----------------------------------\n");

		if(buscarBicicletaLibre(bicicletas, cant_bicicletas, &indice))
		{
			nuevoBicicleta.id = *pProximoBicicleta;
			system("clear");
			printf("\n-----------------------------------\n");
			printf("      ALTA   DE    BICICLETA       \n");
			printf("-----------------------------------\n");

			if(cargaString(nuevoBicicleta.marca, 20, "\n\nMarca: ", "Dato Incorrecto\n"))
			{
				system("clear");
				printf("\n-----------------------------------\n");
				printf("      ALTA   DE    BICICLETA       \n");
				printf("-----------------------------------\n");

				listarTipos(tipos, cant_tipos);

				if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 1000, 1003, &nuevoBicicleta.idTipo))
				{
					system("clear");
					printf("\n-----------------------------------\n");
					printf("      ALTA   DE    BICICLETA       \n");
					printf("-----------------------------------\n");

					listarColores(colores, cant_colores);

					if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 5000, 5004, &nuevoBicicleta.idColor))
					{
						system("clear");
						printf("\n-----------------------------------\n");
						printf("      ALTA   DE    BICICLETA       \n");
						printf("-----------------------------------\n");

						if((getCharacter("\nCarbono 'c' | Aluminio 'a'\n\nElija un material: ", "Dato Incorrecto\n\n", &nuevoBicicleta.material)) &&
						   (nuevoBicicleta.material == 'c' || nuevoBicicleta.material == 'a' ))
						{
							system("clear");
							printf("\n-----------------------------------\n");
							printf("      ALTA   DE    BICICLETA       \n");
							printf("-----------------------------------\n");

							listarClientes(clientes, cant_clientes);

							if((get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 6000, 6999, &nuevoBicicleta.idCliente)) &&
								(validarCliente(clientes, cant_clientes, nuevoBicicleta.idCliente)))
							{
								system("clear");
								printf("\n-----------------------------------\n");
								printf("      ALTA   DE    BICICLETA       \n");
								printf("-----------------------------------\n");

								mostrarBicicleta(nuevoBicicleta, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
								printf("---------------------------------------------\n");

								getCharacter("\nConfirmar alta (s): ", "Dato Incorrecto", &confirmacion);

								if(confirmacion == 's'){

									nuevoBicicleta.inactivo = 0;

									bicicletas[indice] = nuevoBicicleta;

									retorno = 1;

									(*pProximoBicicleta)++;

									system("clear");
									printf("\n\n----------------------------\n");
									printf("  ->    ALTA EXITOSA    <- \n");
									printf("----------------------------\n\n");

								}
							}
						}
					}
				}
			}
		}
	}
	if(!retorno)
	{
		system("clear");
		printf("\n\n----------------------------\n");
		printf("  ->   ALTA CANCELADA   <- \n");
		printf("----------------------------\n\n");

	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuModificarBicicleta(void)
{

	char opcion;

	do{

		printf("A. TIPO DE BICICLETA\n\n");
		printf("B. COLOR\n\n");
		printf("C. SALIR\n\n");

		getCharacter("Qué desea modificar?\nElija e ingrese una opción: ","OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n", &opcion);

		}while((opcion < 'A' || opcion > 'C') && (opcion < 'a' || opcion > 'c'));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int modificarBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)

{
	int retorno = 0;
	int id;
	int indice;
	char salir;
	char confirmacion;
	eBicicleta bicicleta;

	if(bicicletas != NULL && cant_bicicletas > 0 && colores != NULL && cant_colores > 0 && tipos != NULL && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		system("clear");
		printf("\n-----------------------------------\n");
		printf("     MODIFICACIÓN DE BICICLETA     \n");
		printf("-----------------------------------\n");

		if(listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes))
		{

			if((get_int("\n¿Qué bicicleta desea modificar?\nSeleccione y escriba el ID: ", "Dato Incorrecto\n\n", 3000, 4000, &id)) &&
			   (buscarPosicionPorIdBicicleta(bicicletas, cant_bicicletas, id, &indice)))
			{
				system("clear");
				do{

					printf("\n-----------------------------------\n");
					printf("     MODIFICACIÓN DE BICICLETA     \n");
					printf("-----------------------------------\n");
					mostrarBicicleta(bicicletas[indice], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					printf("-----------------------------------\n\n");

					switch(menuModificarBicicleta()){


						case 'a':

							system("clear");
							printf("\n-----------------------------------\n");
							printf("     MODIFICACIÓN DE BICICLETA     \n");
							printf("-----------------------------------\n");
							mostrarBicicleta(bicicletas[indice], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
							printf("-----------------------------------\n\n");
							listarTipos(tipos, cant_tipos);

							if((get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 1000, 2000, &bicicleta.idTipo)) &&
							   (validarTipo(tipos, cant_tipos, bicicleta.idTipo)))
							{
								printf("\n---------------\n");
								printf("Tipo anterior: ");
								mostrarDescripcionTipo(tipos, cant_tipos, bicicletas[indice].idTipo);
								printf("\n");
								printf("Tipo nuevo: ");
								mostrarDescripcionTipo(tipos, cant_tipos, bicicleta.idTipo);
								printf("\n");
								getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

								if(confirmacion == 's'){

									bicicletas[indice].idTipo = bicicleta.idTipo;

									system("clear");
									printf("\n\n----------------------------\n");
									printf(" -> MODIFICACIÓN EXITOSA <- \n");
									printf("----------------------------\n\n");
								}
								else
								{
									system("clear");
									printf("\n\n------------------------------\n");
									printf(" -> MODIFICACIÓN CANCELADA <- \n");
									printf("------------------------------\n\n");
								}
							}
							else
							{
								system("clear");
								printf("No existe ningún tipo de bicicleta con ese ID\n");
							}
							break;

						case 'b':

							system("clear");
							printf("\n-----------------------------------\n");
							printf("     MODIFICACIÓN DE BICICLETA     \n");
							printf("-----------------------------------\n");
							mostrarBicicleta(bicicletas[indice], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
							printf("-----------------------------------\n\n");
							listarColores(colores, cant_colores);

							if((get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 5000, 5100, &bicicleta.idColor)) &&
								(validarColor(colores, cant_colores, bicicleta.idColor)))
							{
								printf("\n---------------\n");
								printf("Color anterior: ");
								mostrarDescripcionColor(colores, cant_colores, bicicletas[indice].idColor);
								printf("\n");
								printf("Color nuevo: ");
								mostrarDescripcionColor(colores, cant_colores, bicicleta.idColor);
								printf("\n");
								getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion);

								if(confirmacion == 's'){

									bicicletas[indice].idColor = bicicleta.idColor;

									system("clear");
									printf("\n\n----------------------------\n");
									printf(" -> MODIFICACIÓN EXITOSA <- \n");
									printf("----------------------------\n\n");
								}
								else
								{
									system("clear");
									printf("\n\n------------------------------\n");
									printf(" -> MODIFICACIÓN CANCELADA <- \n");
									printf("------------------------------\n\n");
								}
							}
							else
							{
								system("clear");
								printf("No existe ningún color de bicicleta con ese ID\n");
							}
							break;

						case 'c':

							salir = 's';
							system("clear");
							break;
					}//switch

				}while((salir != 's') && (salir != 'S'));

			}//id
			else
			{
				system("clear");
				printf("\n\nNo existe ninguna bicicleta con ese ID\n\n");
			}
		}//listar
		else
		{
			system("clear");
			printf("\n\nNo hay bicicletas cargadas en sistema.\n\n");


		}
		retorno = 1;
	}
	return retorno;

}


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int buscarPosicionPorIdBicicleta(eBicicleta array[], int cant_array, int id, int* pPosicion)
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

int mostrarBicicleta(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	char material[10];

	if(colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{

		printf("\nID: %d\n", elemento.id);
		printf("MARCA: %s\n", elemento.marca);
		printf("COLOR: ");
		mostrarDescripcionColor(colores, cant_colores, elemento.idColor);
		printf("\nTIPO DE BICICLETA: ");
		mostrarDescripcionTipo(tipos, cant_tipos, elemento.idTipo);
		printf("\n");
		if(elemento.material == 'c')
		{
			strcpy(material, "Carbono");
		}
		if(elemento.material == 'a')
		{
			strcpy(material, "Aluminio");
		}
		printf("MATERIAL: %s\n", material);
		printf("CLIENTE: ");
		mostrarNombreCliente(clientes, cant_clientes, elemento.idCliente);
		printf("\n");
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarBicicletaFila(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int posColor;
	int posTipo;
	int posCliente;
	char descColor[20];
	char descTipo[20];
	char material[10];
	char nombreCliente[15];

	if(colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
		{

			buscarPosicionPorIdColor(colores, cant_colores, elemento.idColor, &posColor);
			buscarPosicionPorIdTipo(tipos, cant_tipos, elemento.idTipo, &posTipo);
			buscarPosicionPorIdCliente(clientes, cant_clientes, elemento.idCliente, &posCliente);
			strcpy(descColor, colores[posColor].descripcion);
			strcpy(descTipo, tipos[posTipo].descr);
			strcpy(nombreCliente, clientes[posCliente].nombre);

			if(elemento.material == 'c')
			{
				strcpy(material, "Carbono");
			}
			if(elemento.material == 'a')
			{
				strcpy(material, "Aluminio");
			}

			printf(" %4d     %-15s %-15s %-15s  %-10s      %-15s  \n", elemento.id, elemento.marca, descColor, descTipo, material, nombreCliente);
			retorno = 1;
		}
		return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarBicicletas(eBicicleta array[], int cant_array, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int flag = 0;

	if(array != NULL && cant_array > 0 && colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		printf("\n\n----------------------------------------------------------------------------------------\n");
		printf("  BICICLETAS          \n");
		printf("-----------------------------------------------------------------------------------------\n");
		printf("  ID      MARCA           COLOR           TIPO             MATERIAL        CLIENTE    \n");
		printf("-----------------------------------------------------------------------------------------\n");


		for(int i = 0; i < cant_array; i++)
		{
			if(array[i].inactivo == 0){
				mostrarBicicletaFila(array[i], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
				flag = 1;
				retorno = 1;
			}
		}

		if(!flag){

			system("clear");
			printf("\n\nNo hay bicicletas para mostrar\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bajaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)

{
	int retorno = 0;
	int id;
	int indice;
	char opcion;

	if(bicicletas != NULL && cant_bicicletas > 0 && colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		system("clear");
		printf("\n-----------------------------------\n");
		printf("         BAJA DE BICICLETA         \n");
		printf("-----------------------------------\n");
		if(listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes))
		{

			if((get_int("\n¿Qué bicicleta desea eliminar?\nSeleccione y escriba el ID: ", "Dato Incorrecto\n\n", 3000, 4000, &id)) &&
			   (buscarPosicionPorIdBicicleta(bicicletas, cant_bicicletas, id, &indice)) &&
			   (validarBicicleta(bicicletas, cant_bicicletas, bicicletas[indice].id)))
			{
				system("clear");
				printf("\n-----------------------------------\n");
				printf("         BAJA DE BICICLETA         \n");
				printf("-----------------------------------\n\n");

				printf("Bicicleta a eliminar: \n");
				printf("--------------------");

				mostrarBicicleta(bicicletas[indice], colores, cant_bicicletas, tipos, cant_tipos, clientes, cant_clientes);

				getCharacter("\n\nConfirma la baja? (s): ", "Opción Incorrecta", &opcion);

				if(opcion == 's' || opcion == 'S')
				{

					bicicletas[indice].inactivo = 1;
					retorno = 1;

					system("clear");
					printf("\n\n--------------------\n");
					printf(" -> BAJA EXITOSA <- \n");
					printf("--------------------\n\n");
				}
				else
				{
					system("clear");
					printf("\n\n--------------------\n");
					printf(" -> BAJA CANCELADA <- \n");
					printf("--------------------\n\n");
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
			printf("\n\nNo hay bicicletas cargadas en sistema.\n\n");

		}
	}

		return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int validarBicicleta(eBicicleta bicicletas[], int cant_bicicletas, int bicicletaId)
{
	int retorno = 0;

	if(bicicletas != NULL && cant_bicicletas > 0)
	{
		for(int i = 0; i < cant_bicicletas; i++)
		{
			if(bicicletas[i].id == bicicletaId)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int hardcodearBicicletas(eBicicleta bicicletas[], int cant_bicicletas, int cantidad, int* pProximoBicicleta)

{
	int retorno = 0;
	int indice;

	if(bicicletas != NULL && cant_bicicletas > 0 && pProximoBicicleta != NULL && cantidad > 0)
	{
		if(cantidad <= 10)
		{
			eBicicleta listado[10] =
			{
				{0, "Firebird", 1002, 5000, 'a', 6000, 0},
				{0, "Firebird", 1002, 5002, 'a', 6001, 0},
				{0, "Firebird", 1002, 5003, 'c', 6002, 0},
				{0, "Olmo", 1003, 5001, 'c', 6003, 0},
				{0, "Olmo", 1003, 5002, 'c', 6004, 0},
				{0, "Olmo", 1003, 5003, 'c', 6005, 0},
				{0, "BMC", 1001, 5001, 'a', 6006, 0},
				{0, "BMC", 1001, 5003, 'c', 6007, 0},
				{0, "Fuji", 1003, 5002, 'a', 6008, 0},
				{0, "Fuji", 1003, 5004, 'c', 6009, 0}
			};

			for(int i = 0; i < cantidad; i++)
			{
				if(buscarBicicletaLibre(bicicletas, cant_bicicletas, &indice))
				{
					bicicletas[indice] = listado[i];

					bicicletas[indice].id = *pProximoBicicleta;

					(*pProximoBicicleta)++;

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
			printf("\n\nLa cantidad de datos deseados no debe ser superior 10\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ordenarBicicletasTipo (eBicicleta bicicletas[], int cant_bicicletas)
{
	int retorno = 0;
	eBicicleta aux;

	if(bicicletas != NULL && cant_bicicletas > 0)
	{
		for ( int i = 0; i < cant_bicicletas - 1; i++)
		{
			for ( int j = i + 1; j < cant_bicicletas; j++)
			{
				if(bicicletas[i].idTipo > bicicletas[j].idTipo)
				{
					aux = bicicletas[i];
					bicicletas[i] = bicicletas[j];
					bicicletas[j] = aux;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarBicicletaFilaFecha(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, int dia, int mes, int anio)
{
	int retorno = 0;
	int posColor;
	int posTipo;
	int posCliente;
	char descColor[20];
	char descTipo[20];
	char material[10];
	char nombreCliente[15];

	if(colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0 &&
	  (validarFecha(dia, mes, anio)))
	{
		buscarPosicionPorIdColor(colores, cant_colores, elemento.idColor, &posColor);
		buscarPosicionPorIdTipo(tipos, cant_tipos, elemento.idTipo, &posTipo);
		buscarPosicionPorIdCliente(clientes, cant_clientes, elemento.idCliente, &posCliente);
		strcpy(descColor, colores[posColor].descripcion);
		strcpy(descTipo, tipos[posTipo].descr);
		strcpy(nombreCliente, clientes[posCliente].nombre);

		if(elemento.material == 'c')
		{
			strcpy(material, "Carbono");
		}
		if(elemento.material == 'a')
		{
			strcpy(material, "Aluminio");
		}

		printf(" %4d     %-15s %-15s %-15s  %-10s      %-15s  %02d/%02d/%4d\n", elemento.id, elemento.marca, descColor, descTipo, material, nombreCliente, dia, mes, anio);
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarBicicletaFilaServicio(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, eServicio servicio)
{
	int retorno = 0;
	int posColor;
	int posTipo;
	int posCliente;
	char descColor[20];
	char descTipo[20];
	char material[10];
	char nombreCliente[15];

	if(colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		buscarPosicionPorIdColor(colores, cant_colores, elemento.idColor, &posColor);
		buscarPosicionPorIdTipo(tipos, cant_tipos, elemento.idTipo, &posTipo);
		buscarPosicionPorIdCliente(clientes, cant_clientes, elemento.idCliente, &posCliente);
		strcpy(descColor, colores[posColor].descripcion);
		strcpy(descTipo, tipos[posTipo].descr);
		strcpy(nombreCliente, clientes[posCliente].nombre);

		if(elemento.material == 'c')
		{
			strcpy(material, "Carbono");
		}
		if(elemento.material == 'a')
		{
			strcpy(material, "Aluminio");
		}

		printf(" %-10s   $%7.2f  %4d   %-15s %-15s %-15s  %-10s   %-15s  \n", servicio.descripcion, servicio.precio, elemento.id, elemento.marca, descColor, descTipo, material, nombreCliente);
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


