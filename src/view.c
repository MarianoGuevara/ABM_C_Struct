#include <stdio.h>
#include <stdlib.h>

#include "producto.h"

void Menu(void)
{
	printf("1- Alta producto\n");
	printf("2- Baja producto\n");
	printf("3- Modificacion producto\n");
	printf("4- Listar productos\n");
	printf("5- SALIR\n");
}

void MostrarProducto(sProducto producto) // esto me gustaria mandarlo al producto.c pero como no puedo devolver array
										 // de char lo meto aca de una
{
	printf("%d || %s || %d || %f || %d || %d",  producto.idProducto,
												producto.descripcion,
												producto.nacionalidad,
												producto.precio,
												producto.tipo,
												producto.isEmpty);
}

void MostrarArrayProd(sProducto array[], int lenArray)
{
	printf("\n--------------------------------------------\n");
	for (int i=0; i<lenArray; i++)
	{
		if (array[i].isEmpty == 0){MostrarProducto(array[i]);}
		else {printf("VACIO");}
		printf("\n");
	}
	printf("--------------------------------------------\n\n");
}

void MostrarArrayChar(char array[][25], int lenArray)
{
	for (int i=0; i<lenArray; i++)
	{
		if (i != lenArray-1) {printf("%d -> %s || ", i+1,array[i]);}
		else {printf("%d -> %s", i+1,array[i]);}
	}
	printf("\n");
}
