#include <stdio.h>//Libreria de entrada y salida de datos
#include <string.h>// Libreria para cadenas
#include "funciones.h" // Archivo de cabecera donde están las funciones recursivas
// Declaración de la función recursiva para el menú
void mostrarMenu() {
    int eleccion; // Variable para almacenar la opción seleccionada por el usuario
    // Mostrar opciones del menú
    printf("\n=== Menú Interactivo ===\n");
    printf("1. Invertir una cadena\n"); // Opción para invertir una cadena
    printf("2. Calcular el factorial de un número\n"); // Opción para calcular el factorial
    printf("3. Generar sucesión de Fibonacci\n"); // Opción para generar Fibonacci
    printf("4. Salir\n"); // Opción para salir del programa
    printf("Seleccione una opción\n"); // Solicita al usuario que elija una opción
    scanf("%d", &eleccion); // Lee la opción seleccionada
    // Evaluar la opción ingresada por el usuario
    switch (eleccion) {
        case 1: { // Invertir una cadena
            char cadena[100]; // Espacio para almacenar la cadena ingresada por el usuario
            printf("Ingrese una cadena\n");
            scanf("%s", cadena); // Lee la cadena del usuario
            int longitud = strlen(cadena); // Calcula la longitud de la cadena
            invertirCadena(cadena, 0, longitud - 1); // Llama a la función recursiva para invertir la cadena
            printf("Cadena invertida: %s\n", cadena); // Imprime la cadena invertida
            break;
        }
        case 2: { // Calcular el factorial
            int numero; // Variable para almacenar el número ingresado por el usuario
            printf("Ingrese un número entero positivo\n");
            scanf("%d", &numero); // Lee el número del usuario
            if (numero < 0) { // Verifica que el número sea positivo
                printf("El número debe ser positivo.\n"); // Mensaje de error si es negativo
            } else {
                // Llama a la función recursiva para calcular el factorial y muestra el resultado
                printf("El factorial de %d es: %llu\n", numero, factorial(numero));
            }
            break;
        }
        case 3: { // Generar sucesión de Fibonacci
            int num; // Variable para almacenar el límite ingresado por el usuario
            printf("Ingrese el límite para la sucesión de Fibonacci\n");
            scanf("%d", &num); // Lee el límite del usuario
            printf("Sucesión de Fibonacci hasta %d: ", num);
            fibonacciRecursivo(num, 0, 1); // Llama a la función recursiva para generar Fibonacci
            printf("\n"); // Salto de línea después de imprimir la sucesión
            break;
        }
        case 4: // Salir del programa
            printf("Fin del programa\n"); // Mensaje de despedida
            return; // Detener la recursión y salir del programa
        default: // Caso para opciones no válidas
            printf("Opción no válida, intente de nuevo.\n"); // Mensaje de error
    }
    printf("\n");
    mostrarMenu(); // Llamada recursiva para volver a mostrar el menú después de cada acción
}
// Función principal
int main() {
    mostrarMenu(); // Iniciar el menú interactivo llamando a la función recursiva
    return 0; // Finaliza el programa correctamente
}