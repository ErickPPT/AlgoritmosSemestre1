#include <stdio.h>//libreria de entrada y salida de datos
int main() {
    //variables utilizadas para el desarrollo del ejercicio
    int numero, invertido = 0, resto, i;
    do
    {
       printf("Ingresa un número\n");
        scanf("%d", &numero);
        //controla que el numero no sea 0 o menores a 0
    } while (numero<=0);

    //repite el ciclo mientras el numero tenga valor diferente de 0
    for ( i = 0; numero !=0; i++)
    {
        //obtiene el ultimo digito
        resto = numero % 10;        
        //se añade al número invertido  
        invertido = invertido * 10 + resto; 
        //elimina el último dígito del número
        numero = numero / 10;         
    }
    //salida del numero invertido
    printf("El número invertido es %d", invertido);
    return 0;
}