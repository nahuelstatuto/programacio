#include<stdio.h>

/* Leer para entender el proceso de reserva de memoria. O los motivos por lo que no los entendemos :)
El compilador decide, para optimizar el orden de la reserva, y muchas veces es el totalmente inverso al pensado.

De abajo a arriba y de derecha a izquierda.

https://stackoverflow.com/questions/58148075/order-of-memory-allocation-in-c
*/

int main() {

    int y, z, x;
    int a[] = {1, 5, 9};
    int *pa;

    pa=a;

    pa++;
    --pa;
    x = ++(*pa); 
    y = *(pa++); 
    z = *(++pa);

    (*pa)++;
    ++(*pa);
    pa++;
    
    printf("a[] = {%d, %d, %d}\n", a[0], a[1], a[2]);
    printf("a[] = {%p, %p, %p}\n", &a[0], &a[1], &a[2]);
    printf("x=%d y=%d, z=%d\n", x, y, z);
    printf("x=%p y=%p, z=%p\n", &x, &y, &z);
    printf("*pa vale:%d \n", *pa);
    printf("pa vale:%p \n", pa);
    printf("&pa vale:%p \n", &pa);
    printf("pa apunta al elemento: a[%d]\n", (int) (pa-a));

    return 0;
}
