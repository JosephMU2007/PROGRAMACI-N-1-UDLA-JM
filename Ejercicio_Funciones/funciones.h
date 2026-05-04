#ifndef FUNCIONES_H
#define FUNCIONES_H


#define MAX_PRODUCTOS 10

int mostrarMenu();
int ingresarProducto(char nombres[][50], float precios[], int cantidadActual);
void calcularTotal(float precios[], int cantidad);
void mostrarExtremos(char nombres[][50], float precios[], int cantidad);
void calcularPromedio(float precios[], int cantidad);
void buscarProducto(char nombres[][50], float precios[], int cantidad);

#endif