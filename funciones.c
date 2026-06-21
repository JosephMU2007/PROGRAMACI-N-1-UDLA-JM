#include <stdio.h>
#include <string.h>
#include "Funciones.h"

int cargarInventario(struct Vehiculo arreglo[]) {
    FILE *fp = fopen("inventario.txt", "r");
    if (fp == NULL) return 0;
    
    int i = 0;
    while(fscanf(fp, "%d %s %[^\n] %[^\n] %s %f %s", 
                 &arreglo[i].id, arreglo[i].marca, arreglo[i].modelo, 
                 arreglo[i].tipo, arreglo[i].condicion, &arreglo[i].precio, arreglo[i].estado) == 7) {
        i++;
    }
    fclose(fp);
    return i;
}

void guardarInventario(struct Vehiculo arreglo[], int total) {
    FILE *fp = fopen("inventario.txt", "w");
    if (fp != NULL) {
        for (int i = 0; i < total; i++) {
            fprintf(fp, "%d %s %s %s %s %.2f %s\n", 
                    arreglo[i].id, arreglo[i].marca, arreglo[i].modelo, 
                    arreglo[i].tipo, arreglo[i].condicion, arreglo[i].precio, arreglo[i].estado);
        }
        fclose(fp);
    }
}

int agregarVehiculo(struct Vehiculo arreglo[], int total) {
    if (total >= 100) {
        printf("\nInventario lleno.\n");
        return total;
    }

    int tempID, idRepetido, validID = 0;
    printf("\n--- REGISTRO DE VEHICULO ---\n");
    
    // Validacion de ID y limpieza de letras
    do {
        idRepetido = 0;
        printf("ID unico (solo numeros): "); 
        if (scanf("%d", &tempID) != 1) {
            printf("Error: Debe ingresar un valor NUMERICO.\n");
            while(getchar() != '\n'); 
            continue;
        }
        for (int i = 0; i < total; i++) {
            if (arreglo[i].id == tempID) {
                printf("Error: Ese ID ya esta registrado.\n");
                idRepetido = 1;
                break;
            }
        }
        if (idRepetido == 0) validID = 1;
    } while (validID == 0);
    
    arreglo[total].id = tempID;

    // %[^\n] permite escribir con espacios
    printf("Marca: "); scanf(" %[^\n]", arreglo[total].marca);
    printf("Modelo: "); scanf(" %[^\n]", arreglo[total].modelo);
    printf("Tipo (Ej. Camioneta, Sedan): "); scanf(" %[^\n]", arreglo[total].tipo);

    // Validacion de Condicion
    int condicionValida = 0;
    do {
        printf("Condicion (Nuevo/Usado): "); 
        scanf(" %s", arreglo[total].condicion);
        if (strcmp(arreglo[total].condicion, "Nuevo") == 0 || strcmp(arreglo[total].condicion, "Usado") == 0) {
            condicionValida = 1;
        } else {
            printf("Error: Escriba exactamente 'Nuevo' o 'Usado'.\n");
        }
    } while (condicionValida == 0);

    // Validacion de Precio 
    int validPrecio = 0;
    do {
        printf("Precio: "); 
        if (scanf("%f", &arreglo[total].precio) != 1) {
            printf("Error: Debe ingresar un valor NUMERICO.\n");
            while(getchar() != '\n'); 
            continue;
        }
        if (arreglo[total].precio <= 0) {
            printf("Error: El precio no puede ser 0 o negativo.\n");
        } else {
            validPrecio = 1;
        }
    } while (validPrecio == 0);

    strcpy(arreglo[total].estado, "Disponible"); 
    total++;
    guardarInventario(arreglo, total); 
    printf("Vehiculo agregado y guardado con exito.\n");
    return total;
}

void mostrarDisponibles(struct Vehiculo arreglo[], int total) {
    if (total == 0) {
        printf("\nNo hay vehiculos en el sistema.\n");
        return;
    }
    printf("\n--- INVENTARIO DISPONIBLE ---\n");
    printf("ID\tMARCA\tMODELO\tTIPO\tCONDICION\tPRECIO\n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        if (strcmp(arreglo[i].estado, "Disponible") == 0) {
            printf("%d\t%s\t%s\t%s\t%s\t\t$%.2f\n", 
                   arreglo[i].id, arreglo[i].marca, arreglo[i].modelo, 
                   arreglo[i].tipo, arreglo[i].condicion, arreglo[i].precio);
        }
    }
}

void buscarParaCliente(struct Vehiculo arreglo[], int total) {
    char marcaBuscada[50], tipoBuscado[30];
    float presupuesto;
    int encontrados = 0;

    printf("\n--- BUSQUEDA PARA CLIENTE ---\n");
    printf("Marca preferida (Ej. Chevrolet): "); scanf(" %[^\n]", marcaBuscada);
    printf("Tipo de vehiculo (Ej. Camioneta): "); scanf(" %[^\n]", tipoBuscado);
    printf("Presupuesto maximo $: "); scanf("%f", &presupuesto);

    printf("\n--- RESULTADOS ACORDES AL CLIENTE ---\n");
    for (int i = 0; i < total; i++) {
        if (strcmp(arreglo[i].estado, "Disponible") == 0 &&
            strcmp(arreglo[i].marca, marcaBuscada) == 0 &&
            strcmp(arreglo[i].tipo, tipoBuscado) == 0 &&
            arreglo[i].precio <= presupuesto) {
            printf("ID: %d | %s %s (%s) | Precio: $%.2f\n", 
                   arreglo[i].id, arreglo[i].marca, arreglo[i].modelo, 
                   arreglo[i].condicion, arreglo[i].precio);
            encontrados++;
        }
    }
    if (encontrados == 0) printf("No hay vehiculos que cumplan esos requisitos.\n");
}

void registrarVenta(struct Vehiculo arreglo[], int total) {
    int idVenta;
    printf("\nIngrese el ID del vehiculo vendido: ");
    if (scanf("%d", &idVenta) != 1) {
        printf("Error de entrada.\n");
        while(getchar() != '\n');
        return;
    }

    for (int i = 0; i < total; i++) {
        if (arreglo[i].id == idVenta) {
            if (strcmp(arreglo[i].estado, "Vendido") == 0) {
                printf("Error: Este vehiculo ya fue vendido.\n");
                return;
            }
            strcpy(arreglo[i].estado, "Vendido");
            guardarInventario(arreglo, total); 
            printf("Venta registrada con exito!\n");
            return;
        }
    }
    printf("ID no encontrado.\n");
}