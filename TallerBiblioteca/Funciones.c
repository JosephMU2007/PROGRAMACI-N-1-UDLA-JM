#include <stdio.h>
#include <string.h>
#include "Funciones.h"

int ingresarLibro(struct Libro arreglo[], int total) {
    if (total >= 10) {
        printf("\nError: La biblioteca ha alcanzado el limite maximo de 10 libros.\n");
        return total;
    }

    int tempID;
    printf("\nIngrese el ID del libro (numero unico): ");
    scanf("%d", &tempID);


    for (int i = 0; i < total; i++) {
        if (arreglo[i].id == tempID) {
            printf("Error: El ID %d ya existe. Intente con otro.\n", tempID);
            return total; 
        }
    }
    arreglo[total].id = tempID; 

    
    printf("Ingrese el Titulo: ");
    while ((getchar()) != '\n'); 
    fgets(arreglo[total].titulo, 100, stdin);
    arreglo[total].titulo[strcspn(arreglo[total].titulo, "\n")] = 0;

    printf("Ingrese el Autor: ");
    fgets(arreglo[total].autor, 50, stdin);
    arreglo[total].autor[strcspn(arreglo[total].autor, "\n")] = 0;

    printf("Ingrese el Anio de publicacion: ");
    scanf("%d", &arreglo[total].anio);

   
    int estadoValido = 0;
    do {
        printf("Ingrese el Estado (Disponible / Prestado): ");
        scanf("%s", arreglo[total].estado); 
        
        if (strcmp(arreglo[total].estado, "Disponible") == 0 || strcmp(arreglo[total].estado, "Prestado") == 0) {
            estadoValido = 1;
        } else {
            printf("Error: Escriba exactamente 'Disponible' o 'Prestado'.\n");
        }
    } while (estadoValido == 0);

    printf("\nLibro registrado con exito!\n");
    total++; 
    return total; 
}

void mostrarTabla(struct Libro arreglo[], int total) {
    if (total == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }

    printf("\nID\tTITULO\t\t\tAUTOR\t\tANIO\tESTADO\n");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t%s\n", 
               arreglo[i].id, 
               arreglo[i].titulo, 
               arreglo[i].autor, 
               arreglo[i].anio, 
               arreglo[i].estado);
    }
}


void buscarLibro(struct Libro arreglo[], int total) {
    if (total == 0) {
        printf("\nNo hay libros para buscar.\n");
        return;
    }

    int opcionBusqueda;
    int encontrado = 0;

    printf("\nComo desea buscar?\n1. Por ID\n2. Por Titulo\nOpcion: ");
    scanf("%d", &opcionBusqueda);

    if (opcionBusqueda == 1) {
        int idBuscado;
        printf("Ingrese el ID: ");
        scanf("%d", &idBuscado);
        
        for (int i = 0; i < total; i++) {
            if (arreglo[i].id == idBuscado) {
                printf("\n--- Libro Encontrado ---\n");
                printf("Titulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n", 
                       arreglo[i].titulo, arreglo[i].autor, arreglo[i].anio, arreglo[i].estado);
                encontrado = 1;
                break;
            }
        }
    } else if (opcionBusqueda == 2) {
        char tituloBuscado[100];
        printf("Ingrese el Titulo exacto: ");
        while ((getchar()) != '\n'); 
        fgets(tituloBuscado, 100, stdin);
        tituloBuscado[strcspn(tituloBuscado, "\n")] = 0;

        for (int i = 0; i < total; i++) {
            if (strcmp(arreglo[i].titulo, tituloBuscado) == 0) {
                printf("\n--- Libro Encontrado ---\n");
                printf("ID: %d\nAutor: %s\nAnio: %d\nEstado: %s\n", 
                       arreglo[i].id, arreglo[i].autor, arreglo[i].anio, arreglo[i].estado);
                encontrado = 1;
                break;
            }
        }
    }

    if (encontrado == 0) {
        printf("\nLibro no encontrado en el sistema.\n");
    }
}


void actualizarEstado(struct Libro arreglo[], int total) {
    int idBuscado;
    printf("\nIngrese el ID del libro a actualizar: ");
    scanf("%d", &idBuscado);

    for (int i = 0; i < total; i++) {
        if (arreglo[i].id == idBuscado) {
            printf("Estado actual: %s\n", arreglo[i].estado);
            
            
            if (strcmp(arreglo[i].estado, "Disponible") == 0) {
                strcpy(arreglo[i].estado, "Prestado");
            } else {
                strcpy(arreglo[i].estado, "Disponible");
            }
            
            printf("Nuevo estado: %s\n", arreglo[i].estado);
            return;
        }
    }
    printf("\nError: ID no encontrado.\n");
}


int eliminarLibro(struct Libro arreglo[], int total, int idBorrar) {
    int posicion = -1;

    for (int i = 0; i < total; i++) {
        if (arreglo[i].id == idBorrar) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        printf("\nError: ID no encontrado. No se borro nada.\n");
        return total;
    }

    
    for (int j = posicion; j < total - 1; j++) {
        arreglo[j] = arreglo[j + 1];
    }

    total--; 
    printf("\nLibro eliminado exitosamente.\n");
    return total; 
}
