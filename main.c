#include <stdio.h>
#include "Funciones.h"

int main() {
    
    struct Libro biblioteca[10]; 
    int totalLibros = 0; 
    int opc, idTemp;

    do {
        printf("\n=== GESTION DE BIBLIOTECA ===\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar lista completa\n");
        printf("3. Buscar libro (por Titulo o ID)\n");
        printf("4. Actualizar estado del libro\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                
                totalLibros = ingresarLibro(biblioteca, totalLibros);
                break;
            case 2:
                mostrarTabla(biblioteca, totalLibros);
                break;
            case 3:
                buscarLibro(biblioteca, totalLibros);
                break;
            case 4:
                actualizarEstado(biblioteca, totalLibros);
                break;
            case 5:
                printf("\nIngrese el ID del libro a eliminar: ");
                scanf("%d", &idTemp);
                totalLibros = eliminarLibro(biblioteca, totalLibros, idTemp);
                break;
            case 6:
                printf("\nCerrando el sistema. Buen trabajo!\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while (opc != 6);

    return 0;
}