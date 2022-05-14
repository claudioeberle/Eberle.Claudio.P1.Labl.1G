#include "tipo.h"
#include "fecha.h"
#include "input.h"
#include "color.h"
#include "servicio.h"


#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct{

	int id;
	char marca[20];
	int idTipo;
	int idColor;
	char material;
	int inactivo;

}eBicicleta;

#endif /* BICICLETA_H_ */


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recorre el array que recibe y busca la primera posicion que hay libre para poder escribir e informe la posicion por referencia
///
/// @param bicicletas
/// @param max_bicicletas
/// @param pIndice puntero a entero donde se escribirá el indice encontrado
/// @return 1 todoOK, 0 error
int buscarBicicletaLibre(eBicicleta bicicletas[], int max_bicicletas, int* pIndice);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief inicializa el campo inactivo de todos los elementos del array en 1
///
/// @param bicicletas
/// @param max_bicicletas
/// @return 1 todoOK, 0 error
int inicializarBicicletas(eBicicleta bicicletas[], int max_bicicletas);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param aerolineas
/// @param cant_aerolineas
/// @param tipos
/// @param cant_tipos
/// @param pProximoBicicleta
/// @param indice
/// @return
int altaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, int* pProximoBicicleta);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief
///
/// @return
int menuModificarBicicleta(void);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param aerolineas
/// @param cant_aerolineas
/// @param tipos
/// @param cant_tipos
/// @param pProximoBicicleta
/// @param indice
/// @return
int modificarBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief busca entre los elementos del array coincidencia entre el campo id y el id informado.
/// Si la encuentra informa la posicion del elemento por referencia
///
/// @param array de elementos
/// @param cant_array cant max de elementos en el array
/// @param id que se desea validar
/// @param pPosicion puntero a entero para informar la posicion del elemento encontrado
/// @return 1 si se encuentra coincidencia, 0 sino
int buscarPosicionPorIdBicicleta(eBicicleta array[], int cant_array, int id, int* pPosicion);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estrctura y muestra todos sus campos en una única columna
///
/// @param elemento de tipo estrcutura avion
/// @param array aerolineas
/// @param cant_aerolineas
/// @param array tipos de avion
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int mostrarBicicleta(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estrctura y muestra todos sus campos en una única fila
///
/// @param elemento de tipo estrcutura avion
/// @param array aerolineas
/// @param cant_aerolineas
/// @param array tipos de avion
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int mostrarBicicletaFila(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe array y muestra todos sus elementos en unlistado
///
/// @param array de bicicletas
/// @param cant_bicicletas
/// @param array aerolineas
/// @param cant_aerolineas
/// @param array tipos de avion
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int listarBicicletas(eBicicleta array[], int cant_array, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief le muestra al usuario al lista de bicicletas activas, le pide un id, le muestra el avion, le pide al usuario confirmacion y procede a la baja
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param aerolineas
/// @param cant_aerolineas
/// @param tipos
/// @param cant_tipos
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int bajaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);
