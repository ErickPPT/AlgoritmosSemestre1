#include <stdio.h> 
#include <string.h>
#define RESET "\033[0m"         // Restablece colores
#define RED "\033[31m"          // Texto rojo
#define GREEN "\033[32m"        // Texto verde
#define YELLOW "\033[33m"       // Texto amarillo
#define BLUE "\033[34m"         // Texto azul
#define MAGENTA "\033[35m"      // Texto magenta
#define CYAN "\033[36m"         // Texto cian
void mostrarInicio() { 
printf("************************************\n"); 
printf(" MATEMATICAS DISCRETAS 1\n"); 
printf(" NOMBRES DE LOS INTEGRANTES: Jair Robles y Erick Pisuña\n"); 
printf(" Programa que implemente una expresión SOP (Suma de Productos) a partir de una tabla de verdad ingresada por el usuario.\n"); 
printf(" 2024-2025\n"); 
printf("************************************\n"); }
#include<stdio.h>
void Print(int matriz[4][3]) {
    int j;
    printf("a b s\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        if(matriz[i][2] == 1){
                printf(GREEN"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
        printf("\n");
    }   
}
void Arreglo2(int valores[4][3]) {
    int V;
    printf("Ingrese solo 0 y 1\n");
    printf("A B S\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", valores[i][j]);
        }
        do
        {
        scanf("%d", &V);
        valores[i][2]=V;
        if (V != 0 && V != 1) 
                { printf("Error: Solo puede digitar los números cero o uno.\n"); 
                } 
        } while (V!=1 && V!=0 );
    }
}
 void Booleano(int valores[4][3], int*Cont){ 

    int primer_termino = 1;
    int term=0;
    printf("La expresion booleana es: ");
    if (valores[0][2] == 1) {
       
        if (!primer_termino) {
        printf(" + ");}
        printf("A'*B'");
        primer_termino = 0;
        Cont[0]=1;
        term++;
    }
    if (valores[1][2] == 1) {
        
        if (!primer_termino) {printf(" + ");}
        printf("A'*B");
        primer_termino = 0;
        Cont[1] = 1;
        term++;
    }
    if (valores[2][2] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A*B'");
        primer_termino = 0;
        Cont[2] = 1;
        term++;
    }
    if (valores[3][2] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A*B");
        primer_termino = 0;
        Cont[3] = 1;
        term++;
    }
    printf("\n");
    TabladeDos(Cont, term);

 }

int TabladeDos(int Cont[4], int term) {
    int A[4][3] = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int B[4][3] = {
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 0},
        {0, 1, 0}
    };
    int C[4][3] = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
    };
    int D[4][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 1}
    };

    if (Cont[0]==1&&term==1) {
        printf("Seleccionaste A'*B':\n");
        Print(A);
    }
    if (Cont[1]==1&&term==1) {
        printf("Seleccionaste A'*B:\n");
        Print(B);
    }
    if (Cont[2]==1&&term==1) {
        printf("Seleccionaste A*B':\n");
        Print(C);
    }
    if (Cont[3]==1&&term==1) {
        printf("Seleccionaste A*B:\n");
        Print(D);
    }
     if (Cont[0] == 1 && Cont[1]== 1 && term == 2){
        printf("Seleccionaste A'*B' + A'*B:\n");
        remplazardos(A,B);
    }
     if (Cont[0] == 1 && Cont[2]== 1 && term == 2){
        printf("Seleccionaste A'*B' + A*B':\n");
        remplazardos(A,C);
    }
     if (Cont[0] == 1 && Cont[3]== 1 && term == 2){
        printf("Seleccionaste A'*B' + A*B:\n");
        remplazardos(A,D);
    }
    if (Cont[1] == 1 && Cont[2]== 1 && term == 2){
        printf("Seleccionaste A'*B + A*B':\n");
        remplazardos(B,C);
    }
     if (Cont[1] == 1 && Cont[3]== 1 && term == 2){
        printf("Seleccionaste A'*B + A*B:\n");
        remplazardos(B,D);
    }
    if (Cont[2] == 1 && Cont[3]== 1 && term == 2){
        printf("Seleccionaste A*B' + A*B:\n");
        remplazardos(C,D);
    }

    if (Cont[0] == 1 && Cont[1]== 1 && Cont[2]==1 && term == 3){
        printf("Seleccionaste A'*B' + A'*B + A*B':\n");
        remplazartres(A,B,C);
    }
     if (Cont[0] == 1 && Cont[1]== 1 && Cont[3] && term == 3){
        printf("Seleccionaste A'*B' + A'*B + A*B:\n");
        remplazartres(A,B,D);
    }
    if (Cont[0] == 1 && Cont[2]== 1 && Cont[3] && term == 3){
        printf("Seleccionaste A'*B' + A*B' + A*B:\n");
        remplazartres(A,C,D);
    }
     if (Cont[1] == 1 && Cont[2]== 1 &&  Cont[3]==1 && term == 3){
        printf("Seleccionaste A'*B + A*B' + A*B:\n");
        remplazartres(B,C,D);
     }

     if (Cont[0] == 1 && Cont[1]== 1 &&  Cont[2]==1 && Cont[3]==1 && term == 4){
        printf("Seleccionaste A'*B' + A'*B + A*B' + A*B:\n");
        remplazarcuatro(A,B,C,D);
        }
    return 0;
}
void remplazardos(int tabla1[4][3], int tabla2[4][3]){
int matriz[4][6]= {0};
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0; j < 2; j ++){
            printf("%d ", tabla1[i][j]);
        }
            printf(GREEN "%d"RESET , tabla1[i][2]);
            printf("        ");
            if(tabla1[i][2] || tabla2[i][2]){
                printf(RED"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
            printf("        ");
        for(int h = 0; h < 2; h ++){
            printf("%d ", tabla2[i][h]);
        }
            printf(GREEN "%d"RESET , tabla2[i][2]);
            printf("\n");   
    }
}
void remplazartres(int tabla1[4][3], int tabla2[4][3],int tabla3[4][3]){
int matriz[4][6]= {0};
    for(int i = 0 ; i < 4 ; i++){
        printf("(");

        for(int j = 0; j < 2; j ++){
            printf("%d ", tabla1[i][j]);
        }
            printf(GREEN "%d"RESET , tabla1[i][2]);

            printf("        ");
            if(tabla1[i][2] || tabla2[i][2]){
                printf(RED"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
            printf("        ");

        for(int h = 0; h < 2; h ++){
            printf("%d ", tabla2[i][h]);
        }
            printf(GREEN "%d"RESET , tabla2[i][2]);
            printf(")"); 
        printf("        ");
            if((tabla1[i][2] || tabla2[i][2])||tabla3[i][2] == 1){
                printf(RED"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
            printf("        ");

        for(int h = 0; h < 2; h ++){
            printf("%d ", tabla3[i][h]);
        }
            printf(GREEN "%d"RESET , tabla3[i][2]);
            printf("\n");  
    }
}

void remplazarcuatro(int tabla1[4][3], int tabla2[4][3],int tabla3[4][3],int tabla4[4][3]){
int matriz[4][6]= {0};
    for(int i = 0 ; i < 4 ; i++){
        printf("("); 
        //Matriz 1
        for(int j = 0; j < 2; j ++){
            printf("%d ", tabla1[i][j]);
        }
            printf(GREEN "%d"RESET , tabla1[i][2]);
            //Resultado
            printf("        ");
            if(tabla1[i][2] || tabla2[i][2]){
                printf(RED"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
            printf("        ");
        //matriz 2
        for(int h = 0; h < 2; h ++){
            printf("%d ", tabla2[i][h]);
        }
            printf(GREEN "%d"RESET , tabla2[i][2]);
            printf(")"); 
        //Resultado final
            printf("        ");
            if((tabla1[i][2] || tabla2[i][2])||(tabla3[i][2] || tabla4[i][2]==1)){
                printf(RED"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
            printf("        ");
        printf("(");
        //Matriz 3
        for(int l = 0; l < 2; l ++){
            printf("%d ", tabla3[i][l]);
        }
            printf(GREEN "%d"RESET , tabla3[i][2]);
            //Resultado
            printf("        ");
        if(tabla3[i][2] || tabla4[i][2]){
            printf(RED"1 "RESET);
        }else{
            printf(RED"0 "RESET);
        }
            printf("        ");

        for(int k= 0; k < 2; k ++){
            printf("%d ", tabla4[i][k]);
        }
            printf(GREEN "%d"RESET , tabla4[i][2]);
            printf(")"); 
            printf("\n");   
    }
}
void Print1(int matriz[8][4]) {
    int j;
    printf("a b s\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        if(matriz[i][3] == 1){
                printf(GREEN"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
        printf("\n");
    }   
}

 void Arreglo3(int valores1[8][4]) {
    int V;
    printf("Ingrese solo 0 y 1\n");
    printf("A B C S\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", valores1[i][j]);
        }
        do
        {
        scanf("%d", &V);
        valores1[i][3]=V;
        if (V != 0 && V != 1) 
                { printf("Error: Solo puede digitar los números cero o uno.\n"); 
                } 
        } while (V!=1 && V!=0);
    }
}

void Booleano1(int valores1[8][4], int*cont){ 
    int primer_termino = 1;
    int term=0;
        printf("La expresion booleana es: ");

    if (valores1[0][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A'*B'*C'");
        primer_termino = 0;
        cont[0]=1;
        term++;
    }
    if (valores1[1][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A'*B'*C");
        primer_termino = 0;
        cont[1]=1;
        term++;
    }
    if (valores1[2][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A'*B*C'");
        primer_termino = 0;
        cont[2]=1;
        term++;
    }
    if (valores1[3][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A'*B*C");
        primer_termino = 0;
        cont[3]=1;
        term++;
    }
    if (valores1[4][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A*B'*C'");
        primer_termino = 0;
        cont[4]=1;
        term++;
    }
    if (valores1[5][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A*B'*C");
        primer_termino = 0;
        cont[5]=1;
        term++;
    }
    if (valores1[6][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A*B*C'");
        primer_termino = 0;
        cont[6]=1;
        term++;
    }
    if (valores1[7][3] == 1) {
        if (!primer_termino) {printf(" + ");}
        printf("A*B*C");
        primer_termino = 0;
        cont[7]=1;
        term++;
    }

    printf("\n");
    Seleccion1(cont, term);
 }
 int Seleccion1(int Contador[8], int term) {
    int matrices[8][8][4] = {
        {{1,1,1,1}, {1,1,0,0}, {1,0,1,0}, {1,0,0,0}, {0,1,1,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,0}}, // A
        {{1,1,0,0}, {1,1,1,1}, {1,0,0,0}, {1,0,1,0}, {0,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,1,0}}, // B
        {{1,0,1,0}, {1,0,0,0}, {1,1,1,1}, {1,1,0,0}, {0,0,1,0}, {0,0,0,0}, {0,1,1,0}, {0,1,0,0}}, // C
        {{1,0,0,0}, {1,0,1,0}, {1,1,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,1,1,0}}, // D
        {{0,1,1,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,0}, {1,1,1,1}, {1,1,0,0}, {1,0,1,0}, {1,0,0,0}}, // E
        {{0,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,1,0}, {1,1,0,0}, {1,1,1,1}, {1,0,0,0}, {1,0,1,0}}, // F
        {{0,0,1,0}, {0,0,0,0}, {0,1,1,1}, {0,1,0,0}, {1,0,1,0}, {1,0,0,0}, {1,1,1,1}, {1,1,0,0}}, // G
        {{0,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,1,1,0}, {1,0,0,0}, {1,0,1,0}, {1,1,0,0}, {1,1,1,1}}  // H
    };

    for (int i = 0; i < 8; i++) {
        if (Contador[i] == 1 && term == 1) {
            Print1(matrices[i]);
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (Contador[i] == 1 && Contador[j] == 1 && term == 2) {
                mat2(matrices[i], matrices[j]);
            }
            for (int k = j + 1; k < 8; k++) {
                if (Contador[i] == 1 && Contador[j] == 1 && Contador[k] == 1 && term == 3) {
                    mat3(matrices[i], matrices[j], matrices[k]);
                }
                for (int l = k + 1; l < 8; l++) {
                    if (Contador[i] == 1 && Contador[j] == 1 && Contador[k] == 1 && Contador[l] == 1 && term == 4) {
                        mat4(matrices[i], matrices[j], matrices[k], matrices[l]);
                    }
                    for (int m = l + 1; m < 8; m++) {
                        if (Contador[i] == 1 && Contador[j] == 1 && Contador[k] == 1 && Contador[l] == 1 && Contador[m] == 1 && term == 5) {
                            mat5(matrices[i], matrices[j], matrices[k], matrices[l], matrices[m]);
                        }
                        for (int n = m + 1; n < 8; n++) {
                            if (Contador[i] == 1 && Contador[j] == 1 && Contador[k] == 1 && Contador[l] == 1 && Contador[m] == 1 && Contador[n] == 1 && term == 6) {
                                mat6(matrices[i], matrices[j], matrices[k], matrices[l], matrices[m], matrices[n]);
                            }
                            for (int o = n + 1; o < 8; o++) {
                                if (Contador[i] == 1 && Contador[j] == 1 && Contador[k] == 1 && Contador[l] == 1 && Contador[m] == 1 && Contador[n] == 1 && Contador[o] == 1 && term == 7) {
                                    mat7(matrices[i], matrices[j], matrices[k], matrices[l], matrices[m], matrices[n], matrices[o]);
                                }
                                for (int p = o + 1; p < 8; p++) {
                                    if (Contador[i] == 1 && Contador[j] == 1 && Contador[k] == 1 && Contador[l] == 1 && Contador[m] == 1 && Contador[n] == 1 && Contador[o] == 1 && Contador[p] == 1 && term == 8) {
                                        mat8(matrices[i], matrices[j], matrices[k], matrices[l], matrices[m], matrices[n], matrices[o], matrices[p]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

void m(int i ,int matriz1[8][4]){
    for(int j = 0; j < 3; j ++){
            printf("%d ", matriz1[i][j]);
        }
            printf(GREEN "%d"RESET , matriz1[i][3]);
}

void r(int i,int matriz1[8][4], int matriz2[8][4]){
    if(matriz1[i][3] || matriz2[i][3]){
                printf(RED"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
            printf("        ");
}
    
void mat2(int matriz1[8][4], int matriz2[8][4]){
int matriz[4][6]= {0};
    for(int i = 0 ; i < 8 ; i++){
            m(i,matriz1);
            //Resultado
            printf("        ");
            r(i,matriz1,matriz2);
        //matriz 2
            m(i,matriz2);
            printf("\n");   
    }
}

void mat3(int matriz1[8][4], int matriz2[8][4],int matriz3[8][4]){
    for(int i = 0 ; i < 8 ; i++){
        printf("(");
        //Matriz 1
            m(i,matriz1);
            //Resultado
            printf("        ");
            r(i,matriz1,matriz2);
        //matriz 2
            m(i,matriz2);
            printf(")"); 
            printf("        ");
            if((matriz1[i][3] || matriz2[i][3])||matriz3[i][3] == 1){
                printf(RED"1 "RESET);
            }else{
                printf(RED"0 "RESET);
            }
            printf("        ");

        //matriz 3
            m(i,matriz3);
            printf("\n");  

    }
}

void mat4(int matriz1[8][4], int matriz2[8][4],int matriz3[8][4],int matriz4[8][4]){
    for(int i = 0 ; i < 8 ; i++){ 
        //Matriz 1
        printf("(");
        m(i,matriz1);
        printf("        ");
        //resultado 1,2
        r(i, matriz1, matriz2);
        //matriz 2
        m(i,matriz2);
        printf(")");
        printf("        ");
        //Resultado final
        if((matriz1[i][3] || matriz2[i][3])||(matriz3[i][3] || matriz4[i][3])){
            printf(RED"1 "RESET);
        }else{
            printf(RED"0 "RESET);
        }
        printf("        ");
        printf("(");
        //Matriz 3
        m(i,matriz3);
            //Resultado
            printf("        ");
        r(i, matriz3, matriz4);    
        //matriz 4
        m(i,matriz4);
            printf(")"); 
            printf("\n");   

    }
}

void mat5(int matriz1[8][4], int matriz2[8][4],int matriz3[8][4],int matriz4[8][4],int matriz5[8][4]){
    for(int i = 0 ; i < 8 ; i++){ 
        //Matriz 1
        printf("(");
        printf("(");
        m(i,matriz1);
        printf("        ");
        //resultado 1,2
        r(i, matriz1, matriz2);
        //matriz 2
        m(i,matriz2);
        printf(")");
        printf("        ");
        //Resultado final
        if((matriz1[i][3] || matriz2[i][3])||(matriz3[i][3] || matriz4[i][3])){
            printf(RED"1 "RESET);
        }else{
            printf(RED"0 "RESET);
        }
        printf("        ");
        printf("(");
        //Matriz 3
        m(i,matriz3);
            //Resultado
            printf("        ");
        r(i, matriz3, matriz4);    
        //matriz 4
        m(i,matriz4);
        printf(")");
        printf(")"); 
        printf("        ");
        //resultado  
        if(((matriz1[i][3] || matriz2[i][3])||(matriz3[i][3] || matriz4[i][3]))||matriz5[i][3]){
            printf(MAGENTA"1 "RESET);
        }else{
            printf(MAGENTA"0 "RESET);
        } 
        printf("        ");
        m(i,matriz5); 
        printf("\n");
    }
}

void mat6(int matriz1[8][4], int matriz2[8][4],int matriz3[8][4],int matriz4[8][4],int matriz5[8][4],int matriz6[8][4]){
    for(int i = 0 ; i < 8 ; i++){ 
        //Matriz 1
        printf("(");
        m(i,matriz1);
        printf("        ");
        //resultado
        r(i,matriz1,matriz2);
        //matriz 2
        m(i,matriz2);
        printf(")"); 
        printf("        ");
        if((matriz1[i][3] || matriz2[i][3])||(matriz3[i][3] || matriz4[i][3])){
                printf(BLUE"1 "RESET);
            }else{
                printf(BLUE"0 "RESET);
            } 
            printf("        ");
        //Matriz 3
        printf("(");
        m(i,matriz3);
        printf("        ");
        //resultado
        r(i,matriz3,matriz4);
        //matriz 4
        m(i,matriz4);
        printf(")"); 
        printf("        ");
        //RESULTADO FINAL
        if(((matriz1[i][3] || matriz2[i][3])||(matriz3[i][3] || matriz4[i][3]))|| (matriz5[i][3]||matriz6[i][3])){
                printf(MAGENTA"1 "RESET);
            }else{
                printf(MAGENTA"0 "RESET);
            } 
            printf("        ");
            //MATRIZ 5
            printf("(");
            m(i,matriz5);
            printf("        ");
            //resultado
            r(i,matriz5,matriz6);
            //matriz 4
            m(i,matriz6);
            printf(")"); 
        printf("\n");
    }
}

void mat7(int matriz1[8][4], int matriz2[8][4],int matriz3[8][4],int matriz4[8][4],int matriz5[8][4],int matriz6[8][4],int matriz7[8][4]){
    for(int i = 0 ; i < 8 ; i++){ 
        //Matriz 1
        printf("(");
        printf("(");
        m(i,matriz1);
        printf("        ");
        //resultado 1,2
        r(i, matriz1, matriz2);
        //matriz 2
        m(i,matriz2);
        printf(")");
        printf("        ");
        //Resultado final 12 34
        if((matriz1[i][3] || matriz2[i][3])||(matriz3[i][3] || matriz4[i][3])){
            printf(CYAN"1 "RESET);
        }else{
            printf(CYAN"0 "RESET);
        }
        printf("        ");
        printf("(");
        //Matriz 3
        m(i,matriz3);
            //Resultado
        printf("        ");
        r(i, matriz3, matriz4);    
        //matriz 4
        m(i,matriz4);
        printf(")"); 
        printf(")"); 
        printf("        ");
        if(matriz1[i][3]||matriz2[i][3]||matriz3[i][3]||matriz4[i][3] || matriz5[i][3]||matriz6[i][3] ||matriz7[i][3]){
            printf(MAGENTA"1 "RESET);
        }else{
            printf(MAGENTA"0 "RESET);
        }
        printf("        ");
        printf("(");
        printf("(");
        //Matriz 5
        m(i,matriz5);
        //Resultado
        printf("        ");
        r(i, matriz5, matriz6);    
        //matriz 6
        m(i,matriz6);
            printf(")");
         printf("        ");
        if((matriz5[i][3] || matriz6[i][3])||matriz7[i][3] ){
            printf(CYAN"1 "RESET);
        }else{
            printf(CYAN"0 "RESET);
        }
        printf("        ");
        //Matriz 7
        m(i,matriz7);
        printf(")");
            printf("\n");  

    }
}

void mat8(int matriz1[8][4], int matriz2[8][4],int matriz3[8][4],int matriz4[8][4],int matriz5[8][4],int matriz6[8][4],int matriz7[8][4],int matriz8[8][4]){
    for(int i = 0 ; i < 8 ; i++){ 
        //Matriz 1
        printf("(");
        printf("(");
        m(i,matriz1);
        printf("        ");
        //resultado 1,2
        r(i, matriz1, matriz2);
        //matriz 2
        m(i,matriz2);
        printf(")");
        printf("        ");
        //Resultado final 12 34
        if(matriz1[i][3] || matriz2[i][3]||matriz3[i][3] || matriz4[i][3]){
            printf(CYAN"1 "RESET);
        }else{
            printf(CYAN"0 "RESET);
        }
        printf("        ");
        printf("(");
        //Matriz 3
        m(i,matriz3);
            //Resultado
        printf("        ");
        r(i, matriz3, matriz4);    
        //matriz 4
        m(i,matriz4);
        printf(")"); 
        printf(")"); 
        printf("        ");
        if(matriz1[i][3]||matriz2[i][3]||matriz3[i][3]||matriz4[i][3] || matriz5[i][3]||matriz6[i][3] ||matriz7[i][3]||matriz8[i][3]){
            printf(YELLOW"1 "RESET);
        }else{
            printf(YELLOW"0 "RESET);
        }
        printf("        ");
        printf("(");
        printf("(");
        //Matriz 5
        m(i,matriz5);
        //Resultado
        printf("        ");
        r(i, matriz5, matriz6);    
        //matriz 6
        m(i,matriz6);
        printf(")");
        printf("        ");
        if((matriz5[i][3] || matriz6[i][3])||matriz7[i][3] ||matriz8[i][3]){
            printf(CYAN"1 "RESET);
        }else{
            printf(CYAN"0 "RESET);
        }
        printf("        ");
        printf("(");
        //Matriz 7
        m(i,matriz7);
        printf("        ");
        r(i,matriz7,matriz8);
        //Matriz 8
        m(i,matriz8);
        printf(")");
        printf(")");
            printf("\n");  

    }
}