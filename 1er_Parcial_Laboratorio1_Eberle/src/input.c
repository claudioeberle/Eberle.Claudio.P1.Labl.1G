#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*/////////////////////////////////.//////////////////////////////////////////////////////////////////////////////*/

int menu(void){

	char opcion;

	do{

		printf("\n--------------------------------------\n");
		printf("   SISTEMA DE GESTIÓN DE BICICLETAS   \n");
		printf("-------------------------------------- \n\n");
		printf("A. ALTA BICICLETA\n\n");
		printf("B. MODIFICAR BICICLETA\n\n");
		printf("C. BAJA BICICLETA\n\n");
		printf("D. LISTAR BICICLETAS\n\n");
		printf("E. LISTAR TIPOS\n\n");
		printf("F. LISTAR COLORES\n\n");
		printf("G. LISTAR SERVICIOS\n\n");
		printf("H. ALTA TRABAJO\n\n");
		printf("I. LISTAR TRABAJOS\n\n");
		printf("J. INFORMES\n\n");
		printf("K. SALIR\n\n");

		getCharacter("Elija una opción: ","OPCIÓN INCORRECTA. Por favor ingrese una opción válida.\n\n", &opcion);

		}while((opcion < 'A' || opcion > 'K') && (opcion < 'a' || opcion > 'k'));

		return opcion;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int salir(char* var){

	int retorno = 0;
	char opcion;

	if(var != NULL){

		printf("Confirmar salida.\n");
		printf("Ingrese 's' para salir: ");
		fpurge(stdin);
		scanf("%c", &opcion);
		system("clear");

		if(opcion == 's' || opcion == 'S'){

			*var = opcion;
			retorno = 1;
			despedir();
		}
	}
	else{

		printf("*ERROR* - Reinicie e intente nuevamente.");
	}


	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void saludar (){

	system("clear");
	printf("\n''''''''''''''''''''''''''''''' \n");
	printf("    Bienvenido  a SIGBI®        \n");
	printf("\n''''''''''''''''''''''''''''''' \n");

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void despedir (){

	system("clear");
	printf("¡Hasta Luego!\n\n\n\n");
	printf("\n''''''''''''''''''''''''''''''' \n");
	printf("Gracias por utilizar SIGBI®. \n\n");
	printf("\n''''''''''''''''''''''''''''''' \n");


}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int get_int(char* mensaje, char* mensajeError, int min, int max, int* pNumero)
{

	int retorno = 0;
	int reintentos = 2;
	char string[10];
	int auxNum;

	if(pNumero != NULL){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(string, 10, stdin);

			for(int i = 0; i < 10; i++){

				if(string[i] == '\n'){

					string[i] = '\0';
					break;
				}
			}

			if(esNumero(string, 10) == 1){

				auxNum = atoi(string);

				if(auxNum >= min && auxNum <= max){

					*pNumero = auxNum;
					retorno = 1;
					break;
				}
				else{
					printf("%s", mensajeError);
					reintentos--;
				}
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}


		}while(reintentos > 0);


	}


	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int esNumero(char string[], int max_string)
{

	int retorno = 1;

	if (string != NULL && max_string > 0){

		for(int i = 0; string[i] != '\0'; i ++){

			if( i==0 && (string[i] == '+' || string[i] == '-')){

				continue;
			}
			if(string[i] > '9' || string[i] < '0'){

				retorno = 0;
			}

		}

	}

	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int get_float(char* mensaje, char* mensajeError, int min, int max, float* pNumero)
{

	int retorno = 0;
	int reintentos = 3;
	char string[100];
	float auxNum;

	if(pNumero != NULL){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(string, 100, stdin);

			if(quitarEnter (string, 100) && esFloat(string, 100)){

				auxNum = atof(string);

				if(auxNum > min && auxNum < max){

					*pNumero = auxNum;
					retorno = 1;
					break;
				}
				else{
					printf("Dato inválido. Reintente.\n");
					reintentos--;
				}
			}
			else{
			printf("Dato inválido. Reintente.\n");
			reintentos--;
			}


		}while(reintentos > 0);


	}


	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int esFloat(char string[], int max_string)
{

	int retorno = 1;
	int flag = 0;

	if (string != NULL && max_string > 0){

		for(int i = 0; string[i] != '\0'; i ++){

			if( i==0 && (string[i] == '+' || string[i] == '-')){

				continue;
			}
			if(flag == 1 && string[i] == '.'){

				retorno = 0;
				break;
			}

			if(string[i] == '.'){

				flag = 1;
				continue;
			}

			if(string[i] > '9' || string[i] < '0'){

				retorno = 0;
				break;
			}

		}

	}

	return retorno;

}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int quitarEnter (char string[], int max_string)
{

	int retorno = 0;
	char aux[max_string];

	strncpy(aux, string, max_string);

	if(string != NULL && max_string > 0){

		for(int i = 0; i < max_string; i++){

			if(aux[i] == '\n'){

				aux[i] = '\0';
				strncpy(string, aux, max_string);
				retorno = 1;

				break;
			}
		}

		if(!retorno){

			printf("No se ha podido procesar la solicitud. Dato demasiado largo.\n");
		}
	}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int capitalString (char string[])
{

		int retorno = 0;

		if( string != NULL){

			for (int i = 0; string[i] != '\0'; i++){


					string[i] = tolower(string[i]);
			}

			string [0] = toupper(string[0]);

			for (int i = 0; string[i] != '\0'; i++){

				if (string[i] == ' '){

					string[i+1] = toupper(string[i+1]);
				}
			}

			retorno = 1;
		}
	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int getCharacter(char* mensaje, char* mensajeError, char* character){

	int retorno = 0;
	char opcion;
	int check;
	int reintentos = 2;

	if(character != NULL)
	{
		do{
		printf("%s", mensaje);
		fpurge(stdin);
		check = scanf("%c", &opcion);

		opcion = tolower(opcion);

		if(isalpha(opcion))
		{
			*character = opcion;
			retorno = 1;
			break;
		}
		else{

			printf("%s", mensajeError);
			reintentos--;
		}
		}while(reintentos > 0);
	}

	return retorno;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargaString (char string[], int max_string, char* mensaje, char* mensajeError){
	int retorno = 0;
	int reintentos = 3;
	int flag = 0;
	char aux[max_string];
	if(string != NULL && max_string > 0){

		do{
			printf("%s", mensaje);
			fpurge(stdin);
			fgets(aux, max_string, stdin);

			if(quitarEnter(aux, max_string) && !(strlen(aux) == 0))
			{

				flag = 0;

				for(int i = 0; aux[i] != '\0'; i++)
				{

					if(i != 0 && aux[i] == ' ')
					{

						continue;

					}
					if(!isalpha(aux[i]) || aux[0] == ' '){

						flag = 1;
						reintentos --;
						printf("%s", mensajeError);
						break;
					}
				}
				if(!flag)
				{
					retorno = 1;
					capitalString (aux);
					strncpy(string, aux, max_string);
					break;
				}
			}
			else
			{
				flag = 1;
				reintentos --;
				printf("%s", mensajeError);

			}


		}while(reintentos > 0);

	}

	if (!reintentos){

		printf("\nNo se ha podido ingresar el dato.");
	}
	return retorno;
}
