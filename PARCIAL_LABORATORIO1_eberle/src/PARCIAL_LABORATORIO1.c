

#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "fecha.h"
#include "input.h"
#include "color.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"



#define CANT_TIPOS 4
#define CANT_COLORES 5
#define CANT_SERVICIOS 4
#define CANT_BICICLETAS 100
#define CANT_TRABAJOS 100



int main(void) {

	setbuf(stdout,NULL);

	eTipo tipos[CANT_TIPOS] = {

		{1000, "Rutera"},
		{1001, "Carrera"},
		{1002, "Mountain"},
		{1003, "BMX"}

	};

	eColor colores[CANT_COLORES] = {

		{5000, "GRIS"},
		{5001, "BLANCO"},
		{5002, "AZUL"},
		{5003, "NEGRO"},
		{5004, "ROJO"}

	};

	eServicio servicios[CANT_SERVICIOS] = {

			{20000, "Limpieza", 30},
			{20001, "Parche", 400},
			{20002, "Centrado", 500},
			{20003, "Cadena", 450}

		};

	eBicicleta bicicletas[CANT_BICICLETAS];

	eTrabajo trabajos[CANT_TRABAJOS];

	inicializarBicicletas(bicicletas, CANT_BICICLETAS);
	inicializarTrabajos(trabajos, CANT_TRABAJOS);


	char salida = 'n';
	int proximoBicicleta = 30000;
	int proximoTrabajo = 0;




		do{
			switch(menu()){


					case 'a':

						altaBicicleta(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS, &proximoBicicleta);
						break;

					case 'b':

						modificarBicicleta(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS);
						break;

					case 'c':

						bajaBicicleta(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS);
						break;

					case 'd':

						listarBicicletas(bicicletas, CANT_BICICLETAS, colores, CANT_COLORES, tipos, CANT_TIPOS);
						break;

					case 'e':

						listarTipos(tipos, CANT_TIPOS);
						break;

					case 'f':

						listarColores(colores, CANT_COLORES);
						break;

					case 'g':

						listarServicios(servicios, CANT_SERVICIOS);
						break;

					case 'h':

						altaTrabajo(trabajos, CANT_TRABAJOS, bicicletas, CANT_BICICLETAS, servicios, CANT_SERVICIOS, colores, CANT_COLORES, tipos, CANT_TIPOS, &proximoTrabajo);
						break;

					case 'i':

						listarTrabajos(trabajos, CANT_TRABAJOS, bicicletas, CANT_BICICLETAS, servicios, CANT_SERVICIOS);
						break;

					case 'j':

						salir(&salida);

						break;


			}

		}while((salida != 's') || (salida != 'S'));


	return 0;
}
