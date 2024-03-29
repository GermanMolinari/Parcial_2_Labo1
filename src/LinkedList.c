#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int tamLinkedList = -1;

    if(this != NULL)
    {
    	tamLinkedList = this->size;
    }

    return tamLinkedList;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{	Node* pNode = NULL;

	if(this != NULL  && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;

		for(int i = 0; i<nodeIndex; i++)
		{
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int todoOk = -1;
    Node* pNodoAnterior = NULL;
    Node* pNuevoNodo = NULL;

	if(this != NULL  && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		pNuevoNodo = (Node*) malloc(sizeof(Node));

		if(pNuevoNodo != NULL)
		{
			if(nodeIndex == 0)
			{
				pNuevoNodo->pNextNode = this->pFirstNode;
				//  (BASURA)		=		  NULL
				this->pFirstNode = pNuevoNodo;
				//  (NULL)	    =  Direccion de memoria del primer nodo que estamos agregando

			}
			else
			{
				pNodoAnterior = getNode(this, nodeIndex - 1);
				if(pNodoAnterior != NULL)
				{
					pNuevoNodo->pNextNode = pNodoAnterior->pNextNode;
					pNodoAnterior->pNextNode = pNuevoNodo;
				}
			}
			pNuevoNodo->pElement = pElement;
			this->size++;
			todoOk = 0;
		}
	}
    return todoOk;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this) , pElement);

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodo = getNode(this, index);
    	if(pNodo != NULL)
    	{
			returnAux = pNodo->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
		pNodo = getNode(this, index);

		if(pNodo != NULL)
		{
			pNodo->pElement = pElement;
			returnAux = 0;
		}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int todoOk = -1;
	Node* pNodoAnterior = NULL;
	Node* pNodo = NULL;

	if(this != NULL  && index >= 0 && index < ll_len(this))
	{
			pNodo = getNode(this, index);
			if(index == 0)
			{
				this->pFirstNode = pNodo->pNextNode;
			}
			else
			{
				pNodoAnterior = getNode(this, index - 1 );

				if(pNodoAnterior != NULL)
				{
					pNodoAnterior->pNextNode = pNodo->pNextNode;
				}
			}
			this->size--;
			free(pNodo);
			todoOk = 0;

	}
	    return todoOk;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int tam;

    tam = ll_len(this);

    if(this != NULL && tam > 0)
    {
    	for(int i = 0; i < tam; i++)
    	{
    		ll_remove(this, i);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int todoOk = -1;

    if(this != NULL && ll_clear(this) == 0)
    {
    	free(this);
    	todoOk = 0;
    }
    return todoOk;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int todoOk = -1;
    int tam;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	for(int i = 0; i < tam; i++)
    	{
    		if(ll_get(this, i) == pElement)
    		{
    			todoOk = i;
    			break;
    		}
    	}
    }

    return todoOk;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int todoOk = -1;

    if(this != NULL)
    {
    	todoOk = 0;

    	if(ll_len(this) == 0)
    	{
    		todoOk = 1;
    	}
    }
    return todoOk;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int todoOk = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	todoOk = addNode(this, index, pElement);
    }
    return todoOk;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAuxPunteroElemento = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
		returnAuxPunteroElemento = ll_get(this, index);
		ll_remove(this, index);
    }
    return returnAuxPunteroElemento;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int todoOk = -1;

    if(this != NULL)
    {
    	todoOk = 0;
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		todoOk=1;
    	}
    }
    return todoOk;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int todoOk = -1;
    int tam;
    void* pElement = NULL;

    if (this != NULL && this2 != NULL)
    {

    	tam = ll_len(this2);

    	todoOk = 1;

    	for (int i = 0; i < tam; i++)
    	{
    		pElement = ll_get(this2, i);

    		if (ll_contains(this, pElement) == 0)
    		{
    			todoOk = 0;
    			break;
    		}
    	}
    }

    return todoOk;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList = NULL;
    void* pElement = NULL;

    if(this != NULL && from >= 0 && from < ll_len(this) && to <= ll_len(this))
    {
    	subList = ll_newLinkedList();
    	if(subList != NULL)
    	{
    		for(int i = from; i < to; i++)
    		{
    			pElement = ll_get(this, i);
				ll_add(subList, pElement);
    		}
    	}
    }
    return subList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneList = NULL;

    if(this != NULL)
    {
    	cloneList = ll_subList(this, 0, ll_len(this));
    }
    return cloneList;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{

	int returnAux =-1;
	int estaOrdenado;
	int len;
	void* auxElement = NULL;
	void* auxElement2 = NULL;
	//ordena elementos

	//funcion parametros- retorna <0 mayor a cero si el primero es mayor, 0 si son iguales
	//y >0 menor a cero si el segundo es mayor
	if (this != NULL && (order == 0 || order == 1) && pFunc != NULL)
	{
		len = ll_len(this);
		do {
			estaOrdenado = 1;
			len --;

			for (int i = 0; i < len; i++)
			{
				auxElement = ll_get (this, i);//obtengo una dir de memoria
				auxElement2 = ll_get (this, i+1);//obtengo otra dir de memoria

				if ((order == 1 && pFunc(auxElement, auxElement2) > 0) || (order == 0 && pFunc(auxElement, auxElement2) < 0))
				{
					ll_set(this, i, auxElement2);//le pasa el elemento que quiero que ponga en una posicion determinada
					ll_set(this, i+1, auxElement);
					estaOrdenado = 0;
				}
			}
		} while (estaOrdenado == 0);

		returnAux = 0;
	}

	return returnAux;
}

//La funci�n �ll_count� recibir� una lista y una funci�n �fn�. Se deber� iterar todos los elementos
//de la lista y pas�rselos a la funcion �fn�. La funci�n �fn� devolver� la cantidad que debe
//contarse. La funci�n �ll_count� almacenar� un acumulador al cual sumar� el valor de retorno
//de �fn� en cada iteraci�n. Al finalizar las iteraciones, la funci�n �ll_count� devolver� el valor
//acumulado.


int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int todoOk = 0;
	int tam;
	void* pElemento = NULL;

	tam=ll_len(this);

	if(this!=NULL)
	{
		for(int i = 0; i< tam; i++)
		{
			pElemento = ll_get(this, i);

			if(fn(pElemento) == 1)
			{
				todoOk++;
			}
		}
	}
	return todoOk;
}

//Prototipo de la funci�n: LinkedList* ll_filter(LinkedList* this, void (*fn)(void* element))
//La funci�n �ll_filter� recibir� una lista y una funci�n �fn�. Se deber� iterar todos los elementos
//de la lista y pas�rselos a la funci�n �fn�. La funci�n �fn� analizar� el elemento recibido e
//informar� si cumple o no con el criterio establecido. Al finalizar la iteraci�n, la nueva lista
//estar� conformada s�lo por los elementos que corresponden.


LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{

	LinkedList* nuevaLista = NULL;
	int tam;
	void* pElement = NULL;
	tam = ll_len(this);
	nuevaLista =  ll_newLinkedList();

	if(nuevaLista != NULL)
	{
		for(int i = 0; i<tam; i++)
		{
			pElement = ll_get(this, i);

			if(fn(pElement) == 1)
			{
				ll_add(nuevaLista, pElement);
			}
		}
	}
	return nuevaLista;
}

//Prototipo de la funci�n: LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
//La funci�n �ll_map� recibir� una lista y una funci�n �fn�. Se deber� iterar todos los elementos
//de la lista y pas�rselos a la funci�n �fn�. La funci�n �fn� podr� realizar un c�lculo con el
//elemento recibido y modificar alguno de sus campos si es necesario. Al finalizar la iteraci�n,
//los elementos de la lista quedar�n modificados.


LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
	LinkedList* ListaConDescuento = NULL;
	int tam;
	void* pElemento = NULL;
	tam = ll_len(this);

	ListaConDescuento = ll_newLinkedList();

	if(ListaConDescuento != NULL && this != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			pElemento = ll_get(this, i);

			if(pElemento != NULL )
			{
				fn(pElemento);
				ll_add(ListaConDescuento, pElemento);
			}
		}
	}
	return ListaConDescuento;
}
