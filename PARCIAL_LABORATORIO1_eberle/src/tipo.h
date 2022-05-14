
#ifndef TIPO_H_
#define TIPO_H_

typedef struct {

	int id;
	char descr[20];

}eTipo;

#endif /* TIPO_ */


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief busca entre los elementos del array coincidencia entre el campo id y el id informado.
/// Si la encuentra informa la posicion del elemento por referencia
///
/// @param array de elementos
/// @param cant_array cant max de elementos en el array
/// @param id que se desea validar
/// @param pPosicion puntero a entero para informar la posicion del elemento encontrado
/// @return 1 si se encuentra coincidencia, 0 sino
int buscarPosicionPorIdTipo(eTipo array[], int cant_array, int id, int* pPosicion);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief muestra por consola la descripcion del elemento estructura informado
///
/// @param un elemento estrcutura con un campo descripcion
void mostrarDescripcionTipo( eTipo tipos[], int cant_tipos, int tipoId);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento de una estrcutura y muestra por consola y de forma encolumnada los campos que lo conforman
///
/// @param elmento de tipo estructura
void mostrarTipo(eTipo tipo);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento de una estrcutura y muestra por consola y en un sola fila los campos que lo conforman
///
/// @param elmento de tipo estructura
void mostrarTipoFila(eTipo tipo);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un array y muestra por consola una lista de los elementos que lo componen
///
/// @param array
/// @param cantidad elemento array
int listarTipos(eTipo array[], int cant_array);




