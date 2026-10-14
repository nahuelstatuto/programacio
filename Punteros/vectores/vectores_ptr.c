#include <stdio.h>

#define N 5

int main(void) {
    /* Declaració d'una variable sencera i un vector */
    int var = 10;
    int vector[N] = {1, 2, 3, 4, 5};
    int i; /* loops */

    /* Punter a una variable */
    /* int *ptrVar = &var;   
    int *ptrVector = &vector;   així també es podria fer */
    
    int *ptrVar, *ptrVector;

    ptrVar = &var;
    ptrVector = vector;  /* Punter a un vector (realment apunta al primer element) */

    /* Mostrant el valor de la variable a través del punter */
    printf("Valor de var: %d\n", var);
    printf("Valor a través de ptrVar: %d\n", *ptrVar);
    printf("Adreça de var: %p\n", (void*)&var);
    printf("Adreça emmagatzemada en ptrVar: %p\n\n", (void*)ptrVar);

    /* Mostrant els valors del vector usant el punter */
    printf("Valors del vector usant ptrVector:\n");
    for (i = 0; i < N; i++) {
        printf("vector[%d] = %d (usant ptrVector: %d)\n", i, vector[i], *(ptrVector + i));
    }

    /* Mostrant adreces de memòria */
    printf("\nAdreces dels elements del vector:\n\n");
    printf("&vector = %p (ptrVector = %p)\n", (void*)vector, (void*)(ptrVector));


    for (i = 0; i < N; i++) {
        printf("&vector[%d] = %p (ptrVector + %d = %p)\n", i, (void*)&vector[i], i, (void*)(ptrVector + i));
    }

    return 0;
}
