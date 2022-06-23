#include "validations.h"
#include <stdlib.h>
#include <stdio.h>


/// @brief Permite ingresar un numero entero con un maximo y un minimo validando que el dato ingresado sea correcto
///
/// @param message
/// @param errorMessage
/// @param max
/// @param min
/// @return
int EnterNumberInt (char message[], char errorMessage[],  int max, int min)
{
    char enteredNumber [51];
    int isNaN;
    int validatedNumber;

    do
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberInt(enteredNumber, min, max);

        while(isNaN ==-1)
        {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberInt(enteredNumber, min, max);
        }

        validatedNumber = atoi(enteredNumber);

    }while (validatedNumber < min || validatedNumber > max);

    return validatedNumber;
}

/// @brief Permite el ingreso de una cadena validando que el dato ingresado sea correcto
///
/// @param message
/// @param enteredString
void EnterString (char message[], char enteredString[])
{
    int isString;

    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", enteredString);

    isString = ValidateString (enteredString);
    while(isString == -1)
    {
    printf(" %s", message);
    fflush(stdin);
    scanf("%[^\n]", enteredString);
    isString = ValidateString (enteredString);

    }
    NormalizeString(enteredString);
}


void EnterStringWithNumbers(char message[], char enteredString[])
{
    int isString;

    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", enteredString);

    isString = ValidateStringWithNumbers(enteredString);
    while(isString == -1)
    {
    printf(" %s", message);
    fflush(stdin);
    scanf("%[^\n]", enteredString);
    isString = ValidateStringWithNumbers(enteredString);

    }
    NormalizeString(enteredString);
}
/// @brief Permite ingresar un numero flotante con un maximo y un minimo validando que el dato ingresado sea correcto
///
/// @param message
/// @param errormsg
/// @param min
/// @return
float EnterNumberFloat (char message[], char errormsg[], int min)
{
    char enteredNumber [51];
    int isNaN;
    float validatedNumber;

    do
    {

        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberFloat(enteredNumber, min);

        while(isNaN == -1)
        {
        printf("%s",errormsg);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberFloat(enteredNumber, min);
        }
        validatedNumber = atof(enteredNumber);

    }while (validatedNumber <= min);

    return validatedNumber;
}


/// @brief Valida que el numero que recibe por parametro sea numero
///
/// @param enteredNumber
/// @return
int ValidateNumberInt(char enteredNumber[], int min, int max)
{
    int validatedNumber = 0;
    int auxNumber;
    for(int i=0; i < strlen(enteredNumber); i++)
    {
    	auxNumber = atoi(enteredNumber);
        if ((isdigit(enteredNumber[i])==0) || auxNumber > max  || auxNumber < min )
        {
        validatedNumber = -1;
        break;
        }
    }
 return validatedNumber;
}

/// @brief Valida que la cadena que recibe por parametro sea correcta, y chequea que no se ingresen datos en blanco, o signos de puntuacion
///
/// @param enteredString
/// @return
int ValidateString(char enteredString[])
{
    int validatedString = 0;
    for(int i=0; i < strlen(enteredString); i++)
    {
         if (enteredString[0] == ' ')
        {
            validatedString = -1;
            printf("No se admiten espacio como nombres.");
            break;
        }
        else if (enteredString[i] == '-')
        {
       	validatedString = 0;
      	break;
        }
        else if (isalpha(enteredString[i])==0 && enteredString[i] != ' ' )
        {
        validatedString = -1;
        printf("No se admiten numeros/signos como nombres.");
        break;
        }
		else if (enteredString[i] == ' ' && enteredString[i+1] == ' ')
		{
			validatedString = -1;
			printf("No se admiten mas de dos espacios seguidos.");
			break;
		}

    }
    return validatedString;
}

/// @brief Valida que el dato que recibe por parametro sea un numero y tambien que no se ingresen mas de una coma
///
/// @param enteredNumber
/// @return
int ValidateNumberFloat(char enteredNumber[], int min)
{
    int validatedNumber;
    int flag=1;
    int auxNumber;

    for(int i = 0; i< strlen(enteredNumber); i++)
    {
    	auxNumber = atof(enteredNumber);

        if (flag && enteredNumber[i] == '.')
        {
                flag = 0;
        }else if(isdigit(enteredNumber[i])==0 || auxNumber <= min)
            {
                validatedNumber = -1;
                break;
            }

    }
    return validatedNumber;
}

/// @brief Permite que la cadena que recibe por parametro se normalize colocando la primer letra en mayuscula y las demas en minuscula
///
/// @param enteredString
void NormalizeString(char enteredString[])
{

    int flagNormalize = 1;
    for(int i=0;i<strlen(enteredString);i++)
    {
        if(enteredString[i]== ' ')
        {
        flagNormalize = 1;
        }

         else if (flagNormalize && enteredString[i]!= ' ')
        {
            enteredString[i] = toupper(enteredString[i]);
            flagNormalize = 0;

        }

        else
        {
        enteredString[i] = tolower(enteredString[i]);
        }

    }
}

void NormalizeStringToUpper(char enteredString[])
{
    for(int i=0;i<strlen(enteredString);i++)
    {

            enteredString[i] = toupper(enteredString[i]);
     }
}
int ValidateNumberIntWithoutRestriction(char enteredNumber[])
{
	int validatedNumber = 0;
	    for(int i=0; i < strlen(enteredNumber); i++)
	    {
	        if ((isdigit(enteredNumber[i])==0))
	        {
	        validatedNumber = -1;
	        break;
	        }
	    }
	 return validatedNumber;
}

int ValidateStringWithNumbers(char enteredString[])
{
	int validatedString = 0;
	    for(int i=0; i < strlen(enteredString); i++)
	    {
	         if (enteredString[0] == ' ')
	        {
	            validatedString = -1;
	            printf("No se admiten espacio como nombres.");
	            break;
	        }
	 		else if (enteredString[i] == ' ' && enteredString[i+1] == ' ')
	 		{
	 			validatedString = -1;
	 			printf("No se admiten mas de dos espacios seguidos.");
	 			break;
	 		}
	    }
	     return validatedString;
}
