#include <stdio.h>
#include <string.h>
#include "funciones.h"

int mostrarMenu() {
    int opc = 0;
    int leidos;
    
    printf("\n--- GESTION DE INVENTARIO ---\n");
    printf("1. Ingresar producto\n");
    printf("2. Calcular precio total\n");
    printf("3. Mostrar producto mas caro y mas barato\n");
    printf("4. Calcular precio promedio\n");
    printf("5. Buscar producto\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    
    
    leidos = scanf("%d", &opc);
    while(getchar() != '\n'); 
    
    
    if (leidos != 1) {
        return -1; 
    }
    
    return opc;
}

int ingresarProducto(char nombres[][50], float precios[], int cantidadActual) {
    if (cantidadActual >= MAX_PRODUCTOS) {
        printf("\nError: El inventario esta lleno (Maximo 10 productos).\n");
        return cantidadActual;
    }

    printf("\nIngrese el nombre del producto (sin espacios): ");
    scanf("%49s", nombres[cantidadActual]);
    while(getchar() != '\n'); 

    int inputCorrecto = 0;
    
    do {
        printf("Ingrese el precio del producto: ");
        int leidos = scanf("%f", &precios[cantidadActual]);
        
        if (leidos == 1) {
            
            if (precios[cantidadActual] > 0) {
                inputCorrecto = 1; 
            } else {
                printf(">> Error: El precio debe ser mayor a 0.\n");
            }
        } else {
            
            printf(">> Error: Ingrese un valor numerico valido (ej. 10.50).\n");
        }
        
        while(getchar() != '\n'); 
        
    } while(!inputCorrecto);

    printf("Producto '%s' agregado con exito.\n", nombres[cantidadActual]);
    
    return cantidadActual + 1; 
}

void calcularTotal(float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("\nEl inventario esta vacio.\n");
        return;
    }
    
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    printf("\nEl precio total de los %d productos en inventario es: $%.2f\n", cantidad, total);
}

void mostrarExtremos(char nombres[][50], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("\nEl inventario esta vacio.\n");
        return;
    }

    int indiceCaro = 0;
    int indiceBarato = 0;

    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indiceCaro]) {
            indiceCaro = i;
        }
        if (precios[i] < precios[indiceBarato]) {
            indiceBarato = i;
        }
    }

    printf("\nProducto mas caro: %s ($%.2f)\n", nombres[indiceCaro], precios[indiceCaro]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[indiceBarato], precios[indiceBarato]);
}

void calcularPromedio(float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("\nEl inventario esta vacio.\n");
        return;
    }
    
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    
    float promedio = total / cantidad;
    printf("\nEl precio promedio de los productos es: $%.2f\n", promedio);
}

void buscarProducto(char nombres[][50], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("\nEl inventario esta vacio.\n");
        return;
    }

    char nombreBuscado[50];
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf("%49s", nombreBuscado);
    while(getchar() != '\n');

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf(">> Producto encontrado: %s - Precio: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado) {
        printf(">> El producto '%s' no se encontro en el inventario.\n", nombreBuscado);
    }
}