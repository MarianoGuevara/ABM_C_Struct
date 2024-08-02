#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "producto.h"
#include "view.h"
#include "utilidades.h"
#include "productoControlador.h"

#define LEN 10

/*
typedef struct
{
	int idTipo;
	char descripcionTipo[51];
}stipoProducto;
*/

int main(void)
{
	setbuf(stdout, NULL);

	sProducto arrayProductos[LEN];
	for (int i=0; i<LEN; i++)
	{
		arrayProductos[i].isEmpty = 1; // true a mi centinela
	}

	sProducto p; // variables que voy a usar en la app
	int resultado;
	int id;

	int opcion;
	do
	{
		Menu();
		printf("Ingrese una opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion)
		{
			case 1:
				p = PedirProducto();
				resultado = AgregarProductoFinal(arrayProductos, LEN, p);

				if (resultado == 0) {printf("\nNo se pudo agregar el producto\n\n");}
				else {printf("\nProducto agregado exitosamente\n\n");}

				break;
			case 2:
				//p = PedirProducto();
				id = PedirEnteroRango(0,LEN,"Ingrese ID del producto a borrar: ");
				resultado = EliminarProductoFinal(arrayProductos, LEN, id);

				if (resultado == 0) {printf("\nNo se pudo eliminar el producto\n\n");}
				else {printf("\nProducto eliminado exitosamente\n\n");}
				break;
			case 3:
				id = PedirEnteroRango(0,LEN,"Ingrese ID del producto a Modificar: ");
				resultado = ModificarProductoFinal(arrayProductos, LEN, id);

				if (resultado == 0) {printf("\nNo se pudo modificar el producto\n\n");}
				else {printf("\nProducto modificado exitosamente\n\n");}
				break;
			case 4:
				MostrarArrayProd(arrayProductos, LEN); // ver si hago con columnas el view
				break;
			case 5:
				printf("Programa cerrado. Gracias por usarlo");
				break;
			default:
				printf("Opcion no valida en la interaccion con el menu");
				break;
		}
	} while (opcion != 5);


	return EXIT_SUCCESS;
}
