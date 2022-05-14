
#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */

int menu(void);
int salir(char* var);
void bienvenida ();
void despedida ();


int get_int(char* mensaje, char* mensajeError, int min, int max, int* pNumero);
int esNumero(char string[], int max_string);
int get_code(char* mensaje, char* mensajeError, char codigo[], int max_codigos);
int get_float(char* mensaje, char* mensajeError, int min, int max, float* pNumero);
int esFloat(char string[], int max_string);
int quitarEnter (char string[], int max_string);
int capitalString (char string[]);
int getCharacter(char* mensaje, char* mensajeError, char* character, char min, char max);
int cargaString (char string[], int max_string, char* mensaje, char* mensajeError);