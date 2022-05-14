

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
