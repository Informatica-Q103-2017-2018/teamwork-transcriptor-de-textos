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
			
									
//meter aki lo gordo (del codigo) 8==D

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
