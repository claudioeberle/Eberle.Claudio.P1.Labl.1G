#include "cliente.h"
#include "color.h"
#include "fecha.h"
#include "input.h"
#include "servicio.h"
#include "tipo.h"


#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct{

	int id;
	char marca[20];
	int idTipo;
	int idColor;
	char material;
	int idCliente;
	int inactivo;

}eBicicleta;

#endif /* BICICLETA_H_ */


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recorre el array que recibe y busca la primera posicion que hay libre para poder escribir e informe la posicion por referencia
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param pIndice puntero a entero donde se escribirá el indice encontrado.
/// @return 1 todoOK, 0 error
int buscarBicicletaLibre(eBicicleta bicicletas[], int cant_bicicletas, int* pIndice);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief inicializa el campo inactivo de todos los elementos del array en 1
///
/// @param bicicletas
/// @param cant_bicicletas
/// @return 1 todoOK, 0 error
int inicializarBicicletas(eBicicleta bicicletas[], int cant_bicicletas);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief funcion para dar de alta una nueva bicicleta en el array de bicicletas, solicita al usuario los datos necesarios, los valida y pide confirmacion antes de grabar
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @param pProximoBicicleta
/// @param indice
/// @return 1 tododOK || 0 error
int altaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, int* pProximoBicicleta);

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
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @param pProximoBicicleta
/// @param indice
/// @return
int modificarBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief busca entre los elementos del array coincidencia entre el campo id y el id informado.
/// Si la encuentra informa la posicion del elemento por referencia
///
/// @param array de elementos
/// @param cant_array cant cant de elementos en el array
/// @param id que se desea validar
/// @param pPosicion puntero a entero para informar la posicion del elemento encontrado
/// @return 1 si se encuentra coincidencia, 0 sino
int buscarPosicionPorIdBicicleta(eBicicleta array[], int cant_array, int id, int* pPosicion);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estrctura y muestra todos sus campos en una única columna
///
/// @param elemento de tipo estrcutura bicicleta
/// @param array colores
/// @param cant_colores
/// @param array tipos de bicicleta
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int mostrarBicicleta(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estrctura y muestra todos sus campos en una única fila
///
/// @param elemento de tipo estructura bicicleta
/// @param array colores
/// @param cant_colores
/// @param array tipos de bicicleta
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int mostrarBicicletaFila(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe array y muestra todos sus elementos en unlistado
///
/// @param array de bicicletas
/// @param cant_bicicletas
/// @param array colores
/// @param cant_colores
/// @param array tipos de bicicleta
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int listarBicicletas(eBicicleta array[], int cant_array, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief le muestra al usuario al lista de bicicletas activas, le pide un id, le muestra el bicicleta, le pide al usuario confirmacion y procede a la baja
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 si sa logra el cometido de la funcion, 0 si no
int bajaBicicleta(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief hardcodea al array recibido la cantidad de datos indicados por el usuario y le asigna el valor de id correlativo
///
/// @param array bicicletas
/// @param cant_bicicletas
/// @param cantidad de datos a ingresar
/// @param pProximoBicicleta puntero a variable de IDs correlativas
/// @return 1 si logra hardcodear al menos un dato || 0 si no logra hardcodear ningun dato
int hardcodearBicicletas(eBicicleta bicicletas[], int cant_bicicletas, int cantidad, int* pProximoBicicleta);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief valida si el id informado corresponde a al id de los elementos en el array
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param bicicletaId a validar
/// @return 1 si valida || 0 si no valida
int validarBicicleta(eBicicleta bicicletas[], int cant_bicicletas, int bicicletaId);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief ordena el array de bicicletas por el campo 'tipo'
///
/// @param bicicletas
/// @param cant_bicicletas
/// @return
int ordenarBicicletasTipo (eBicicleta bicicletas[], int cant_bicicletas);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe una estructura y muestra todos sus campos en una única fila + fecha pasada como argumento
///
/// @param elemento
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @param dia
/// @param mes
/// @param anio
/// @return
int mostrarBicicletaFilaFecha(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, int dia, int mes, int anio);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief  recibe una estructura y muestra todos sus campos en una única fila + servicio pasado como argumento
///
/// @param elemento
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @param servicio
/// @return
int mostrarBicicletaFilaServicio(eBicicleta elemento, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes, eServicio servicio);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
