#include "passenger.h"


Passenger* Passenger_new()
{
	Passenger* passenger;
	passenger = (Passenger*) malloc (sizeof(Passenger));
	return passenger;
}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoStr,char* tipoPasajeroStr,char* estadoStr)
{
	int passengerType;
	int passengerStatus;
	Passenger* passenger = Passenger_new();

	passengerType = compararTipos(tipoPasajeroStr);
	passengerStatus = compararEstados(estadoStr);

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoStr != NULL && tipoPasajeroStr != NULL && estadoStr != NULL && passenger != NULL)
	{
		Passenger_setId(passenger, atoi(idStr));
		Passenger_setNombre(passenger, nombreStr);
		Passenger_setApellido(passenger, apellidoStr);
		Passenger_setPrecio(passenger, atof(precioStr));
		Passenger_setCodigoVuelo(passenger, codigoStr);
		Passenger_setTipoPasajero(passenger, passengerType);
		Passenger_setEstado(passenger, passengerStatus);

	}
	return passenger;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int Passenger_setId(Passenger* this,int id)
{
	int todoOk = -1;

	if(this != NULL && id>0)
	{
		this->id = id;
		todoOk = 0;
	}

	return todoOk;
}


int Passenger_getMillas(Passenger* this,float* millas)
{

	int todoOk = -1;

	if(this != NULL)
	{
		*millas = this->millas;
		todoOk = 0;
	}

	return todoOk;
}
int Passenger_getId(Passenger* this,int* id)
{

	int todoOk = -1;

	if(this != NULL && id>0)
	{
		*id = this->id;
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk = -1;

	if(this != NULL &&  nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		todoOk = 0;
	}
	return todoOk;

}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		todoOk = 0;
	}

	return todoOk;
}



int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = -1;

	if(this != NULL && codigoVuelo != NULL )
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk = -1;

	if (this != NULL && (tipoPasajero >= 1 || tipoPasajero <= 4) )
	{
		this->tipoPasajero = tipoPasajero;
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_setMillas(Passenger* this,float millas)
{
	int todoOk = -1;

	if (this != NULL )
	{
		this->millas = millas;
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk = -1;

	if (this != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		todoOk = 0;
	}

	return todoOk;
}



int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = -1;

	if(this != NULL && precio > 0)
	{
		*precio = this-> precio;
		todoOk = 0;
	}

	return todoOk;
}

int Passenger_setEstado(Passenger* this, int estado)
{
	int todoOk = -1;

	if(this != NULL && (estado >= 1 || estado <= 3))
	{
		this->isEmpty = estado;
		todoOk = 0;
	}
	return todoOk;
}

int Passenger_getEstado(Passenger* this, int* estado)
{
	int todoOk = -1;

	if(this != NULL && (*estado >= 1 || *estado <= 3))
	{
		*estado = this ->isEmpty;
		todoOk = 0;
	}
	return todoOk;
}

void mostrarTipos(eTipoPass* tipos, int tam)
{
	printf("TIPO DE VUELO\n\n");
	for(int i = 0; i< tam; i ++)
	{
		printf("%d- %s\n",tipos[i].idTipo, tipos[i].descripcion);
	}
}

void mostrarEstadoDeVuelo(eEstadoPass* estados, int tam)
{
	printf("ESTADO DEL VUELO\n\n");
	for(int i = 0; i< tam; i ++)
	{
		printf("%d- %s\n",estados[i].idEstado, estados[i].descripcion);
	}
}

int compararTipos(char* tipoStr)
{
	int tipoPasajero;

	if(strcmp(tipoStr,"FirstClass") == 0)
	{
		tipoPasajero =1;
	}
	else if(strcmp(tipoStr,"ExecutiveClass") == 0)
	{
		tipoPasajero = 2;
	}
	else if(strcmp(tipoStr,"EconomyClass") == 0)
	{
		tipoPasajero = 3;
	}
	return tipoPasajero;
}

void cargarDescTipo(int tipo, char* tipoStr)
{
	if(tipo == 1)
	{
		strcpy(tipoStr,"FirstClass");
	}
	else if(tipo == 2)
	{
		strcpy(tipoStr,"ExecutiveClass");
	}
	else
	{
		strcpy(tipoStr,"EconomyClass");
	}
}

void cargarDescEstado(int estadoVuelo, char* estadoVueloStr)
{

	if(estadoVuelo == 1)
	{
		strcpy(estadoVueloStr,"Aterrizado");
	}
	else if(estadoVuelo == 2)
	{
		strcpy(estadoVueloStr,"En Horario");
	}
	else if(estadoVuelo == 3)
	{
		strcpy(estadoVueloStr,"En Vuelo");
	}
	else
	{
		strcpy(estadoVueloStr,"Demorado");
	}
}

int compararEstados(char* estadoStr)
{
	int estadoPasajero;

	if(strcmp(estadoStr,"Aterrizado") == 0)
	{
		estadoPasajero =1;
	}
	else if(strcmp(estadoStr,"En Horario") == 0)
	{
		estadoPasajero = 2;
	}
	else if(strcmp(estadoStr,"En Vuelo") == 0)
	{
		estadoPasajero =3;
	}
	else if(strcmp(estadoStr,"Demorado") == 0)
	{
		estadoPasajero =4;
	}
	return estadoPasajero;
}

void mostrarPasajeros(LinkedList* pArrayPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estadoVuelo, int tamEstado)
{
	Passenger* pPassenger = NULL;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estado;

	if(pArrayPassenger != NULL)
	{
		for(int i = 0; i < ll_len(pArrayPassenger) ; i++)
		{

			pPassenger = ll_get(pArrayPassenger, i);

			if(pPassenger != NULL &&
			   Passenger_getId(pPassenger,&id) == 0 &&
			   Passenger_getNombre(pPassenger, nombre) == 0 &&
			   Passenger_getApellido(pPassenger, apellido) == 0 &&
			   Passenger_getPrecio(pPassenger, &precio) == 0 &&
			   Passenger_getCodigoVuelo(pPassenger, codigoVuelo) == 0 &&
			   Passenger_getTipoPasajero(pPassenger, &tipoPasajero) == 0 &&
			   Passenger_getEstado(pPassenger, &estado) == 0 )
			{

				for(int j = 0; j < tamTipo ; j ++)
				{
					if(tipoPasajero == tipo[j].idTipo)
					{
						for(int k = 0; k< tamEstado;k ++)
						{
							if(estado == estadoVuelo[k].idEstado)
							{
								printf("%4d 	%25s 		%25s 			$%-10.2f 		%20s 	%20s 	%20s \n",id , nombre, apellido, precio, codigoVuelo, tipo[j].descripcion, estadoVuelo[k].descripcion);
							}
						}
					}
				}
			}
		}
	}
}

void mostrarPasajeroIndex(LinkedList* pArrayPassenger, eTipoPass* tipo ,int tamTipo, eEstadoPass* estadoVuelo, int tamEstado, int index)
{
	Passenger* pPassenger = NULL;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estado;

	if(pArrayPassenger != NULL)
	{
		pPassenger = ll_get(pArrayPassenger, index);

		if(pPassenger != NULL &&
		   Passenger_getId(pPassenger,&id) == 0 &&
		   Passenger_getNombre(pPassenger, nombre) == 0 &&
		   Passenger_getApellido(pPassenger, apellido) == 0 &&
		   Passenger_getPrecio(pPassenger, &precio) == 0 &&
		   Passenger_getCodigoVuelo(pPassenger, codigoVuelo) == 0 &&
		   Passenger_getTipoPasajero(pPassenger, &tipoPasajero) == 0 &&
		   Passenger_getEstado(pPassenger, &estado) == 0 )
		{

			for(int j = 0; j < tamTipo ; j ++)
			{
				if(tipoPasajero == tipo[j].idTipo)
				{
					for(int k = 0; k< tamEstado;k ++)
					{

							if(estado == estadoVuelo[k].idEstado)
							{
								printf("%4d 	%25s 		%25s 			$%-10.2f 		%20s 	%20s 	%20s \n",id , nombre, apellido, precio, codigoVuelo, tipo[j].descripcion, estadoVuelo[k].descripcion);
							}
					}
				}
			}
		}
	}
}
int incrementarId(char* path)
{
	FILE* pIdFile = NULL;
	int idAux;

	pIdFile = fopen(path, "rb");

	if(pIdFile !=NULL)
	{
		fread(&idAux,sizeof(int),1,pIdFile);
		idAux ++;
	}
	fclose(pIdFile);

	pIdFile = fopen(path, "wb");

	if(pIdFile != NULL)
	{
		fwrite(&idAux,sizeof(int),1,pIdFile);
	}
	fclose(pIdFile);

	return idAux;
}

int getIdMax(char* path)
{
	FILE* pFile = NULL;
	pFile = fopen(path,"r");
	int idAux;

	if(pFile !=NULL)
	{
		fread(&idAux,sizeof(int),1,pFile);
	}

	fclose(pFile);

	return idAux;
}


int buscarIndexPorId(LinkedList* pArrayListPassenger, int id)
{
	Passenger* pPassenger = NULL;
	int idAux;
	int index = -1;

	if(pArrayListPassenger != NULL)
	{
		for(int i= 0; i < ll_len(pArrayListPassenger); i++)
		{
			pPassenger = ll_get(pArrayListPassenger,i);
			if(pPassenger != NULL && Passenger_getId(pPassenger, &idAux) == 0 && id == idAux)
			{
				index = i;
			}
		}
	}

	return index;
}
Passenger* getPassengerPorId(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estadoVuelo, int tamEstado)
{
	int index;
	int idMax;
	int id;
	Passenger* pPassenger = NULL;
	Passenger* retornoPasajero = NULL;

	idMax = getIdMax("idFile.bin");
	mostrarPasajeros(pArrayListPassenger, tipo, tamTipo, estadoVuelo, tamEstado);
	id = EnterNumberInt("Ingrese el Id de un pasajero: ", "Error, ingrese un Id valido: ", idMax , 1);
	index = buscarIndexPorId(pArrayListPassenger, id);
	if(index != -1)
	{
		pPassenger = ll_get(pArrayListPassenger,  index);
		//printf("index %d\n",index);
		if(pPassenger != NULL && pPassenger->id  == id)
		{
			retornoPasajero = pPassenger;
		}
		else
		{
			retornoPasajero = NULL;
		}
	}
	return retornoPasajero;
}


Passenger* addPassenger(eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado)
{
	Passenger* pPassenger;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char codigoVuelo[50];
	char tipoPasajero[50];
	char estadoPasajero[50];
	int idAux;
	float auxPrecio;
	int auxTipo;
	int auxEstado;

	idAux = incrementarId("idFile.bin");
	EnterString("Ingrese el nombre del pasajero: ", nombre);
	EnterString("Ingrese el apellido del pasajero: ", apellido);
	auxPrecio = EnterNumberFloat("Ingrese el precio del vuelo: ", "Error, ha ingresado un precio invalido: ",0);
	mostrarTipos(tipo, tamTipo);
	auxTipo = EnterNumberInt("Ingrese la clase del pasajero: ", "Error, ingrese una opcion valida (1-3): ", 3, 1);
	EnterStringWithNumbers("Ingrese el codigo de vuelo del pasajero: ", codigoVuelo);
	mostrarEstadoDeVuelo(estado, tamEstado);
	auxEstado = EnterNumberInt("Ingrese el estado del vuelo: ", "Error, ingrese una opcion valida (1-4): ", 4, 1);

	itoa(idAux,id,10);
	itoa(auxPrecio,precio,10);
	cargarDescEstado(auxEstado, estadoPasajero);
	cargarDescTipo(auxTipo, tipoPasajero);
	NormalizeStringToUpper(codigoVuelo);

	pPassenger = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoPasajero);

	return pPassenger;
}

int editPassenger( eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado, Passenger* pPassenger)
{
	int todoOk = -1;
	int opcion ;
	char auxChar[120];
	float auxFloat;
	int auxInt;


		printf("\n1-Nombre\n2-Apellido\n3-Precio\n4-Codigo de vuelo\n5-Clase del pasajero\n6-Estado del vuelo\n0-Salir\n");
		opcion = EnterNumberInt("Ingrese que desea modificar: "	,"\nError, verifique que la opcion ingresada sea valida(6-0)\n",6, 0);

		switch(opcion)
		{
		case 1:
				EnterString("Ingrese el nombre: ", auxChar);
				Passenger_setNombre(pPassenger, auxChar);
				todoOk = 0;
			break;
		case 2:
				EnterString("Ingrese el apellido: ", auxChar);
				Passenger_setApellido(pPassenger, auxChar);
				todoOk = 0;
			break;
		case 3:
				auxFloat=	EnterNumberFloat("Ingrese el precio: ", "Error, ingrese un precio valido: ", 0);
				Passenger_setPrecio(pPassenger, auxFloat);
				todoOk = 0;
			break;
		case 4:
				EnterStringWithNumbers("Ingrese el codigo de vuelo: ", auxChar);
				NormalizeStringToUpper(auxChar);
				Passenger_setCodigoVuelo(pPassenger, auxChar);
				todoOk = 0;
			break;
		case 5:
				mostrarTipos(tipo, tamTipo);
				auxInt = EnterNumberInt("Ingrese tipo de pasajero: ", "Error ingrese un tipo de pasajero valido (1-3) ", 3, 1);
				Passenger_setTipoPasajero(pPassenger, auxInt);
				todoOk = 0;
			break;
		case 6:
				mostrarEstadoDeVuelo(estado, tamEstado);
				auxInt = EnterNumberInt("Ingrese estado del vuelo: ", "Error ingrese un estado de vuelo valido (1-4) ", 4, 1);
				Passenger_setEstado(pPassenger, auxInt);
				todoOk = 0;
			break;
		case 0:
			break;
		}

	return todoOk;
}

int removePassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado,Passenger* pPassenger, int index)
{
	int todoOk;
	int opcion;

	mostrarPasajeroIndex(pArrayListPassenger, tipo, tamTipo, estado, tamEstado, index);
	printf("Esta seguro que desea eliminar este pasajero?\n1-Si\n2-No\n\n");
	opcion = EnterNumberInt("Ingrese una opcion; ", "Ingrese una opcion valida (1-2): ", 2,1);
	switch(opcion)
	{
		case 1:
				ll_remove(pArrayListPassenger, index);
				Passenger_delete(pPassenger);
				todoOk = 0;
			break;
		case 2:
				todoOk = -1;
			break;
	}

	return todoOk;
}

int menuOrdenar(LinkedList* pArrayListPassenger)
{
	int todoOk = -1;;
	int option;

	printf("Ordenar lista por \n1-ID \n2-Nombre \n3-Apellido \n4-Precio \n0-Volver al menu principal");
	option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 4, 0);

	switch(option)
	{
		case 1:
				todoOk = ordenarIdMenu(pArrayListPassenger);
			break;

		case 2:
				todoOk =  ordenarNombreMenu(pArrayListPassenger);
			break;

		case 3:
				todoOk = ordenarApellidoMenu(pArrayListPassenger);
			break;

		case 4:
				todoOk = ordenarPrecioMenu(pArrayListPassenger);
			break;
		case 0:
				todoOk = -1;
	}

	return todoOk;
}

int ordenarNombre(void* elementoUno, void* elementoDos)
{
	char auxUno[50];
	char auxDos[50];
	int todoOk;

	Passenger_getNombre(elementoUno, auxUno);
	Passenger_getNombre(elementoDos, auxDos);
	todoOk = strcmp(auxUno,auxDos);

	return todoOk;
}
int ordenarApellido(void* elementoUno, void* elementoDos)
{
	char auxUno[50];
	char auxDos[50];
	int todoOk;

	Passenger_getApellido(elementoUno, auxUno);
	Passenger_getApellido(elementoDos, auxDos);
	todoOk = strcmp(auxUno,auxDos);

	return todoOk;
}

int ordenarId(void* elementoUno, void* elementoDos)
{
	int todoOk;
	int auxUno;
	int auxDos;

	Passenger_getId(elementoUno, &auxUno);
	Passenger_getId(elementoDos, &auxDos);

	if(auxUno > auxDos)
	{
		todoOk = 1;
	}
	else if(auxUno < auxDos)
	{
		todoOk = -1;
	}
	else
	{
		todoOk = 0;
	}

	return todoOk;
}
int ordenarPrecio(void* elementoUno, void* elementoDos)
{
	int todoOk;
	float auxUno;
	float auxDos;

	Passenger_getPrecio(elementoUno, &auxUno);
	Passenger_getPrecio(elementoDos, &auxDos);

	if(auxUno > auxDos)
	{
		todoOk = 1;
	}
	else if(auxUno < auxDos)
	{
		todoOk = -1;
	}
	else
	{
		todoOk = 0;
	}

	return todoOk;
}

int ordenarIdMenu(LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	int option;
	printf("\nOrdenar por ID \n1-Ascendentemente \n2-Descendentemente");

	option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

	switch (option)
	{
		case 1:
				printf("Esto puede demorar unos segundos...");
				todoOk = ll_sort(pArrayListPassenger, ordenarId, 1);
			break;

		case 2:
				printf("Esto puede demorar unos segundos...");
				todoOk = ll_sort(pArrayListPassenger, ordenarId, 0);
			break;

	}
	return todoOk;
}

int ordenarNombreMenu(LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	int option;

	printf("\nOrdenar por nombre\n1-Ascendentemente(A-Z)\n2-Descendentemente(Z-A)");

	option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

	switch (option)
	{
		case 1:
				printf("Esto puede demorar unos segundos...");
				todoOk = ll_sort(pArrayListPassenger, ordenarNombre, 1);
			break;

		case 2:
				printf("Esto puede demorar unos segundos...");
				todoOk = ll_sort(pArrayListPassenger, ordenarNombre, 0);
			break;

	}
	return todoOk;
}

int ordenarApellidoMenu(LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	int option;

	printf("\nOrdenar por apellido\n1-Ascendentemente(A-Z)\n2-Descendentemente(Z-A)");

	option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

	switch (option)
	{
		case 1:
				printf("Esto puede demorar unos segundos...");
				ll_sort(pArrayListPassenger, ordenarApellido, 1);
				todoOk = 0;
			break;

		case 2:
				printf("Esto puede demorar unos segundos...");
				ll_sort(pArrayListPassenger, ordenarApellido, 0);
				todoOk = 0;
			break;

	}
	return todoOk;
}


int ordenarPrecioMenu(LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	int option;

	printf("\nOrdenar por precio\n1-Ascendentemente\n2-Descendentemente");

	option=EnterNumberInt("\nSeleccione una opcion: ", "\nError, verifique que la opcion sea valida\n", 2, 1);

	switch (option)
	{
		case 1:
				printf("Esto puede demorar unos segundos...");
				todoOk = ll_sort(pArrayListPassenger, ordenarPrecio, 1);
			break;

		case 2:
				printf("Esto puede demorar unos segundos...");
				todoOk = ll_sort(pArrayListPassenger, ordenarPrecio, 0);
			break;

	}
	return todoOk;
}

int filtrarPorTipo (void* pasajero)
{

	int todoOk = 0;
	int idTipo;

	Passenger_getTipoPasajero(pasajero, &idTipo);

	if(pasajero != NULL && idTipo == 2)
	{
		todoOk = 1;
	}

	return todoOk;
}

int contarPrim(void* pPassenger)
{

	int todoOk = 0;
	int tipoPasajero;

	if(Passenger_getTipoPasajero(pPassenger,&tipoPasajero) == 0)
	{
		if(tipoPasajero == 1)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int contarExe(void* pPassenger)
{

	int todoOk = -0;
	int tipoPasajero;

	if(Passenger_getTipoPasajero(pPassenger,&tipoPasajero) == 0)
	{
		if(tipoPasajero == 2)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int contarEco(void* pPassenger)
{

	int todoOk = -1;
	int tipoPasajero;

	if(Passenger_getTipoPasajero(pPassenger,&tipoPasajero) == 0)
	{
		if(tipoPasajero == 3)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}
