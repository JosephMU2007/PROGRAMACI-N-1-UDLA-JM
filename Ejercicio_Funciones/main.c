#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][50]; 
    float precios[MAX_PRODUCTOS];    
    int cantidad = 0; 
    int opc = 0;

    do {
        opc = mostrarMenu();

        switch(opc) {
            case 1:
                cantidad = ingresarProducto(nombres, precios, cantidad);
                break;
            case 2:
                calcularTotal(precios, cantidad);
                break;
            case 3:
                mostrarExtremos(nombres, precios, cantidad);
                break;
            case 4:
                calcularPromedio(precios, cantidad);
                break;
            case 5:
                buscarProducto(nombres, precios, cantidad);
                break;
            case 6:
                printf("\nSaliendo del programa...\n");
                break;
            case -1: 
                printf("\nEntrada invalida. Por favor, ingrese un numero del 1 al 6.\n");
                break;
            default:
                if (opc != -1) {
                    printf("\nOpcion invalida. Intente de nuevo.\n");
                }
        }
    } while(opc != 6);

    return 0;
}
