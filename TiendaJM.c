#include <stdio.h>
#include <string.h>

int main() {
    char ID[15] = "Pendiente";
    char nombre[30] = "Sin nombre";
    int stock = 0;
    float precio_unitario = 0.0;
    float ganancias_totales = 0.0;

    int opcion = 0;
    int cantidad_operacion = 0;
    float porcentaje_descuento = 0.0;
    int check_scan;

    do {
        printf("\n\tSISTEMA DE GESTION DE PRODUCTO");
        printf("\n\t1.Registrar producto");
        printf("\n\t2.Vender unidades");
        printf("\n\t3.Reabastecer stock");
        printf("\n\t4.Consultar informacion");
        printf("\n\t5.Ver ganancias totales");
        printf("\n\t6.Salir");
        printf("\n\tSeleccione una opcion: ");

        check_scan = scanf("%d", &opcion);
        while (getchar() != '\n');
        if (check_scan != 1) {
            printf("\n\t[!] Error: Ingrese un numero valido.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                printf("\n--- Registro de Datos ---");
                printf("\nIngrese ID del producto: ");
                scanf("%s", ID);
                while (getchar() != '\n');

                printf("Ingrese nombre del producto: ");
                fgets(nombre, 30, stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; 

                printf("Ingrese cantidad inicial en stock: ");
                scanf("%d", &stock);
                printf("Ingrese precio por unidad: ");
                scanf("%f", &precio_unitario);
                printf("\n[OK] Producto registrado correctamente.\n");
                break;

            case 2: 
                if (stock <= 0) {
                    printf("\n[!] No hay stock disponible para realizar ventas.\n");
                } else {
                    printf("\n--- Proceso de Venta ---");
                    printf("\nStock actual: %d unidades", stock);
                    printf("\nCantidad a vender: ");
                    scanf("%d", &cantidad_operacion);

                    if (cantidad_operacion > stock) {
                        printf("\n[!] Error: No se puede vender mas de lo que hay en stock.\n");
                    } else if (cantidad_operacion <= 0) {
                        printf("\n[!] Error: Cantidad no valida.\n");
                    } else {
                        printf("Ingrese porcentaje de descuento (0 para ninguno): ");
                        scanf("%f", &porcentaje_descuento);

                        float subtotal = cantidad_operacion * precio_unitario;
                        float descuento_aplicado = subtotal * (porcentaje_descuento / 100);
                        float total_venta = subtotal - descuento_aplicado;

                        stock -= cantidad_operacion;
                        ganancias_totales += total_venta;

                        printf("\n--- Resumen de Transaccion ---");
                        printf("\nSubtotal:\t$%.2f", subtotal);
                        printf("\nDescuento:\t$%.2f", descuento_aplicado);
                        printf("\nTotal Pago:\t$%.2f", total_venta);
                        printf("\n[OK] Venta exitosa. Stock restante: %d\n", stock);
                    }
                }
                break;

            case 3: 
                printf("\n--- Reabastecimiento ---");
                printf("\nCantidad a agregar al stock: ");
                scanf("%d", &cantidad_operacion);

                if (cantidad_operacion < 0) {
                    printf("\n[!] Error: No se pueden agregar cantidades negativas.\n");
                } else {
                    stock += cantidad_operacion;
                    printf("\n[OK] Stock actualizado. Nuevo total: %d unidades.\n", stock);
                }
                break;

            case 4: 
                printf("\n\t--- Ficha del Producto ---");
                printf("\n\tID:\t\t%s", ID);
                printf("\n\tNombre:\t\t%s", nombre);
                printf("\n\tStock:\t\t%d unidades", stock);
                printf("\n\tPrecio Unit.:\t$%.2f", precio_unitario);
                printf("\n\t--------------------------\n");
                break;

            case 5:
                printf("\n\tGANANCIAS ACUMULADAS: $%.2f", ganancias_totales);
                break;

            case 6:
                printf("\nCerrando el sistema. ¡Suerte en la entrega, Joseph!\n");
                break;

            default:
                printf("\n[!] Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 6);

    return 0;
}