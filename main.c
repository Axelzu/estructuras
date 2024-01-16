#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno {
    int matricula;
    char nombre[50];
    char direccion[100];
    char carrera[50];
    float promedio;
};
void ingresarAlumnos(struct Alumno *alumnos, int numAlumnos);
void mostrarAlumnos(struct Alumno *alumnos, int numAlumnos);

int main() {
    int opcion;
    int numAlumnos = 0;

    struct Alumno *alumnos = NULL;

    do {
        printf("\n----- Menú -----\n");
        printf("1. Ingresar alumnos\n");
        printf("2. Mostrar información de los alumnos\n");
        printf("3. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nIngrese el número de alumnos: ");
                scanf("%d", &numAlumnos);

                alumnos = (struct Alumno *)malloc(numAlumnos * sizeof(struct Alumno));

                if (alumnos == NULL) {
                    printf("Error de asignación de memoria.\n");
                    return 1;
                }

                ingresarAlumnos(alumnos, numAlumnos);
                break;

            case 2:
                if (numAlumnos > 0) {
                    mostrarAlumnos(alumnos, numAlumnos);
                } else {
                    printf("Aún no se han ingresado alumnos.\n");
                }
                break;

            case 3:
                free(alumnos);
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;

            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }

    } while (opcion != 3);

    return 0;
}