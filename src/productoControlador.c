#include <stdio.h>
#include <stdlib.h>

#include "producto.h"
#include "utilidades.h"


int AgregarProductoFinal(sProducto array[], int lenArray, sProducto producto)
{
	int retorno = 0;
	int id = NuevoIdProducto(array, lenArray);
	producto.idProducto = id;
	retorno = AgregarProducto(array,lenArray,producto);
	return retorno;
}

int EliminarProductoFinal(sProducto array[], int lenArray, int id)
{
	int retorno = 0;
	int indice = IgualdadProducto(array,lenArray,id);
	if (indice!=-1 && array[indice].isEmpty == 0)
	{
		EliminarProducto(array,lenArray,indice);
		retorno = 1;
	}
	return retorno;
}

int ModificarProductoFinal(sProducto array[], int lenArray, int id)
{
	int retorno = 0;

	int indice = IgualdadProducto(array,lenArray,id);
	if (indice!=-1 && array[indice].isEmpty == 0)
	{
		sProducto p = PedirProducto();
		p.idProducto = id;
		ModificarProducto(array,indice,p);
		retorno = 1;
	}
	return retorno;
}
