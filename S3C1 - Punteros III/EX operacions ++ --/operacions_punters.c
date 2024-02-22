#include<stdio.h>

int main() {

    int a[] = {1, 5, 9};
    int *pa = a;
    int x, y, z;


    pa++;
    --pa;
    x = ++*pa; 
    y = *pa++; 
    z = *++pa;

    (*pa)++;
    ++(*pa);
    pa++;
    
    printf("a[] = {%d, %d, %d}\n", a[0], a[1], a[2]);
    printf("x=%d y=%d, z=%d\n", x, y, z);
    printf("*pa vale:%d \n", *pa);
    printf("pa apunta al elemento: a[%ld]\n", pa-a);

    return 0;
}
