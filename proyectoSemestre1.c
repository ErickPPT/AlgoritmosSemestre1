/* PROYECTO2: MÁQUINA DISPENSADORA DE BOLETOS DE AUTOBÚS */
#include <stdio.h> // Librería estándar para entrada y salida
#define Monedas 3 // Definimos el número de tipos de monedas disponibles
#define CantidadMonedas 3 // Definimos el tamaño del arreglo de cantidades de monedas
int main() {
    // Declaración de variables
    int tarifa = 6, respuesta; // Tarifa fija por kilómetro y variable para la respuesta del usuario
    int distancia, costoBoleto, monto, cambio; // Variables para la distancia, costo del boleto, monto ingresado y cambio
    int monedas[Monedas] = {5, 2, 1}; // Valores de las monedas disponibles
    int cantidad_monedas[CantidadMonedas] = {0}; // Inicializamos la cantidad de monedas a 0
    // Ciclo principal para permitir varios cálculos de viaje
    do {
        // Preguntar al usuario si desea realizar un viaje
        do {
            printf("Desea hacer un viaje? 1 Si, 0 NO\n");
            scanf("%d", &respuesta);
        } while (respuesta != 1 && respuesta!=0); // Aseguramos que la respuesta sea 1 o 0
        if (respuesta==0)
        {
            printf("Saliendo del programa...");
            break;
        }
        // Pedir al usuario la distancia del viaje
        do {
            printf("Ingresa la distancia del viaje en kilómetros\n");
            scanf("%d", &distancia);
        } while (distancia < 0); // Aseguramos que la distancia no sea negativa

        // Calcular el costo del boleto
        costoBoleto = distancia * tarifa;
        printf("El costo del boleto es: %d pesos\n", costoBoleto);
        // Pedir al usuario el monto a pagar y validarlo
        do {
            printf("Ingresa el monto que usted va a pagar\n");
            scanf("%d", &monto);

            if (monto < costoBoleto) { // Validar que el monto cubra el costo del boleto
                printf("El monto ingresado no cubre el costo del boleto. Por favor, intenta de nuevo.\n");
            }
        } while (monto < costoBoleto);
        // Calcular el cambio a entregar
        cambio = monto - costoBoleto;
        printf("El cambio a entregar es %d pesos\n", cambio);
        int cambiototal = cambio;
        // Calcular la cantidad de monedas necesarias para el cambio
        for (int i = 0; i < 3; i++) {
            cantidad_monedas[i] = cambiototal / monedas[i]; // Cantidad de monedas de cada denominación
            cambiototal %= monedas[i]; // Restar el valor de las monedas entregadas
        }
        // Mostrar el desglose del cambio en monedas
        for (int i = 0; i < 3; i++) {
            if (cantidad_monedas[i] > 0) { // Mostrar solo las monedas que se van a entregar
                printf("Su cambio serán %d Monedas de %d\n", cantidad_monedas[i], monedas[i]);
            }
        }
        printf("Costo del boleto: %d pesos\n", costoBoleto);
        printf("Monto pagado: %d pesos\n", monto);
        printf("Cambio total entregado: %d pesos\n", cambio);
        // Preguntar al usuario si desea calcular otro viaje
        do {
            printf("Desea hacer un viaje? 1 Si, 0 NO\n");
            scanf("%d", &respuesta);
        } while (respuesta != 1 && respuesta!=0); // Aseguramos que la respuesta sea 1 o 0
        if (respuesta==0)
        {
            printf("Saliendo del programa...");
            break;
        }
    } while (respuesta == 1); // Continuar mientras la respuesta sea 1
    return 0; // Finalizar el programa
}