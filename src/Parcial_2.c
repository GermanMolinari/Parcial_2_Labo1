#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#define TAM_TIPO 3
#define TAM_ESTADO 4

int main()
{
	eTipoPass tipos [TAM_TIPO]= {{1,"FirstClass"},{2,"ExecutiveClass"},{3,"EconomyClass"}};
	eEstadoPass estados[TAM_ESTADO]= {{1,"Aterrizado"},{2,"En Horario"},{3,"En Vuelo"},{4,"Demorado"}};

	int option = 0;
	int flagSave = -1;
	int flagCarga = -1;

	setbuf(stdout,NULL);
	LinkedList* listaPasajeros = ll_newLinkedList();
	do{
		controller_Menu();
		option = EnterNumberInt("Ingrese una opcion: ", "Error, Ingrese una opcion valida: ", 10, 1);

		switch(option)
		{
			case 1:
				if(flagCarga == -1 && controller_loadFromText("data.csv",listaPasajeros) == 0)
				{
					printf("Se realizo con exito \n");
					flagCarga = 0;
				}
				else
				{	if(flagCarga == 0)
					{
						printf("La lista ya fue cargada previamente \n");
					}
					else
					{
						printf("Fallo la carga desde el .csv \n");
					}
				}
				break;

			case 2 :
				if(flagCarga == -1 && controller_loadFromBinary("data.bin" , listaPasajeros) == 0)
				 {
					printf("Se realizo con exito \n");
					flagCarga =0;
				 }
					else
					{	if(flagCarga == 0)
						{
							printf("La lista ya fue cargada previamente \n");
						}
						else
						{
							printf("Fallo la carga desde el .bin \n");
						}
					}
				break;

			case 3:
				if(controller_addPassenger(listaPasajeros, tipos, TAM_TIPO, estados, TAM_ESTADO) == 0)
				{
					printf("Se realizo con exito \n");
				}
				else
				{
					printf("No se pudo dar de alta \n");
				}
				break;

			case 4:
				if(controller_editPassenger (listaPasajeros, tipos, TAM_TIPO, estados, TAM_ESTADO) == 0)
				{
					printf("Se realizo con exito \n");
				}
				else
				{
					printf("No se pudo modificar \n");
				}
				break;

			case 5:
				if(controller_removePassenger(listaPasajeros, tipos, TAM_TIPO, estados, TAM_ESTADO) == 0)
				{
					printf("Se realizo con exito \n");
				}
				else
				{
					printf("No se pudo dar la baja \n");
				}
				break;

			case 6:
				if(controller_ListPassenger(listaPasajeros,tipos,TAM_TIPO,estados,TAM_ESTADO) == 0)
				{
					printf("Se realizo con exito \n");
				}
				else
				{
					printf("No se pudo mostrar\n");
				}
				break;

			case 7:
				if(controller_sortPassenger(listaPasajeros) == 0)
				{
					printf("Se ordeno con exito\n");
				}
				else
				{
					printf("No se pudo ordenar\n");
				}
				break;

			case 8:
				if(controller_saveAsText("data.csv", listaPasajeros) == 0 && flagCarga == 0)
				{
					printf("Se guardo con exito! \n");
					flagSave = 0;
				}
				else
				{
					printf("No se pudo guardar\n");
				}
				break;

			case 9:
				if(controller_saveAsBinary("data.bin", listaPasajeros) == 0 && flagCarga == 0)
				{
					printf("Se guardo con exito! \n");
					flagSave = 0;
				}
				else
				{
					printf("No se pudo guardar\n");
				}
				break;

			case 10:
				if(flagSave == 0 && ll_isEmpty(listaPasajeros) != 1)
				{
					option = 11;
				}
				else
				{
					printf("Primero debe guardar\n");
				}
				break;
		}
	}while(option != 11);
	return 0;
}
