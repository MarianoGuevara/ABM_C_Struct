#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "producto.h"
#include "utilidades.h"
#include "view.h"

#define NACIONALIDADES 3
#define TIPO 4

sProducto PedirProducto(void)
{
	char descripcion[51];
	int nacionalidad;
	int tipo;
	float precio;
	char nacionalidades[NACIONALIDADES][25] = {"EEUU", "CHINA", "OTRO"};
	char tipos[TIPO][25] = {"IPHONE", "MAC", "IPAD", "ACCESORIOS"};

	do
	{
		printf("Ingrese descripcion: ");
		fflush(stdin);
		scanf("%[^\n]",descripcion);

	} while (ValidarString(descripcion, 1,51)==0);

	MostrarArrayChar(nacionalidades, (sizeof(nacionalidades)/sizeof(nacionalidades[0])));
	nacionalidad = PedirEnteroRango(1,3, "Ingrese Nacionalidad: ");

	MostrarArrayChar(tipos, (sizeof(tipos)/sizeof(tipos[0])));
	tipo = PedirEnteroRango(1,4, "Ingrese Tipo: ");

	precio = PedirFlotanteRango(1.0,100000.0, "Ingrese precio: ");

	return NuevoProducto(0, descripcion, nacionalidad, tipo, precio);
}

int NuevoIdProducto(sProducto array[], int lenArray)
{
	int id = 1;
	for (int i=lenArray-1; i>=0; i--)
	{
		//printf("%d \n", array[i].isEmpty);
		if (array[i].isEmpty == 0)
		{
			//printf("ENTROOO \n");
			id = array[i].idProducto + 1;
			break;
		}
	}
	//printf("%d \n", id);
	return id;
}

sProducto NuevoProducto(int id, char descripcion[], int nacionalidad, int tipo, float precio)
{
	sProducto producto;

	producto.isEmpty = 0;
	producto.idProducto = id;
	strcpy(producto.descripcion, descripcion);
	producto.nacionalidad = nacionalidad;
	producto.tipo = tipo;
	producto.precio= precio;

	return producto;
}

sProducto HardcodearProducto(void)
{
	sProducto producto = {-1, "x", 1, 1, 10000.5, 0};
	return producto;
}

// pasar array de param es pasar puntero al 1er elemento; cambia el original; se pasa por referencia
// mientras resto de variables por valor
int AgregarProducto(sProducto array[], int lenArray, sProducto producto)
{
	int retorno = 0; // false

	for (int i=0; i<lenArray; i++)
	{
		if (array[i].isEmpty == 1 && array[i].idProducto != -1) // los -1 son los hardcodeados
		{
			array[i].isEmpty = 0; // false
			array[i] = producto;
			retorno = 1;
			break;
		}
	}
	return retorno;
}
// lastima que sin punteros no puedo devolver un array de chars en una funcion. Haría un "toString"

void EliminarProducto(sProducto array[], int lenArray, int indice)
{
    for (int i=indice; i < lenArray - 1; i++) // len-1 asi llega a 1 menos del ultimo pq al ultimo le asignaria len+1 si no
    {
        array[i] = array[i + 1]; // Me corre DESDE el indice que quiero borrar hasta el final todos 1 a la izquierda
    }
    array[lenArray - 1].isEmpty = 1; // -> EL ULT ELEMENTO DEL ARRAY QUEDARÁ CON MISMO CONTENIDO DEL ANTEULTIMO.
    								 // -> Simulo un borrado poniendolo empty al menos
}

void ModificarProducto(sProducto array[], int indice, sProducto p)
{
	array[indice] = p;
}

int IgualdadProducto(sProducto array[], int lenArray, int id)
{
	int retorno = -1;
	for (int i=0; i < lenArray - 1; i++)
	{
		if (array[i].idProducto == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}
