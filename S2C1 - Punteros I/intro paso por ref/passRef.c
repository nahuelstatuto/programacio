/* passRef.c

ejemplo básico de paso por referencia. La primera función A no hace nada ya 
que recibe num pero no devuelve el valor. En cambio la función B recibe las 
direcciones.

Mostrar el progama y preguntar: que escribe cada print

*/#include<stdio.h>
#include<math.h>

void A(int num);
void B(int* num);

int main(void) {
    int num;
    num = 55;
    printf("num: %d \n",num);
    A(num);
    printf("num: %d \n",num);
    printf("&num: %p \n",&num);
    B(&num);
    printf("num: %d \n",num);
    printf("&num: %p \n",&num);
    return 0;
}

void A(int num) {
    num = num + 1;
}

void B(int *num) {
    printf("num_B: %p \n",num);
    printf("*num_B: %d \n",*num);
    printf("&num_B: %p \n",&num);
    *num = *num + 1;
}
