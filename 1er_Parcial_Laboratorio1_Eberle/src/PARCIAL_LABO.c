
#include <stdio.h>
#include <stdlib.h>

#include "bicicleta.h"
#include "cliente.h"
#include "color.h"
#include "fecha.h"
#include "informes.h"
#include "input.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"



#define CANT_TIPOS 4
#define CANT_COLORES 5
#define CANT_SERVICIOS 4
#define CANT_CLIENTES 10
#define CANT_BICICLETAS 100
#define CANT_TRABAJOS 100



int main(void) {

	setbuf(stdout,NULL);

	eTipo tipos[CANT_TIPOS] = {

		{1000, "BMX"},
		{1001, "Carrera"},
		{1002, "Mountain"},
		{1003, "Rutera"}

	};

	eColor colores[CANT_COLORES] = {

		{5000, "AZUL"},
		{5001, "BLANCO"},
		{5002, "GRIS"},
		{5003, "NEGRO"},
		{5004, "ROJO"}

	};

	eServicio servicios[CANT_SERVICIOS] = {

			{20000, "Limpieza", 30},
			{20001, "Parche", 400},
			{20002, "Centrado", 500},
			{20003, "Cadena", 450}

		};
	eCliente clientes[CANT_CLIENTES] = {

			{6000, "Mauro", 'm'},
			{6001, "Jimena", 'f'},
			{6002, "Pedro", 'm'},
			{6003, "Sabrina", 'f'},
			{6004, "Julian", 'm'},
			{6005, "Francisco", 'm'},
			{6006, "Felicitas", 'f'},
			{6007, "Silvia", 'f'},
			{6008, "Romina", 'f'},
			{6009, "Guillermo", 'm'}
	};

	eBicicleta bicicletas[CANT_BICICLETAS];

	eTrabajo trabajos[CANT_TRABAJOS];

	inicializarBicicletas(bicicletas, CANT_BICICLETAS);
	inicializarTrabajos(trabajos, CANT_TRABAJOS);

	char salida = 'n';
	int proximoBicicleta = 3000;
	int proximoTrabajo = 2000;

	hardcodearBicicletas(bicicletas, CANT_BICICLETAS, 10, &proximoBicicleta);
	hardcodearTrabajos(trabajos, CANT_TRABAJOS, 30, &proximoTrabajo);



		saludar();
		do{
			switch(menu()){

				case 'a':

					altaBicicleta(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS, clientes, CANT_CLIENTES, &proximoBicicleta);
					break;

				case 'b':

					modificarBicicleta(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS, clientes, CANT_CLIENTES);
					break;

				case 'c':

					bajaBicicleta(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS, clientes, CANT_CLIENTES);
					break;

				case 'd':

					system("clear");
					ordenarBicicletasTipo(bicicletas, CANT_BICICLETAS);
					listarBicicletas(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS, clientes, CANT_CLIENTES);
					break;

				case 'e':

					system("clear");
					listarTipos(tipos, CANT_TIPOS);
					break;

				case 'f':

					system("clear");
					listarColores(colores, CANT_COLORES);
					break;

				case 'g':

					system("clear");
					listarServicios(servicios, CANT_SERVICIOS);
					break;

				case 'h':

					altaTrabajo(trabajos, CANT_TRABAJOS, bicicletas, CANT_BICICLETAS, servicios, CANT_SERVICIOS, colores, CANT_COLORES, tipos, CANT_TIPOS, clientes, CANT_CLIENTES, &proximoTrabajo);
					break;

				case 'i':

					system("clear");
					listarTrabajos(trabajos, CANT_TRABAJOS, bicicletas, CANT_BICICLETAS, servicios, CANT_SERVICIOS);
					break;

				case 'j':

					system("clear");
					informes(trabajos, CANT_TRABAJOS, bicicletas, CANT_BICICLETAS, servicios, CANT_SERVICIOS, colores, CANT_COLORES, tipos, CANT_TIPOS, clientes, CANT_CLIENTES);
					break;

				case 'k':

					salir(&salida);
					break;

			}

		}while((salida != 's') && (salida != 'S'));


	return 0;
}
