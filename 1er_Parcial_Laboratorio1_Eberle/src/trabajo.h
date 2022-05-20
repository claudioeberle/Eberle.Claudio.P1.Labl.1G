
#include "bicicleta.h"
#include "color.h"
#include "fecha.h"
#include "input.h"
#include "servicio.h"
#include "tipo.h"

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


/*////////////////////////////.///////////////////////////////////////////////////////////////////////////////////*/
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
/// @param bicicletas
/// @param cant_bicicletas
/// @param servicios
/// @param cant_servicios
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @param pProximoTrabajo
/// @return
int altaTrabajo(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, int* pProximoTrabajo);

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
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
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
/// @brief  recibe el elemento de un array y muestra todos sus campos en columna
///
/// @param elemento
/// @param bicicletas
/// @param cant_bicicletas
/// @param servicios
/// @param cant_servicios
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return
int mostrarTrabajo(eTrabajo elemento, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estrctura y muestra todos sus campos en una única fila
///
/// @param elemento
/// @param bicicletas
/// @param cant_bicicletas
/// @param servicios
/// @param cant_servicios
/// @return
int mostrarTrabajoFila(eTrabajo elemento, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe array y muestra todos sus elementos en un listado
///
/// @param trabajos
/// @param cant_trabajos
/// @param bicicletas
/// @param cant_bicicletas
/// @param servicios
/// @param cant_servicios
/// @return
int listarTrabajos(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief hardcodea al array recibido la cantidad de datos indicados por el usuario y le asigna el valor de id correlativo
///
/// @param trabajos
/// @param cant_trabajos
/// @param cantidad
/// @param pProximotrabajo
/// @return 1 si logra hardcodear al menos un dato || 0 si no logra hardcodear ningun dato
int hardcodearTrabajos(eTrabajo trabajos[], int cant_trabajos, int cantidad, int* pProximotrabajo);
