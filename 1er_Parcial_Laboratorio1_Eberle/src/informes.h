#include "bicicleta.h"
#include "cliente.h"
#include "color.h"
#include "fecha.h"
#include "input.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"

#ifndef Z_INFORMES_H_
#define Z_INFORMES_H_



#endif /* Z_INFORMES_H_ */

/*//////////////////////////////////./////////////////////////////////////////////////////////////////////////////*/
/// @brief presenta un menu y devuelve la opcion elegida por el usuario
///
/// @return opcion elegida por el usuario
int menuInformes(void);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief segun la opcion devuelta por menuInformes entra a distintos opciones de informes
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
/// @return 1 todoOK || 0 error
int informes(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief pide un id de color al usuario y muestra las bicicletas que tienen ese color del array de bicicletas
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 todoOK || 0 error
int bicicletasSegunColor(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief se le indica un tipo de material por parametro y cuenta la cant de bicicletas en el array de ese material
/// y carga el valor en el puntero a entero que se pasa como argumento
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param material 'c' carbono | 'a' aluminio
/// @param pTotal puntero a entero
/// @return 1 todoOK || 0 error
int totalBicicletasPorMaterial(eBicicleta bicicletas[], int cant_bicicletas, char material, int* pTotal);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief cuenta la cantidad de bicicletas que hay de cada material 'c' carbono | 'a' aluminio y define el máximo,
/// la cantidad del mismo y lo muestra por consola
///
/// @param bicicletas
/// @param cant_bicicletas
/// @return 1 todoOK || 0 error
int MaterialMaximoCantidad(eBicicleta bicicletas[], int cant_bicicletas);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// @brief pide un id de tipo al usuario y muestra las bicicletas que tienen ese tipo del array de bicicletas
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 todoOK || 0 error
int bicicletasSegunTipo(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief muestra un listado de todas las bicicletas del array separadas por tipo
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 todoOK || 0 error
int bicicletasPorTipos(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief informa la cantidad de bicicletas que hay de un color y un tipo seleccionados por el usuario
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param colores
/// @param cant_colores
/// @param tipos
/// @param cant_tipos
/// @param clientes
/// @param cant_clientes
/// @return 1 todoOK || 0 error
int cantidadPorColorYTipo(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief se le pasa un color como argumento y cuenta la canidad de bicicletas que existen de ese color y anota ese valor en el puntero informado
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param color
/// @param pTotal puntero a entero donde se guardara el total de bicicletas
/// @return 1 todoOK || 0 error
int totalBicicletasPorColor(eBicicleta bicicletas[], int cant_bicicletas, eColor color, int* pTotal);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief informa los colores para los cuales existe mayor cantidad de bicicletas
///
/// @param bicicletas
/// @param cant_bicicletas
/// @param colores
/// @param cant_colores
/// @return 1 todoOK || 0 error
int colorMasElegido(eBicicleta bicicletas[], int cant_bicicletas, eColor colores[], int cant_colores);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief muestra un listado de los trabajos hechos a la bicicleta elegida por el usuario
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
/// @return 1 todoOK || 0 error
int trabajosSegunBicicleta(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief se le pasa una bicicleta y devuelve por referencia la suma de todos los importes de servicios que se le hicieron // si no se le
/// hicieron servicios entonces carga 0 en la variable pImporteTotal
///
/// @param bicicleta
/// @param trabajos
/// @param cant_trabajos
/// @param servicios
/// @param cant_servicios
/// @param pImporteTotal
/// @return 1 todoOK || 0 error
int sumaPreciosServicios(eBicicleta bicicleta, eTrabajo trabajos[], int cant_trabajos, eServicio servicios[], int cant_servicios, float* pImporteTotal);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief el usuario elige una bicicleta y se le informa la suma de los importes de todos los servicios realizados a la misma
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
/// @return 1 todoOK || 0 error
int importeServiciosBicicleta(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief el usuario elige un servicio y se istan todas las bicicletas a las que se les realizó el servicio
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
/// @return 1 todoOK || 0 error
int bicicletasFechasSegunServicio(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief el usuario ingresa una fecha y se listan los servicios realizados en esa fecha
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
/// @return 1 todoOK || 0 error
int ServiciosSegunFecha(eTrabajo trabajos[], int cant_trabajos, eBicicleta bicicletas[], int cant_bicicletas, eServicio servicios[], int cant_servicios, eColor colores[], int cant_colores, eTipo tipos[], int cant_tipos, eCliente clientes[], int cant_clientes);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

