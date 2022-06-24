#include "Controller.h"

void controller_Menu()
{
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
	    			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
	    			"3. Alta de pasajero\n"
	    			"4. Modificar datos de pasajero\n"
	    			"5. Baja de pasajero\n"
	    			"6. Listar pasajeros\n"
	    			"7. Ordenar pasajeros\n"
	    			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
	    			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
	    			"10. Salir\n\n");
}

int controller_CheckListStatus(LinkedList* pArrayListPassenger)
{

	int todoOk = -1;
	if(ll_isEmpty(pArrayListPassenger) == 0 )
	{
		todoOk = 0;
	}
	return todoOk;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	int todoOk = -1;


	pFile = fopen(path,"r");

	if(pFile != NULL)
	{
		todoOk = parser_PassengerFromText(pFile, pArrayListPassenger);

		if(todoOk == 0)
		{
			printf("Se cargo la lista correctamente\n\n");
		}

	}

	fclose(pFile);
    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
		FILE* pFile;
		int todoOk = -1 ;


		pFile = fopen(path,"rb");
		if(pFile != NULL)
		{

			todoOk  = parser_PassengerFromBinary(pFile, pArrayListPassenger);

			if (todoOk == 0)
			{
				printf("Se cargo la lista de binaria de manera correcta\n\n");
			}
		}
		fclose(pFile);


    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado)
{
	Passenger* pPassenger;
	int todoOk = -1;
		if(pArrayListPassenger != NULL)
		{
			if(controller_ListaVacia(pArrayListPassenger) == 0)
			{
				printf("Se ha cancelado la operacion\n\n");
			}
			else
			{
				pPassenger = addPassenger(tipo, tamTipo, estado, tamEstado);

				if(pPassenger != NULL)
				{

					if(ll_add(pArrayListPassenger, pPassenger) == 0)
					{
						printf("Se cargo al pasajero de manera correcta\n\n");
						todoOk = 0;
					}
					else
					{
						printf("Ocurrio un error al cargar al pasajero\n\n");
					}
				}
			}

		}

    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado)
{
	int todoOk;
	Passenger* pPassenger= NULL;

	if(pArrayListPassenger != NULL)
	{
		pPassenger= getPassengerPorId(pArrayListPassenger, tipo, tamTipo, estado, tamEstado);

		if(pPassenger != NULL)
		{
			system("cls");
			todoOk = editPassenger(tipo, tamTipo, estado, tamEstado, pPassenger);
			system("cls");
			if(todoOk == 0)
			{
				printf("Se edito al pasajero de manera correcta\n\n");
			}
			else if(todoOk == -1)
			{
				printf("Se cancelo la operacion \n\n");
			}
		}else
		{
			printf("No se encontro al pasajero en la base de datos \n\n");
		}
	}




    return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado)
{
	int todoOk;
	int index;
	Passenger* pPassenger= NULL;
	if(pArrayListPassenger != NULL)
		{
			pPassenger= getPassengerPorId(pArrayListPassenger, tipo, tamTipo, estado, tamEstado);
			if(pPassenger != NULL)
			{
				index = ll_indexOf(pArrayListPassenger, pPassenger);
				todoOk = removePassenger(pArrayListPassenger,tipo, tamTipo, estado, tamEstado, pPassenger ,index);
				if(todoOk == 0)
				{
					printf("Se elimino al pasajero de manera correcta\n\n");
				}
				else if(todoOk == -1)
				{
					printf("Se cancelo la operacion \n\n");
				}
			}else
			{
				printf("No se encontro al pasajero \n\n");
			}
		}
    return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado)
{

	int todoOk = -1;

	if(pArrayListPassenger != NULL)
	{
		  mostrarPasajeros(pArrayListPassenger, tipo, tamTipo, estado, tamEstado);
		  todoOk = 0;
	}
    return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk;

	todoOk = menuOrdenar(pArrayListPassenger);

	if(todoOk == 0)
	{
		printf("Se ordeno la lista de manera correcta\n\n");
	}
	else if(todoOk == 1)
	{
		printf("Se ha cancelado la operacion\n\n");
	}
	else
	{
		printf("Ocurrio un error al ordenar la lista\n\n");
	}
    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	int todoOk = -1;



		if(pArrayListPassenger != NULL)
		{
				pFile = fopen(path,"w");

				if(pFile != NULL)
				{
					todoOk = guardarModoTexto(pFile, pArrayListPassenger);

					if(todoOk ==  0)
					{
						printf("Se guardo lista correctamente\n\n");
					}
					else
					{
						printf("Ocurrio un error al guardar la lista\n\n");
					}
				}
		}
					fclose(pFile);
	    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	int todoOk = -1;

	pFile = fopen(path,"wb");

   if(pFile != NULL)
   {
	   todoOk =  guardarModoBinario(pFile, pArrayListPassenger, path);

	 if(todoOk != -1)
	 {
		 printf("Se guardo la lista de manera corecta\n\n");
	 }
	 else
	 {
		 printf("Ocurrio un error al guardar la lista\n\n");
	 }
   }

   return todoOk;
}


int controller_ListaVacia(LinkedList* pArrayListPassenger)
{
	int todoOk;
	int option;
	if(ll_isEmpty(pArrayListPassenger) == 1)
	{
		printf("No se cargo la lista previamente\n¿Estas seguro que quieres dar el alta a un empleado?\nPuede que los datos se sobrescriban si luego guarda\n1-Continuar\n2-Volver al menu\n ");
		option=EnterNumberInt("Selecciona una opcion: ", "\nError, selecciona una opcion valida\n", 2,1);
		switch(option)
		{
		case 1:
			todoOk =-1;
			break;
		case 2:
			todoOk = 0;
		}
	}
	return todoOk;
}

int controller_GenerarArchivoVuelo(LinkedList* pArrayListPassenger, char* path)
{
	int todoOk = 0;
	LinkedList* listaFiltrada = NULL;
	FILE* pArchivo = NULL;


	if(pArrayListPassenger != NULL && ll_isEmpty(pArrayListPassenger) != 1)
	{
		listaFiltrada = ll_filter(pArrayListPassenger, filtrarPorTipo);

		if(listaFiltrada != NULL)
		{
			pArchivo = fopen(path ,"w");

			if(pArchivo != NULL)
			{
				todoOk = controller_saveAsText(path, listaFiltrada);
			}
			fclose(pArchivo);
		}
	}

	return todoOk;
}

int controller_PasajerosPorClase(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int contadorPrim = 0;
	int contadoExe = 0;
	int contadorEco = 0;

	if(pArrayListPassenger != NULL)
	{
		contadorPrim = ll_count(pArrayListPassenger,contarPrim);
		contadorEco = ll_count(pArrayListPassenger,contarEco);
		contadoExe = ll_count(pArrayListPassenger,contarExe);

		printf("La cantidad de pasajeros en PrimaryClass es %d, la cantidad en ExecutiveClass es %d, y la cantidad en EcnomicClass es %d",contadorPrim,contadoExe,contadorEco);
	}

	return todoOk;
}


int controller_calcularMillas(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	if(pArrayListPassenger != NULL)
	{
		ll_map(pArrayListPassenger, calcularMillas);
	}

	return todoOk;
}

void calcularMillas (void* element)
{
	Passenger* pPass;
	int tipoPasajero;
	float precio;
	float millas;

	if(Passenger_getTipoPasajero(pPass,&tipoPasajero) == 0)
	{
		if(tipoPasajero == 1)
		{
			if(Passenger_getPrecio(pPass, &precio) == 0)
			{
				millas = precio / 100;
				millas = millas * 2;
				Passenger_setMillas(pPass, millas);
			}
		}
		else if (tipoPasajero == 2)
		{
			if(Passenger_getPrecio(pPass, &precio) == 0)
			{
				millas = precio / 100;
				millas = millas * 3;
				Passenger_setMillas(pPass, millas);
			}
		}
		else
		{
			if(Passenger_getPrecio(pPass, &precio) == 0)
			{
				millas = precio / 100;
				Passenger_setMillas(pPass, millas);
			}
		}
	}
}
