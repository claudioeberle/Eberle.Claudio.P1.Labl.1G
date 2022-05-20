#include "input.h"

#ifndef FECHA_H_
#define FECHA_H_

typedef struct{

	int dia;
	int mes;
	int anio;

}eFecha;

#endif /* FECHA_H_ */

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/// /// @brief solicita al usuario el ingreso de un entero dia, un entero mes y un entero anio.
/// Valida contra los valores minimos y maximos informados por parametro e carga la fecha por referecia a la variable informada
///
/// @param pFecha puntero a una variable de tio eFecha
/// @param minDia entero valor minimo para dia
/// @param maxDia entero valor maximo para dia
/// @param minMes entero valor minimo para mes
/// @param maxMes entero valor maximo para mes
/// @param minAnio entero valor minimo para anio
/// @param maxAnio entero valor maximo para anio
/// @return 1 si se logra cargar la variable con los tres datos correctos, 0 si no se logra
int ingresarFecha(eFecha* pFecha, int minDia, int maxDia, int minMes, int maxMes, int minAnio, int maxAnio);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief se le informa un anio y valida si se trata de un anio bisiesto
///
/// @param anio que se quiere validar
/// @return 1 si el anio es bisiesto || 0 si el anio NO es bisiesto
int anioBisiesto(int anio);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief se le informa un dia, un mes y un anio de una fecha y valida que los dias y meses se correspondan
///
/// @param dia
/// @param mes
/// @param anio
/// @return 1 si la fecha es válida || 0 si la fecha NO es válida
int validarFecha(int dia, int mes, int anio);
