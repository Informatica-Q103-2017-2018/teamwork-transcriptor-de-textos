//PROGRAMA: COMANDO BANNER DE SISTEMAS UNIX
//MIGUEL VALIENTE Nº:52683
//ISABEL GÓMEZ   Nº:52382



#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARS 80  // La longitud máxima del texto que introduce el usuario


struct letrabanner
{
	char letra;
	char matriz[7][7];
};


struct letrabanner cadenadebanners[MAXCHARS]; //defino una cadena de estructuras para almacenar las letras y su representación en banner
char tipograf; // lo definimos como una variable global

void leerbannerdeletra(int posicion);
void transformarbanner(int posicion);


int main()
{
	//PRESENTACIÓN DEL PROGRAMA
	printf("Este programa es un COMANDO BANNER DE SISTEMAS UNIX.\nMuestra un texto en grande dibujando cada letra con una matriz 6x6.\n\n");

	//Variables

	int opcion, opcion2, i, j,k;
	char texto[MAXCHARS];


	tipograf = '#';




	do
	{
			printf("\nSeleccione una opcion: \n");
		printf("1-Elegir tipografia\n");
		printf("2-Mostrar banner\n");
		printf("3-Salir del programa\n");
	printf("Opcion: ");
		
		scanf("%d", &opcion);
		while (getchar() != '\n');
		printf("\n");

		switch (opcion)
		{
		case 1:
			printf("\n\tSeleccione una opcion de tipografia: \n");
			printf("\t\t1-Hashtag\n");
			printf("\t\t2-Asteriscos\n");
			printf("\t\t3-Arrobas\n");
			printf("\t\tOpcion: ");
			scanf("%d", &opcion2);
			while (getchar() != '\n');
			printf("\n");

			if (opcion2 == 1) tipograf = '#';
			else if (opcion2 == 2) tipograf = '*';
			else if (opcion2 == 3) tipograf = '@';
			else printf("\tValor incorrecto, se mantiene la tipografía existente\n");
			
			//PONEMOS AQUI LA OPCION DOS DEL SWITCH PARA CONSEGUIR QUE PIDA EL TEXTO DESPUES DE ELEGIR LA TIPOGRAFIA SIN TENER QUE REPETIR EL MENU PRINCIPAL. 
			printf("\tIntroduzca el texto:"); 
			gets(texto);    // usamos la función gets porque coge espacios
			
			if (strlen(texto) >= 25)
			{
				printf("\n\tEl texto debe ser menor de 25 caracteres.\n");
			}

			else
			{
				for (i = 0; i < strlen(texto); i++)  //Este es un bucle donde voy a tratar cada letra del texto
				{                                    //Strlen() me mide la longitud del texto



					if (texto[i] == ' ')
					{    // si la letra es un espacio, relleno las 6 lineas de la matriz con "      ".
						cadenadebanners[i].letra = ' ';
						for (j = 0; j < 6; j++)
							strcpy(cadenadebanners[i].matriz[j], "      ");
					}

					else if (texto[i] >= 'A' && texto[i] <= 'Z')     //Me aseguro de que la letra que trato es una mayuscula entre la A y la Z
					{
						cadenadebanners[i].letra = texto[i];   // Le doy una posición en el banner a cada letra del texto 
						leerbannerdeletra(i);   // Leo la matriz de la letra en mi fichero 
						transformarbanner(i);   // Transformo la cadena de estructuras de # a la tipografía seleccionada

					}
					else if (texto[i] >= 'a' && texto[i] <= 'z')
					{
						//convierte primero la letra a mayuscula restandole 32 (códigos ASCII)

						cadenadebanners[i].letra = texto[i] - 32;
						leerbannerdeletra(i);
						transformarbanner(i);
					}
					else
					{ // no es letra ni espacio y lo rellenamos con una matriz 6x6 con la tipografia seleccionada
						cadenadebanners[i].letra = texto[i];
						for (j = 0; j < 6; j++)
							for (k = 0; k < 6; k++)
								cadenadebanners[i].matriz[j][k] = tipograf;
						transformarbanner(i);
					}

				}


				// Imprimir texto en HORIZONTAL:

				for (j = 0; j < 6; j++)
				{
					for (i = 0; i < strlen(texto); i++)
					{
						printf("%s ", cadenadebanners[i].matriz[j]);
					}
					printf("\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
				}
			}
			

			break;


		case 2:
			// Pedir al usuario un texto.
			// Cargar cada letra desde fichero a un string de matrices de 6x6
			// (Si alguna letra no tiene tipografía creada deberá mostrar en su lugar una matriz 6x6 con el carácter #)
			// Hacemos el cambio de # a la tipografía seleccionada.
			// Mostrar banner 


			printf("\tIntroduzca el texto:"); 
			gets(texto);    // usamos la función gets porque coge espacios
			
			if (strlen(texto) >= 25)
			{
				printf("\n\tEl texto debe ser menor de 25 caracteres.\n");
			}

			else
			{
				for (i = 0; i < strlen(texto); i++)  //Este es un bucle donde voy a tratar cada letra del texto
				{                                    //Strlen() me mide la longitud del texto



					if (texto[i] == ' ')
					{    // si la letra es un espacio, relleno las 6 lineas de la matriz con "      ".
						cadenadebanners[i].letra = ' ';
						for (j = 0; j < 6; j++)
							strcpy(cadenadebanners[i].matriz[j], "      ");
					}

					else if (texto[i] >= 'A' && texto[i] <= 'Z')     //Me aseguro de que la letra que trato es una mayuscula entre la A y la Z
					{
						cadenadebanners[i].letra = texto[i];   // Le doy una posición en el banner a cada letra del texto 
						leerbannerdeletra(i);   // Leo la matriz de la letra en mi fichero 
						transformarbanner(i);   // Transformo la cadena de estructuras de # a la tipografía seleccionada

					}
					else if (texto[i] >= 'a' && texto[i] <= 'z')
					{
						//convierte primero la letra a mayuscula restandole 32 (códigos ASCII)

						cadenadebanners[i].letra = texto[i] - 32;
						leerbannerdeletra(i);
						transformarbanner(i);
					}
					else
					{ // no es letra ni espacio y lo rellenamos con una matriz 6x6 con la tipografia seleccionada
						cadenadebanners[i].letra = texto[i];
						for (j = 0; j < 6; j++)
							for (k = 0; k < 6; k++)
								cadenadebanners[i].matriz[j][k] = tipograf;
						transformarbanner(i);
					}

				}


				// Imprimir texto en HORIZONTAL:

				for (j = 0; j < 6; j++)
				{
					for (i = 0; i < strlen(texto); i++)
					{
						printf("%s ", cadenadebanners[i].matriz[j]);
					}
					printf("\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
				}
			}

			break;



		case 3:  //Salir del programa 
			break;

		default:
			printf("Opcion incorrecta\n");
		}

	} while (opcion != 3);


	system("pause");



}

	//FUNCIONES

	void leerbannerdeletra(int posicion)

		//Posicion es donde va cada matriz letra en la cadena de estructuras

	{
		FILE *punteroafichero;

		char dummy[7]; //Dummy es para leer del fichero el retorno de carro que hay al final de cada fila de cada matriz de letra
		int j;
		int no_lineas_invalidas;  //nºde lineas invalidas que hay en el fichero hasta llegar a la linea de la matriz de cada letra

		punteroafichero = fopen("Hashtag.txt", "r");

		if (punteroafichero == NULL)

		{ //no existe el fichero y aviso al usuario
			printf("\t\tNo existe el fichero Hashtag.txt que debe de contener los banners de las letras");
		}

		else
		{ //leo lineas que no me interesan hasta la linea donde empieza la palabra
			no_lineas_invalidas = (cadenadebanners[posicion].letra - 'A') * 6;

				for (j = 0; j < no_lineas_invalidas; j++)
				{
					fgets(dummy, 7, punteroafichero);
					fgets(dummy, 2, punteroafichero);
				}

				for (j = 0; j < 6; j++)   //leo las seis filas de la letra que me interesa
				{
					fgets(cadenadebanners[posicion].matriz[j], 7, punteroafichero);
					fgets(dummy, 2, punteroafichero);
				}
			
		}
		fclose(punteroafichero);

	}



	void transformarbanner(int posicion)

		//Transformo la tipografía de la letra en la posición de la cadena de banners

	{
		int i, j;

		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < 7; j++)
			{
				if (cadenadebanners[posicion].matriz[i][j] == '#')
					cadenadebanners[posicion].matriz[i][j] = tipograf;
			}
		}
	}
