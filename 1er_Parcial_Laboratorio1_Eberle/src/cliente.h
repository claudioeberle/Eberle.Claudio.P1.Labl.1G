

#ifndef Z_CLIENTE_H_
#define Z_CLIENTE_H_

typedef struct{

	int id;
	char nombre[15];
	char sexo;

}eCliente;

#endif /* Z_CLIENTE_H_ */


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief busca entre los elementos del array coincidencia entre el campo id y el id informado.
/// Si la encuentra informa la posicion del elemento por referencia
///
/// @param array de elementos
/// @param cant_array cant max de elementos en el array
/// @param id que se desea validar
/// @param pPosicion puntero a entero para informar la posicion del elemento encontrado
/// @return 1 si se encuentra coincidencia, 0 sino
int buscarPosicionPorIdCliente(eCliente array[], int cant_array, int id, int* pPosicion);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief muestra por consola la descripcion del elemento estructura informado
///
/// @param un elemento estrcutura con un campo descripcion
void mostrarNombreCliente( eCliente clientes[], int cant_clientes, int clienteId);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento estructura y muestra por consola y de forma encolumnada los campos que lo conforman
///
/// @param elemento de cliente estructura
void mostrarCliente(eCliente cliente);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un elemento de una estrcutura y muestra por consola y en un sola fila los campos que lo conforman
///
/// @param elemento de tipo estructura
void mostrarClienteFila(eCliente cliente);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief recibe un array y muestra por consola una lista de los elementos que lo componen
///
/// @param array
/// @param cantidad elemento array
int listarClientes(eCliente array[], int cant_array);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/// @brief valida si el id informado corresponde a al id de los elementos en el array
///
/// @param clientes
/// @param cant_clientes
/// @param clienteId a validar
/// @return 1 si valida || 0 si no valida
int validarCliente(eCliente clientes[], int cant_clientes, int clienteId);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

