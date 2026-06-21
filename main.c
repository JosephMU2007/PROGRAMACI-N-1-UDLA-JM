#include <stdio.h>
#include "Funciones.h"

int main() {
    struct Vehiculo concesionaria[100];
    int totalAutos = 0;
    int opcion;

    totalAutos = cargarInventario(concesionaria);
    printf("Sistema iniciado. Vehiculos en base de datos: %d\n", totalAutos);

    do {
        printf("\n=== RUEDAS DE ORO - SGIC ===\n");
        printf("1. Ingresar nuevo vehiculo\n");
        printf("2. Mostrar vehiculos disponibles\n");
        printf("3. Busqueda avanzada para cliente\n");
        printf("4. Registrar Venta\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                totalAutos = agregarVehiculo(concesionaria, totalAutos);
                break;
            case 2:
                mostrarDisponibles(concesionaria, totalAutos);
                break;
            case 3:
                buscarParaCliente(concesionaria, totalAutos);
                break;
            case 4:
                registrarVenta(concesionaria, totalAutos);
                break;
            case 5:
                printf("\nGuardando datos finales y cerrando sistema...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}