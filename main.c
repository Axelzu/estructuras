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
void ingresarAlumnos(struct Alumno *alumnos, int numAlumnos) {
    for (int i = 0; i < numAlumnos; i++) {
        printf("\nIngrese la información del alumno #%d:\n", i + 1);

        printf("Matrícula: ");
        scanf("%d", &alumnos[i].matricula);

        
        while(getchar() != '\n'); // el getchar es para devolver un caracter leido 

        printf("Nombre: ");
        fgets(alumnos[i].nombre, sizeof(alumnos[i].nombre), stdin);
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0'; //  el fgets nos ayuda a leer los caracteres de la posición actual de ruta hasta el primer carácter de nueva línea , hasta el final de la ruta o hasta que el número de caracteres leídos sea igual a n-1.

        printf("Dirección: ");
        fgets(alumnos[i].direccion, sizeof(alumnos[i].direccion), stdin); // stdin es como un apuntador para otro archivo es algo similar al getchar
        alumnos[i].direccion[strcspn(alumnos[i].direccion, "\n")] = '\0'; // sizeof es para poder almacenar o proorcionar una cantidad de almacenamiento 

        printf("Carrera: ");
        fgets(alumnos[i].carrera, sizeof(alumnos[i].carrera), stdin);
        alumnos[i].carrera[strcspn(alumnos[i].carrera, "\n")] = '\0';  // el strcspn busca una primera aparicion de un caracter string 1 que pertenece a un conjunto de caracteres especificos por string 2

        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
    }
}