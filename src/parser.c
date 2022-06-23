#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pPassenger;
	int todoOk = -1;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char codigoVuelo[50];
	char tipoPasajero[50];
	char estadoVuelo[50];
	int validacionId;
	int validacionNombre;
//	int validacionApellido;
	int validacionPrecio;
	int validacionCodigo;
	int validacionTipo;
	int validacionEstado;

	if(pFile !=NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		do{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
			validacionId = ValidateNumberIntWithoutRestriction(id);
			validacionNombre = ValidateString(nombre);
		//	validacionApellido = ValidateString(apellido);
			validacionPrecio =ValidateNumberFloat(precio, 0);
			validacionCodigo = ValidateStringWithNumbers(codigoVuelo);
			validacionTipo = ValidateString(tipoPasajero);
			validacionEstado = ValidateString(estadoVuelo);

		//	printf("%5s 		%25s  		%25s  		$%-20s 	%20s 	%20s  	%20s \n", id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

			if(validacionId != -1 && validacionNombre != -1   && validacionPrecio != -1  &&
					validacionCodigo != -1 && validacionTipo != -1  && validacionEstado != -1)
			{
				pPassenger = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
					if(pPassenger != NULL)
					{
						ll_add(pArrayListPassenger, pPassenger);
						todoOk = 0;
					}
			}

		}while(feof(pFile) == 0);
	}

	return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	Passenger* pPassenger = NULL;
	int todoOk = -1;

	if(pArrayListPassenger != NULL && pFile !=NULL)
	{
		do
		{
			pPassenger = Passenger_new();
			if(pPassenger != NULL)
				{
				if(fread(pPassenger,sizeof(Passenger),1,pFile)== 1)
				{
					todoOk = ll_add(pArrayListPassenger, pPassenger);
				}
			}
		}while(!feof(pFile));

	}
	return todoOk;
}

int guardarModoTexto(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	Passenger* pPassenger = NULL;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estadoVuelo;
	char auxIdChar[50];
	char auxPrecioChar[50];
	char auxTipoChar[50];
	char auxEstadoChar[50];

	fprintf(pFile,"id,name,lastName,price,flycode,typePassenger,statusFlight\n");

	for(int i=0; i<ll_len(pArrayListPassenger); i ++)
	{
		pPassenger = ll_get(pArrayListPassenger, i);
		if(pPassenger != NULL &&
		   Passenger_getId(pPassenger,&id) == 0 &&
		   Passenger_getNombre(pPassenger, nombre) == 0 &&
		   Passenger_getApellido(pPassenger, apellido) == 0 &&
		   Passenger_getPrecio(pPassenger, &precio) == 0 &&
		   Passenger_getCodigoVuelo(pPassenger, codigoVuelo) == 0 &&
		   Passenger_getTipoPasajero(pPassenger, &tipoPasajero) == 0 &&
		   Passenger_getEstado(pPassenger, &estadoVuelo) == 0 )
			{
				{
						itoa(id,auxIdChar,10);
						itoa(precio,auxPrecioChar,10);
						cargarDescEstado(estadoVuelo, auxEstadoChar);
						cargarDescTipo(tipoPasajero, auxTipoChar);
						fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",auxIdChar,nombre,apellido,auxPrecioChar,codigoVuelo,auxTipoChar,auxEstadoChar);
						todoOk = 0;
				}

			}

		}
	fclose(pFile);
	return todoOk;
}

int guardarModoBinario(FILE* pFile , LinkedList* pArrayListPassenger, char* path)
{
	int todoOk = -1;
	Passenger* pPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		if(pFile !=NULL)
		{
			for(int i = 0; i<ll_len(pArrayListPassenger); i++)
			{
					pPassenger = ll_get(pArrayListPassenger,i);
					if(pPassenger !=NULL)
					{
						fwrite(pPassenger,sizeof(Passenger),1,pFile);
						todoOk = 0;
					}
			}
		}
	}
	return todoOk;
}

