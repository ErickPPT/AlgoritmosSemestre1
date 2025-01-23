//3 intentos para adivinar el numero, se acaba
//3 intentos para adivinar pero que se pueda repetir
//pregunta si quieres jugar
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int numero;
    int respuesta;
    int aleatorio;
    srand(time(NULL)); //orden necesaria para generar numeros aleatorios
    
    do
    {
        printf("ingresa un numero del 0 al 10\n");
         numero=rand()%10; //genera numeros del 0 al 100
        
        scanf("%d", &aleatorio);
        if (aleatorio==numero)
        {
            printf("ganaste\n");
        }
        else
        {
            printf("perdiste el numero era\n");
            printf("%d\n", numero);
        }
    
        printf("deseas continuar (1 Si o 0 No)-> ");
        scanf("%d", &respuesta);
    } while (respuesta!=0);
    
}