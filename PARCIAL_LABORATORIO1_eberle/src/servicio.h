

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{

	int id;
	char descripcion[25];
	float precio;

}eServicio;

#endif /* SERVICIO_H_ */


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief busca entre los elementos del array coincidencia entre el campo id y el id informado.
/// Si la encuentra informa la posicion del elemento por referencia
///
/// @param array de elementos
/// @param cant_array cant max de elementos en el array
/// @param id que se desea validar
/// @param pPosicion puntero a entero para informar la posicion del elemento encontrado
/// @return 1 si se encuentra coincidencia, 0 sino
int buscarPosicionPorIdServicio(eServicio array[], int cant_array, int id, int* pPosicion);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief muestra por consola la descripcion del elemento estructura informado
///
/// @param un elemento estrcutura con un campo descripcion
void mostrarDescripcionServicio (eServicio servicios[], int cant_servicios, int servicioId);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento estrcutura y muestra por consola y de forma encolumnada los campos que lo conforman
///
/// @param elemento de tipo estructura
void mostrarServicio(eServicio elemento);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento estrcutura y muestra por consola y en un sola fila los campos que lo conforman
///
/// @param elmento de tipo estructura
void mostrarServicioFila(eServicio elemento);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un array y muestra por consola una lista de los elementos que lo componen
///
/// @param array
/// @param cantidad elemento array
void listarServicios(eServicio array[], int cant_array);

