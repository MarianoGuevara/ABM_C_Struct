#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para funciones de string

float ValidarFloatRango(float num, float min, float max)
{
	int retorno = 1;
	if (num < min || num > max){retorno = 0;}
	return retorno;
}

int ValidarIntRango(int num, int min, int max)
{
	int retorno = 1;
	if (num < min || num > max){retorno = 0;}
	return retorno;
}

int ValidarString(char str[], int min, int max)
{
	int retorno = 1;
	int len = strlen(str);
	if (len < min || len > max){retorno = 0;}
	return retorno;
}

int PedirEnteroRango(int min, int max, char msj[])
{
	int num;
	int result;
	do
	{
		printf(msj);
		fflush(stdin);
		result = scanf("%d", &num);
		//printf("%d",result);
	} while (result == 0 || (ValidarIntRango(num, min,max) == 0));
	return num;
}

int PedirFlotanteRango(float min, float max, char msj[])
{
	float num;
	int result;
	do
	{
		printf(msj);
		fflush(stdin);
		result = scanf("%f", &num);
		//printf("%d",result);
	} while (result == 0 || (ValidarFloatRango(num, min,max) == 0));
	return num;
}
