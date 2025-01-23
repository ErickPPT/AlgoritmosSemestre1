#ifndef FUNCIONES_H // Preprocesador: evita múltiples inclusiones del archivo
#define FUNCIONES_H

#include <stdio.h> // Librería estándar para entrada y salida
#include <string.h> // Librería para manipulación de cadenas

// Función para invertir una cadena de texto recursivamente
// Parámetros:
// cadena: arreglo de caracteres (la cadena a invertir)
// inicio: posición inicial para invertir
// fin: posición final para invertir
void invertirCadena(char cadena[], int inicio, int fin) {
    if (inicio >= fin) { // Condición base: cuando inicio es mayor o igual a fin
        return; // Detiene la recursión
    }
    char temp = cadena[inicio]; // Almacena el carácter actual temporalmente
    cadena[inicio] = cadena[fin]; // Intercambia caracteres entre inicio y fin
    cadena[fin] = temp; // Asigna el carácter temporal a la posición final
    invertirCadena(cadena, inicio + 1, fin - 1); // Llama recursivamente para invertir el resto
}

// Función para calcular el factorial de un número recursivamente
// Parámetros:
// n: número entero cuyo factorial se calculará
// Retorna: el factorial de n como un número entero largo sin signo
unsigned long long factorial(int numero) {
    if (numero <= 1) { // Condición base: factorial de 0 o 1 es 1
        return 1; // Retorna 1
    }
    return numero * factorial(numero - 1); // Llama recursivamente para calcular factorial
}

// Función auxiliar para imprimir la sucesión de Fibonacci recursivamente
// Parámetros:
// num: límite superior para la sucesión de Fibonacci
// a: primer número de la sucesión
// b: segundo número de la sucesión
void fibonacciRecursivo(int num, int a, int b) {
    if (a > num) { // Condición base: detiene la recursión cuando a excede el límite
        return; // Detiene la recursión
    }
    printf("%d ", a); // Imprime el número actual de la sucesión
    fibonacciRecursivo(num, b, a + b); // Llama recursivamente para calcular el siguiente número
}

#endif // Final del archivo de cabecera