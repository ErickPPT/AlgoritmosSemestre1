/*Erick Pisuña y Jair Robles*/
#include<stdio.h>
#include <string.h>
#include"funcionesProyecto.h"
#define RESET "\033[0m"         // Restablece colores
#define RED "\033[31m"          // Texto rojo
#define GREEN "\033[32m"        // Texto verde
#define YELLOW "\033[33m"       // Texto amarillo
#define BLUE "\033[34m"         // Texto azul
#define MAGENTA "\033[35m"      // Texto magenta
#define CYAN "\033[36m"         // Texto cian
int main() {
    int continuar;
    do
    {
        int Cont [4] ={0};
        int cont[8]={0};
        int valores[4][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {1, 0, 0},
            {1, 1, 0}
        };
        int valores1[8][4]={
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {1, 0, 0, 0},
            {1, 0, 1, 0},
            {1, 1, 0, 0},
            {1, 1, 1, 0}
        };

        mostrarInicio();
        int numVariables; 
        do { 
            printf("Digite el número de variables lógicas, solo 2 o 3: "); 
            scanf("%d", &numVariables); 
            if (numVariables != 2 && numVariables != 3) 
                { printf("Error: Solo puede digitar los números dos o tres.\n"); 
                } 
        } while (numVariables != 2 && numVariables != 3); 

        if (numVariables==2)
        {
            Arreglo2(valores);
            Booleano(valores, Cont);


        }
        if (numVariables==3)
        {
            Arreglo3(valores1);
            Booleano1(valores1, cont);
        }
        printf("Presione 1 si desea volver a correr el programa");
        scanf("%d", &continuar);
    } while (continuar==1);
    
    return 0; 
}