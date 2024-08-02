/*
 * producto.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Mariano
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	int idProducto;
	char descripcion[51];
	int nacionalidad; // EEUU, CHINA, OTRO
	int tipo; // IPHONE, MAC, IPAD, ACCESORIOS
	float precio;
	int isEmpty; // Flag para saber si el producto está vacío o no
}sProducto;

sProducto PedirProducto(void);
int NuevoIdProducto(sProducto[], int);
sProducto NuevoProducto(int, char[], int, int, float);
sProducto HardcodearProducto(void);
int AgregarProducto(sProducto[], int, sProducto);
void EliminarProducto(sProducto[], int, int);
void ModificarProducto(sProducto[], int, sProducto);
int IgualdadProducto(sProducto[], int, int);

#endif /* PRODUCTO_H_ */
