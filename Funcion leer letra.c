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
