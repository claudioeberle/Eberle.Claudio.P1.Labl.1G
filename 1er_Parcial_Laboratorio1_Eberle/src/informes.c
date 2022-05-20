#include "informes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicleta.h"
#include "cliente.h"
#include "color.h"
#include "fecha.h"
#include "input.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"

/*////////////////////////////////////////.///////////////////////////////////////////////////////////////////////*/

int informes(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	char salida;

	if(trabajos != NULL && colores != NULL && tipos != NULL && cant_trabajos > 0 && bicicletas != NULL && cant_bicicletas > 0 && servicios != NULL && cant_servicios > 0 && clientes != NULL && cant_clientes > 0)
	{
		do{
			switch(menuInformes()){

				case 1:

					bicicletasSegunColor(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					break;

				case 2:

					bicicletasSegunTipo(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					break;

				case 3:

					MaterialMaximoCantidad(bicicletas, cant_bicicletas);
					break;

				case 4:

					bicicletasPorTipos(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					break;

				case 5:

					cantidadPorColorYTipo(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos);
					break;

				case 6:

					colorMasElegido(bicicletas, cant_bicicletas, colores, cant_colores);
					break;

				case 7:

					trabajosSegunBicicleta(trabajos, cant_trabajos, bicicletas, cant_bicicletas, servicios, cant_servicios, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					break;

				case 8:

					importeServiciosBicicleta(trabajos, cant_trabajos, bicicletas, cant_bicicletas, servicios, cant_servicios, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					break;

				case 9:

					bicicletasFechasSegunServicio(trabajos, cant_trabajos, bicicletas, cant_bicicletas, servicios, cant_servicios, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					break;

				case 10:

					ServiciosSegunFecha(trabajos, cant_trabajos, bicicletas, cant_bicicletas, servicios, cant_servicios, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					break;

				case 11:

					salida = 's';
					system("clear");
					break;

			}

		}while((salida != 's') && (salida != 'S'));
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int menuInformes(void){

	int opcion;

	do{

		printf("\n--------------------------------------\n");
		printf("               INFORMES                \n");
		printf("-------------------------------------- \n\n");
		printf("1. BICICLETAS POR COLOR ELEGIDO POR USUARIO\n\n");
		printf("2. BICICLETAS POR TIPO ELEGIDO POR USUARIO\n\n");
		printf("3. MAYOR Y CANTIDAD MATERIAL (ALUMINIO | CARBONO)\n\n");
		printf("4. BICICLETAS SEPARADAS POR TIPOS\n\n");
		printf("5. CANTIDAD DE BICICLETAS DE UN TIPO Y COLOR ELEGIDOS POR USUARIO\n\n");
		printf("6. COLORES MÁS ELEGIDOS POR LOS USUARIOS\n\n");
		printf("7. TRABAJOS HECHOS A UNA BICICLETA\n\n");
		printf("8. TOTAL DE IMPORTE DE TODOS LOS SERVICIOS A UNA BICICLETA\n\n");
		printf("9. BICICLETAS Y FECHAS DE UN SERVICIO\n\n");
		printf("10. SERVICIOS POR FECHA\n\n");
		printf("11. SALIR\n\n");

		get_int("Elija una opción: ", "OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n", 1, 11, &opcion);

	}while(opcion < 1 || opcion > 11);
	return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bicicletasSegunColor(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int idColor;
	int indiceColor;
	int flag = 0;

	if(bicicletas != NULL && colores != NULL && tipos != NULL && cant_bicicletas > 0 && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		listarColores(colores, cant_colores);

		if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 5000, 5004, &idColor))
		{
			buscarPosicionPorIdColor(colores, cant_colores, idColor, &indiceColor);

			system("clear");
			printf("\n\n----------------------------------------------------------------------------------------\n");
			printf("  BICICLETAS  DE COLOR %s \n", colores[indiceColor].descripcion);
			printf("-----------------------------------------------------------------------------------------\n");
			printf("  ID      MARCA           COLOR           TIPO             MATERIAL        CLIENTE    \n");
			printf("-----------------------------------------------------------------------------------------\n");
			for( int i = 0; i < cant_bicicletas; i++)
			{
				if(bicicletas[i].idColor == idColor && bicicletas[i].inactivo == 0)
				{
					mostrarBicicletaFila(bicicletas[i], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					flag = 1;
				}
			}
			if(!flag)
			{
				printf("No hay bicicletas de color %s para mostrar.\n\n", colores[indiceColor].descripcion);
			}
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bicicletasSegunTipo(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int idTipo;
	int indiceTipo;
	int flag = 0;

	if(bicicletas != NULL && colores != NULL && tipos != NULL && cant_bicicletas > 0 && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		listarTipos(tipos, cant_tipos);

		if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 1000, 1003, &idTipo))
		{
			buscarPosicionPorIdTipo(tipos, cant_tipos, idTipo, &indiceTipo);

			system("clear");
			printf("\n\n----------------------------------------------------------------------------------------\n");
			printf("  BICICLETAS  DE TIPO %s \n", tipos[indiceTipo].descr);
			printf("-----------------------------------------------------------------------------------------\n");
			printf("  ID      MARCA           COLOR           TIPO             MATERIAL        CLIENTE    \n");
			printf("-----------------------------------------------------------------------------------------\n");
			for( int i = 0; i < cant_bicicletas; i++)
			{
				if(bicicletas[i].idTipo == idTipo && bicicletas[i].inactivo == 0)
				{
					mostrarBicicletaFila(bicicletas[i], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					flag = 1;
				}
			}
			if(!flag)
			{
				printf("No hay bicicletas de tipo %s para mostrar.\n\n", tipos[indiceTipo].descr);
			}
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int MaterialMaximoCantidad(eBicicleta bicicletas[], int cant_bicicletas)
{
	int retorno = 0;
	int totalCarbono = 0;
	int totalAluminio = 0;

	if(bicicletas != NULL && cant_bicicletas > 0)
	{

		for(int i = 0; i < 2; i++)
		{
			totalBicicletasPorMaterial(bicicletas, cant_bicicletas, 'c', &totalCarbono);
			totalBicicletasPorMaterial(bicicletas, cant_bicicletas, 'a', &totalAluminio);
		}

		system("clear");
		printf("\n\n---------------------------------------------------------------------\n");
		if(totalCarbono > totalAluminio)
		{
			printf("El material mayoritario es Carbono y hay %d bicicletas", totalCarbono);
		}
		else if(totalCarbono < totalAluminio)
		{
			printf("El material mayoritario es Aluminio y hay %d bicicletas", totalAluminio);
		}
		else
		{
			printf("Hay la misma cantidad de ambos materiales y la cantidad de cada uno es %d", totalCarbono);
		}
		printf("\n---------------------------------------------------------------------\n\n");

		retorno = 1;
	}
	return retorno;
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int totalBicicletasPorMaterial(eBicicleta bicicletas[], int cant_bicicletas, char material, int* pTotal)
{
	int retorno = 0;
	int contador = 0;

	if(bicicletas != NULL && cant_bicicletas > 00)
	{
		for(int i = 0; i < cant_bicicletas; i++)
		{
			if(material == bicicletas[i].material && bicicletas[i].inactivo == 0)
			{
				contador++;
			}
		}
		*pTotal = contador;
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bicicletasPorTipos(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int flag = 0;

	if(bicicletas != NULL && colores != NULL && tipos != NULL && cant_bicicletas > 0 && cant_colores > 0 && cant_tipos > 0 && clientes != NULL && cant_clientes > 0)
	{
		for(int i = 0; i < cant_tipos; i++)
		{
			flag = 0;

			printf("\n\n----------------------------------------------------------------------------------------\n");
			printf("Bicicletas de Tipo %s\n", tipos[i].descr);
			printf("-----------------------------------------------------------------------------------------\n");
			printf("  ID      MARCA           COLOR           TIPO             MATERIAL        CLIENTE    \n");
			printf("-----------------------------------------------------------------------------------------\n");

			for(int j = 0; j < cant_bicicletas; j++)
			{
				if(bicicletas[j].inactivo == 0 && tipos[i].id == bicicletas[j].idTipo)
				{
					mostrarBicicletaFila(bicicletas[j], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);
					flag = 1;
				}
			}
			if(!flag)
			{
				printf("No hay bicicletas de este tipo.\n");
			}

		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cantidadPorColorYTipo(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos)
{
	int retorno = 0;
	int idColor;
	int indiceColor;
	int contador = 0;
	int idTipo;
	int indiceTipo;
	int flag = 0;

	if(bicicletas != NULL && colores != NULL && tipos != NULL && cant_bicicletas > 0 && cant_colores > 0 && cant_tipos > 0)
	{
		listarColores(colores, cant_colores);

		if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 5000, 5004, &idColor))
		{
			buscarPosicionPorIdColor(colores, cant_colores, idColor, &indiceColor);

			listarTipos(tipos, cant_tipos);

			if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 1000, 1003, &idTipo))
			{
				buscarPosicionPorIdTipo(tipos, cant_tipos, idTipo, &indiceTipo);

				for(int i = 0; i < cant_bicicletas; i ++)
				{
					if(bicicletas[i].inactivo == 0)
					{
						if(bicicletas[i].idColor == idColor)
						{

							if(bicicletas[i].idTipo == idTipo)
							{
								contador++;
								flag = 1;
							}
						}
					}
				}
				system("clear");
				printf("\n\n-------------------------------------------------------\n");
				if(!flag)
				{

					printf("No hay bicicletas de color %s y tipo %s para mostrar\n", colores[indiceColor].descripcion, tipos[indiceTipo].descr);
				}
				else
				{

					printf("Hay %d bicicleta/s de color %s y tipo %s\n", contador, colores[indiceColor].descripcion, tipos[indiceTipo].descr);
				}
				printf("\n\n-------------------------------------------------------\n");

			}
		}
		retorno = 1;
	}
	return retorno;
}


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int colorMasElegido(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores)
{
	int retorno = 0;
	int flag = 1;
	int max;
	int totales[cant_colores];

	if(bicicletas != NULL && colores != NULL && cant_bicicletas > 0 && cant_colores > 0)
	{

		for(int i = 0; i < cant_colores; i++)
		{
			totales[i] = 0;
		}

		for(int i = 0; i < cant_colores; i++)
		{
			totalBicicletasPorColor(bicicletas, cant_bicicletas, colores[i], &totales[i]);
		}

		for(int i = 0; i < cant_colores; i++)
		{
			if(flag || totales[i] > max)
			{
				max = totales[i];
				flag = 0;
			}
		}

		system("clear");
		printf("\n\n---------------------------------------------------\n");
		printf("Los Colores con mayor cantidad de bicicletas son: \n\n");

		for(int i = 0; i < cant_colores; i++)
		{
			if(totales[i] == max)
			{
				printf("%s\n", colores[i].descripcion);
			}
		}

		printf("---------------------------------------------------\n\n");
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int totalBicicletasPorColor(eBicicleta bicicletas[], int cant_bicicletas, eColor color, int* pTotal)
{
	int retorno = 0;
	int contador = 0;

	if(bicicletas != NULL && cant_bicicletas > 00)
	{
		for(int i = 0; i < cant_bicicletas; i++)
		{
			if(color.id == bicicletas[i].idColor && bicicletas[i].inactivo == 0)
			{
				contador++;
			}

		}
		*pTotal = contador;
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int trabajosSegunBicicleta(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int flag = 0;
	int idBicicleta;

	if(trabajos != NULL && colores != NULL && tipos != NULL && cant_trabajos > 0 && bicicletas != NULL && cant_bicicletas > 0 && servicios != NULL && cant_servicios > 0 && clientes != NULL && cant_clientes > 0)
	{

		listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);

		if((get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 3000, 3100, &idBicicleta)) &&
			(validarBicicleta(bicicletas, cant_bicicletas, idBicicleta)))
		{
			system("clear");
			printf("\n\n-------------------------------------------------\n");
			printf("  TRABAJOS DE BICICLETA ID: %d       \n", idBicicleta);
			printf("-------------------------------------------------\n");
			printf("  ID     BICICLETA    SERVICIO           FECHA     \n");
			printf("-------------------------------------------------\n");

			for(int i = 0; i < cant_trabajos; i++)
			{
				if(trabajos[i].inactivo == 0 && trabajos[i].idBicicleta == idBicicleta)
				{
					mostrarTrabajoFila(trabajos[i], bicicletas, cant_bicicletas, servicios, cant_servicios);
					flag = 1;
				}
			}
			if(!flag)
			{
				system("clear");
				printf("No hay trabajos para la bicicleta con ID: %d", idBicicleta);
			}
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int importeServiciosBicicleta(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int idBicicleta;
	int indice;
	float importeTotal;

	if(trabajos != NULL && colores != NULL && tipos != NULL && cant_trabajos > 0 && bicicletas != NULL && cant_bicicletas > 0 && servicios != NULL && cant_servicios > 0 && clientes != NULL && cant_clientes > 0)
	{

		listarBicicletas(bicicletas, cant_bicicletas, colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes);

		if((get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 3000, 3100, &idBicicleta)) &&
			(validarBicicleta(bicicletas, cant_bicicletas, idBicicleta)))
		{
			system("clear");
			printf("\n\n-------------------------------------------------\n");
			printf(" PRECIO TOTAL DE SERVICIOS A BICICLETA ID: %d       \n", idBicicleta);
			printf("-------------------------------------------------\n");

			buscarPosicionPorIdBicicleta(bicicletas, cant_bicicletas, idBicicleta, &indice);
			sumaPreciosServicios(bicicletas[indice], trabajos, cant_trabajos, servicios, cant_servicios, &importeTotal);

			if (!importeTotal)
			{
				system("clear");
				printf("No se le han hecho servicios a esta bicicleta.\n\n");
			}
			else
			{
				printf(" $%.2f", importeTotal);
			}

		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int sumaPreciosServicios(eBicicleta bicicleta, eTrabajo trabajos[], int cant_trabajos, eServicio servicios[], int cant_servicios, float* pImporteTotal)
{
	int retorno = 0;
	float acumImporte = 0;
	int flag = 0;

	if(trabajos != NULL && cant_trabajos > 0 &&  servicios != NULL && cant_servicios > 0 && pImporteTotal != NULL)
	{
		*pImporteTotal = 0;

		for(int i = 0; i < cant_trabajos; i++)
		{
			if(trabajos[i].idBicicleta == bicicleta.id && trabajos[i].inactivo == 0)
			{
				for(int j = 0; j < cant_servicios; j++)
				{
					if(trabajos[i].idServicio == servicios[j].id)
					{
						acumImporte += servicios[j].precio;
						flag = 1;
					}
				}
			}
		}
		if(flag)
		{
			*pImporteTotal = acumImporte;
		}
		retorno = 1;

	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int bicicletasFechasSegunServicio(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int idServicio;
	int indiceServicio;
	int flag = 0;

	if(trabajos != NULL && colores != NULL && tipos != NULL && cant_trabajos > 0 && cant_colores > 0 && bicicletas != NULL && cant_bicicletas > 0 && servicios != NULL && cant_servicios > 0 && clientes != NULL && cant_clientes > 0)
	{
		listarServicios(servicios, cant_servicios);

		if(get_int("\nElija e ingrese un ID: ", "Dato Incorrecto\n\n", 20000, 20003, &idServicio))
		{
			buscarPosicionPorIdServicio(servicios, cant_servicios, idServicio, &indiceServicio);

			system("clear");
			printf("\n\n------------------------------------------------------------------------------------------------------\n");
			printf("  BICICLETAS CON SERVICIO DE %s \n", servicios[indiceServicio].descripcion);
			printf("------------------------------------------------------------------------------------------------------\n");
			printf("  ID      MARCA           COLOR           TIPO             MATERIAL        CLIENTE          FECHA   \n");
			printf("------------------------------------------------------------------------------------------------------\n");
			for( int i = 0; i < cant_bicicletas; i++)
			{
				if(trabajos[i].idServicio == idServicio && trabajos[i].inactivo == 0)
				{
					for(int j = 0; j < cant_bicicletas; j++)
					{
						if(trabajos[i].idBicicleta == bicicletas[j].id && bicicletas[j].inactivo == 0)
						{
							mostrarBicicletaFilaFecha(bicicletas[j], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
							flag = 1;
						}
					}
				}
			}
			if(!flag)
			{
				system("clear");
				printf("No hay bicicletas con el servicio de %s.\n\n", servicios[indiceServicio].descripcion);
			}
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ServiciosSegunFecha(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes)
{
	int retorno = 0;
	int flag = 0;
	eFecha fecha;
	int posBicicleta;
	int posServicio;

	if(trabajos != NULL && colores != NULL && tipos != NULL && cant_trabajos > 0 && bicicletas != NULL && cant_bicicletas > 0 && servicios != NULL && cant_servicios > 0 && clientes != NULL && cant_clientes > 0)
	{
		system("clear");
		if((ingresarFecha(&fecha, 1, 31, 1, 12, 2020, 2024)) && validarFecha(fecha.dia, fecha.mes, fecha.anio))
		{
			system("clear");
			printf("\n\n------------------------------------------------------------------------------------------------------\n");
			printf("  SERVICIOS REALIZADOS EL %02d/%02d/%4d\n", fecha.dia, fecha.mes, fecha.anio);
			printf("------------------------------------------------------------------------------------------------------\n");
			printf(" SERVICIO     PRECIO     ID     MARCA           COLOR           TIPO            MATERIAL     CLIENTE    \n");
			printf("------------------------------------------------------------------------------------------------------\n");


			for(int i = 0; i < cant_trabajos; i++)
			{
				if(trabajos[i].fecha.dia == fecha.dia && trabajos[i].fecha.mes == fecha.mes && trabajos[i].fecha.anio == fecha.anio &&
				   trabajos[i].inactivo == 0)
				{
					buscarPosicionPorIdBicicleta(bicicletas, cant_bicicletas, trabajos[i].idBicicleta, &posBicicleta);
					buscarPosicionPorIdServicio(servicios, cant_servicios, trabajos[i].idServicio, &posServicio);

					mostrarBicicletaFilaServicio(bicicletas[posBicicleta], colores, cant_colores, tipos, cant_tipos, clientes, cant_clientes, servicios[posServicio]);
					flag = 1;
				}
			}
			if(!flag)
			{
				system("clear");
				printf("No hay servicios realizados el %02d/%02d/%4d\n", fecha.dia, fecha.mes, fecha.anio);
			}
		}
		retorno = 1;
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

