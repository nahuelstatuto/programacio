#include<stdio.h>

int main() {

    int a[] = {1, 5, 9};
    int *pa = a; /* pa apunta a a[0] */
    int x, y, z;


    pa++; /* pa apunta a a[1] */
    --pa; /* pa apunta a a[0] */
    x = ++*pa; /* a[0]=2, x=2, pa apunta a a[0] */
    y = *pa++; /* y=2, pa apunta a a[1] */
    z = *++pa; /*pa apunta a[2], z=pa[2] i.e. 9, a[1] sense canvi */

    (*pa)++; /* a[2J=10, pa apunta a a[2] */
    ++(*pa); /* a[2]=11, pa apunta a a[2] */
    pa++; /* pa apunta a a[3] */
    
    printf("a[] = {%d, %d, %d}\n", a[0], a[1], a[2]);
    printf("x=%d y=%d, z=%d\n", x, y, z);
    printf("*pa vale:%d \n", *pa);
    printf("pa apunta al elemento: a[%ld]\n", pa-a);

    return 0;
}
