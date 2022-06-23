#ifndef CONTROLLER_H_
#define  CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"

/// @brief Devuelve un 0 en caso que la lista este vacia o 1 en caso que haya al menos un pasajero cargado en la lista
///
/// @param pArrayListPassenger
/// @return
int controller_CheckListStatus(LinkedList* pArrayListPassenger);

/// @brief Imprime el menu de opciones
///
void controller_Menu();

/// @brief Controlador que llama a las funciones que cargan la lista desde un archivo de texto
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/// @brief Controlador que llama a las funciones que cargan la lista desde un archivo de binario
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief Controllador que llama a las funcion que da el alta a un pasajero
///
/// @param pArrayListPassenger
/// @param
/// @param
/// @param
/// @param
/// @return
int controller_addPassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado);

/// @brief Controllador que llama a las funciones que permiten modificar un empleado
///
/// @param pArrayListPassenger
/// @param
/// @param
/// @param
/// @param
/// @return
int controller_editPassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado);

/// @brief Controllador que llama a las funciones que permiten la baja de un empleado
///
/// @param pArrayListPassenger
/// @param passengerType
/// @param typeLen
/// @param flightStatus
/// @param flightLen
/// @return
int controller_removePassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado);

/// @brief Controllador que llama a la funcion que imprime la lista
///
/// @param pArrayListPassenger
/// @param type
/// @param typeLen
/// @param flightStatus
/// @param flightLen
/// @return
int controller_ListPassenger(LinkedList* pArrayListPassenger, eTipoPass* tipo, int tamTipo, eEstadoPass* estado, int tamEstado);

/// @brief Controllador que llama a las funciones que hace un ordenamiento
///
/// @param pArrayListPassenger
/// @return
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// @brief Controllador que llama a la funcion que guarda el archivo en modo texto
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/// @brief  Controllador que llama a la funcion que guarda el archivo en modo binario
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief Controllador que chequea que se haya guardado previamente le archivo
///
/// @param pArrayListPassenger
/// @param flagSave
/// @return
int controller_exit(LinkedList* pArrayListPassenger, int flagSave);

/// @brief Controllador que informa al usuario que no se ha cargado la lista antes de dar un alta
///
/// @param pArrayListPassenger
/// @return
int controller_overWriteData(LinkedList* pArrayListPassenger);

/// @brief Controllador que le informa al usuario que esta a punto de sobreescribir datos en modo texto
///
/// @param pArrayListPassenger
/// @return
int controller_overWriteText(LinkedList* pArrayListPassenger);

/// @brief Controllador que le informa al usuario que esta a punto de sobreescribir datos en modo binario
///
/// @param pArrayListPassenger
/// @return
int controller_overWriteBin(LinkedList* pArrayListPassenger);
#endif  /* CONTROLLER_H_ */
