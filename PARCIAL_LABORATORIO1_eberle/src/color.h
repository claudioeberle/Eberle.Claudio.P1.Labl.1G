
#ifndef COLOR_H_
#define COLOR_H_

typedef struct{

	int id;
	char descripcion[20];


}eColor;

#endif /* COLOR_H_ */

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief busca entre los elementos del array coincidencia entre el campo id y el id informado.
/// Si la encuentra informa la posicion del elemento por referencia
///
/// @param array de elementos
/// @param cant_array cant max de elementos en el array
/// @param id que se desea validar
/// @param pPosicion puntero a entero para informar la posicion del elemento encontrado
/// @return 1 si se encuentra coincidencia, 0 sino
int buscarPosicionPorIdColor(eColor array[], int cant_array, int id, int* pPosicion);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief muestra por consola la descripcion del elemento estructura informado
///
/// @param un elemento estrcutura con un campo descripcion
void mostrarDescripcionColor( eColor colores[], int cant_colores, int colorId);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento de una estrcutura y muestra por consola y de forma encolumnada los campos que lo conforman
///
/// @param elmento de color estructura
void mostrarColor(eColor color);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento de una estrcutura y muestra por consola y en un sola fila los campos que lo conforman
///
/// @param elemento de tipo estructura
void mostrarColorFila(eColor color);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un array y muestra por consola una lista de los elementos que lo componen
///
/// @param array
/// @param cantidad elemento array
int listarColores(eColor array[], int cant_array);




