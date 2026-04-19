#include <stdio.h>

int main() {
    float cal[5][3];
    char nombres[5][20];
    char materias[3][20] = {"FISICA", "MATEMATICAS", "LENGUA"};
    int opc, i, a;
    float max, min, suma; 
    do {
        printf("\nGESTION DE CALIFICACIONES\n");
        printf("1. Registrar nombres de estudiantes\n");
        printf("2. Registrar notas (0-10)\n");
        printf("3. Reporte: Promedios (Estudiante y Asignatura)\n");
        printf("4. Reporte: Calificaciones Maximas y Minimas\n");
        printf("5. Reporte: Aprobados y Reprobados por Asignatura\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                for (i = 0; i < 5; i++) {
                    printf("Nombre estudiante %d: ", i + 1);
                    scanf("%s", nombres[i]);
                }
                break;

            case 2:
                for (i = 0; i < 5; i++) {
                    printf("\nNotas para %s:\n", nombres[i]);
                    for (a = 0; a < 3; a++) {
                        do {
                            printf("  %s: ", materias[a]);
                            scanf("%f", &cal[i][a]);
                            if (cal[i][a] < 0 || cal[i][a] > 10) 
                                printf("  Error: La nota debe estar entre 0 y 10.\n");
                        } while (cal[i][a] < 0 || cal[i][a] > 10);
                    }
                }
                break;

            case 3:
                printf("\nPROMEDIOS POR ESTUDIANTE\n");
                for (i = 0; i < 5; i++) {
                    suma = 0;
                    for (a = 0; a < 3; a++) suma += cal[i][a];
                    printf("%s: %.2f\n", nombres[i], suma / 3);
                }
                printf("\nPROMEDIOS POR ASIGNATURA\n");
                for (a = 0; a < 3; a++) {
                    suma = 0;
                    for (i = 0; i < 5; i++) suma += cal[i][a];
                    printf("%s: %.2f\n", materias[a], suma / 5);
                }
                break;

            case 4:
                printf("\nMAXIMOS Y MINIMOS POR ESTUDIANTE\n");
                for (i = 0; i < 5; i++) {
                    max = cal[i][0]; min = cal[i][0];
                    for (a = 1; a < 3; a++) {
                        if (cal[i][a] > max) max = cal[i][a];
                        if (cal[i][a] < min) min = cal[i][a];
                    }
                    printf("%s -> Max: %.2f | Min: %.2f\n", nombres[i], max, min);
                }
                printf("\nMAXIMOS Y MINIMOS POR ASIGNATURA\n");
                for (a = 0; a < 3; a++) {
                    max = cal[0][a]; min = cal[0][a];
                    for (i = 1; i < 5; i++) {
                        if (cal[i][a] > max) max = cal[i][a];
                        if (cal[i][a] < min) min = cal[i][a];
                    }
                    printf("%s -> Max: %.2f | Min: %.2f\n", materias[a], max, min);
                }
                break;

            case 5:
                printf("\nSTADO DE APROBACION POR ASIGNATURA\n");
                for (a = 0; a < 3; a++) {
                    int ap = 0, rep = 0;
                    for (i = 0; i < 5; i++) {
                        if (cal[i][a] >= 6) ap++;
                        else rep++;
                    }
                    printf("%s -> Aprobados: %d | Reprobados: %d\n", materias[a], ap, rep);
                }
                break;
        }
    } while (opc != 6);

    return 0;
}