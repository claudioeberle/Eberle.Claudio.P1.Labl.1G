#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "fecha.h"
#include "input.h"
#include "color.h"
#include "servicio.h"

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

int altaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, int* pProximoBicicleta)
{
	int retorno = 0;
	eBicicleta nuevoBicicleta;
	int indice;

	if(bicicletas != NULL && cant_bicicletas > 0 && colores != NULL && cant_colores > 0 && tipos != NULL && cant_tipos > 0 && pProximoBicicleta != NULL)
	{
		if(buscarBicicletaLibre(bicicletas, cant_bicicletas, &indice))
		{
			nuevoBicicleta.id = *pProximoBicicleta;

			if(cargaString(nuevoBicicleta.marca, 20, "Marca: ", "Dato Incorrecto"))
			{
				listarTipos(tipos, cant_tipos);
				if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 1000, 1003, &nuevoBicicleta.idTipo))
				{
					listarColores(colores, cant_colores);
					if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 5000, 5004, &nuevoBicicleta.idColor))
					{

							getCharacter("\nCarbono 'c' | Aluminio 'a'\nElija uno material: ", "Dato Incorrecto\n\n", &nuevoBicicleta.material, 'a', 'z');


							if(nuevoBicicleta.material != 'c' && nuevoBicicleta.material != 'a' )
							{
								printf("Dato Incorrecto.\n");

								getCharacter("\nCarbono 'c' | Aluminio 'a'\nElija uno material: ", "Dato Incorrecto\n\n", &nuevoBicicleta.material, 'a', 'z');
							}


						if(nuevoBicicleta.material == 'c' || nuevoBicicleta.material == 'a' )
						{
							nuevoBicicleta.inactivo = 0;

							bicicletas[indice] = nuevoBicicleta;

							retorno = 1;

							(*pProximoBicicleta)++;

							printf("Alta Exitosa.\n\n");
						}
						else{

							printf("Alta Cancelada.\n\n");
						}
					}
				}
			}
		}

	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuModificarBicicleta(void)
{

	char opcion;

	do{

		printf("\n-----------------------------------\n");
		printf("       MODIFICACIÓN DE BICICLETA         \n");
		printf("------------------------------------ \n\n");
		printf("A. TIPO DE BICICLETA\n\n");
		printf("B. COLOR\n\n");
		printf("C. SALIR\n\n");

		getCharacter("Qué desea modificar?\nElija e ingrese una opción: ","OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n", &opcion, 'a', 'c');

		}while((opcion < 'A' || opcion > 'C') && (opcion < 'a' || opcion > 'c'));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int modificarBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos)

{
	int retorno = 0;
	int id;
	int indice;
	char salir;
	char confirmacion;
	eBicicleta bicicleta;

	if(bicicletas != NULL && cant_bicicletas > 0 && colores != NULL && cant_colores > 0 && tipos != NULL && cant_tipos > 0)
	{


				if(listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos))
				{


					if((get_int("\n¿Qué bicicleta desea modificar?\nSeleccione y escriba el ID: ", "Dato Incorrecto\n\n", 30000, 31000, &id)) &&
					   (buscarPosicionPorIdBicicleta(bicicletas, cant_bicicletas, id, &indice)))
					{
						mostrarBicicleta(bicicletas[indice], colores, cant_colores, tipos, cant_tipos);

						do{

						switch(menuModificarBicicleta()){


								case 'a':

									listarTipos(tipos, cant_tipos);
									get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 1000, 1003, &bicicleta.idTipo);

									printf("\n---------------\n");
									printf("Tipo anterior: ");
									mostrarDescripcionTipo(tipos, cant_tipos, bicicletas[indice].idTipo);
									printf("\n");
									printf("Tipo nuevo: ");
									mostrarDescripcionTipo(tipos, cant_tipos, bicicleta.idTipo);
									printf("\n");
									getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion, 'a', 'z');
									if(confirmacion == 's'){

										bicicletas[indice].idTipo = bicicleta.idTipo;
										printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");


									}
									else{

										printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");

									}
									break;

								case 'b':
									listarColores(colores, cant_colores);
									get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 5000, 5004, &bicicleta.idColor);

									printf("\n---------------\n");
									printf("Color anterior: ");
									mostrarDescripcionColor(colores, cant_colores, bicicletas[indice].idColor);
									printf("\n");
									printf("Color nuevo: ");
									mostrarDescripcionColor(colores, cant_colores, bicicleta.idColor);
									printf("\n");
									getCharacter("\nConfirmar modificación (s): ", "Dato Incorrecto", &confirmacion, 'a', 'z');
									if(confirmacion == 's'){

										bicicletas[indice].idColor = bicicleta.idColor;
										printf("\n\n->->-> MODIFICACIÓN EXITOSA <-<-<-\n");


									}
									else{

										printf("\n->->-> MODIFICACIÓN CANCELADA <-<-<-\n");


									}
									break;

								case 'c':

									salir = 's';

									break;

						}

					}while((salir != 's') && (salir != 'S'));
				}
			}
			else
			{
				printf("No existe ninguna bicicleta con ese ID\n\n");
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

int mostrarBicicleta(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos)
{
	int retorno = 0;
	char material[10];

	if(colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0)
	{

		printf("\n\nID: %d\n", elemento.id);
		printf("COLOR: ");
		mostrarDescripcionColor(colores, cant_colores, elemento.idColor);
		printf("\n");
		printf("TIPO DE BICICLETA: ");
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
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int mostrarBicicletaFila(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos)
{
	int retorno = 0;
	int posColor;
	int posTipo;
	char descColor[20];
	char descTipo[20];
	char material[10];

	if(colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0)
		{

			buscarPosicionPorIdColor(colores, cant_colores, elemento.idColor, &posColor);
			buscarPosicionPorIdTipo(tipos, cant_tipos, elemento.idTipo, &posTipo);
			strcpy(descColor, colores[posColor].descripcion);
			strcpy(descTipo, tipos[posTipo].descr);

			if(elemento.material == 'c')
			{
				strcpy(material, "Carbono");
			}
			if(elemento.material == 'a')
			{
				strcpy(material, "Aluminio");
			}

			printf(" %4d %10s  %10s  %10s \n", elemento.id, descColor, descTipo, material);
			retorno = 1;
		}
		return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int listarBicicletas(eBicicleta array[], int cant_array, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos)
{
	int retorno = 0;
	int flag = 0;

	if(array != NULL && cant_array > 0 && colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0)
	{
		printf("\n\n----------------------------------------\n");
		printf("  BICICLETAS          \n");
		printf("----------------------------------------\n");
		printf("  ID      COLOR     TIPO      MATERIAL  \n");
		printf("----------------------------------------\n\n");


		for(int i = 0; i < cant_array; i++)
		{
			if(array[i].inactivo == 0){
				mostrarBicicletaFila(array[i], colores, cant_colores, tipos, cant_tipos);
				flag = 1;
				retorno = 1;
			}
		}

		if(!flag){

			printf("No hay bicicletaes para mostrar\n\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bajaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos)

{
	int retorno = 0;
	int id;
	int indice;
	char opcion;

	if(bicicletas != NULL && cant_bicicletas > 0 && colores != NULL && tipos != NULL && cant_colores > 0 && cant_tipos > 0)
	{

				if(listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos))
				{

					if((get_int("\n¿Qué bicicleta desea eliminar?\nSeleccione y escriba el ID: ", "Dato Incorrecto\n\n", 30000, 31000, &id)) &&
					   (buscarPosicionPorIdBicicleta(bicicletas, cant_bicicletas, id, &indice)))
					{

						printf("Bicicleta a eliminar:  \n");
						printf("------------------\n");
						mostrarBicicleta(bicicletas[indice], colores, cant_bicicletas, tipos, cant_tipos);

						getCharacter("\n\nConfirma la baja? (s): ", "Opción Incorrecta", &opcion, 'a', 'z');

						if(opcion == 's' || opcion == 'S')
						{

							bicicletas[indice].inactivo = 1;
							retorno = 1;

							printf("\n\n--------------\n");
							printf(" Baja exitosa. \n");
							printf("---------------\n\n");
						}
						else
						{
							printf("\n\n--------------\n");
							printf(" Baja cancelada. \n");
							printf("---------------\n\n");
						}
					}
				}
	}

		return retorno;
}


