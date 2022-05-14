
#include "fecha.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{

	int id;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int inactivo;

}eTrabajo;

#endif /* TRABAJO_H_ */


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recorre el array que recibe y busca la primera posicion que hay libre para poder escribir e informe la posicion por referencia
///
/// @param trabajos
/// @param max_trabajos
/// @param pIndice puntero a entero donde se escribirá el indice encontrado
/// @return 1 todoOK, 0 error
int buscarTrabajoLibre(eTrabajo trabajos[], int max_trabajos, int* pIndice);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief inicializa el campo inactivo de todos los elementos del array en 1
///
/// @param trabajos
/// @param max_trabajos
/// @return 1 todoOK, 0 error
int inicializarTrabajos(eTrabajo trabajos[], int max_trabajos);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief
///
/// @param trabajos
/// @param cant_trabajos
/// @param aerolineas
/// @param cant_aerolineas
/// @param tipos
/// @param cant_tipos
/// @param pProximoTrabajo
/// @param indice
/// @return
int altaTrabajo(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, int* pProximoTrabajo);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief
///
/// @return
int menuModificarTrabajo(void);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief
///
/// @param trabajos
/// @param cant_trabajos
/// @param aerolineas
/// @param cant_aerolineas
/// @param tipos
/// @param cant_tipos
/// @param pProximoTrabajo
/// @param indice
/// @return
int modificarTrabajo(eTrabajo trabajos[], int cant_trabajos, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief busca entre los elementos del array coincidencia entre el campo id y el id informado.
/// Si la encuentra informa la posicion del elemento por referencia
///
/// @param array de elementos
/// @param cant_array cant max de elementos en el array
/// @param id que se desea validar
/// @param pPosicion puntero a entero para informar la posicion del elemento encontrado
/// @return 1 si se encuentra coincidencia, 0 sino
int buscarPosicionPorIdTrabajo(eTrabajo array[], int cant_array, int id, int* pPosicion);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estrctura y muestra todos sus campos en una única columna
///
/// @param elemento de tipo estrcutura avion
/// @param array aerolineas
/// @param cant_aerolineas
/// @param array tipos de avion
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int mostrarTrabajo(eTrabajo elemento, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estrctura y muestra todos sus campos en una única fila
///
/// @param elemento de tipo estrcutura avion
/// @param array aerolineas
/// @param cant_aerolineas
/// @param array tipos de avion
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int mostrarTrabajoFila(eTrabajo elemento, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe array y muestra todos sus elementos en unlistado
///
/// @param array de trabajos
/// @param cant_trabajos
/// @param array aerolineas
/// @param cant_aerolineas
/// @param array tipos de avion
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int listarTrabajos(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief le muestra al usuario al lista de trabajos activas, le pide un id, le muestra el avion, le pide al usuario confirmacion y procede a la baja
///
/// @param trabajos
/// @param cant_trabajos
/// @param aerolineas
/// @param cant_aerolineas
/// @param tipos
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int bajaTrabajo(eTrabajo trabajos[], int cant_trabajos, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);
