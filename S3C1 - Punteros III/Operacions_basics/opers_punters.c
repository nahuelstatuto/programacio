/* opers_punters.c 
operacions de increment i decrement amb punters
l'ides és que ells diguin que mostra cada printf
*/

#include<stdio.h>

int main() {

    int a = 3, x, y;
    int *pa;

    pa = &a;
    printf("\n ----------------------\n");
    printf("a: \t %d\n",a);
    printf("pa: \t %p\n",pa);
    printf("*pa: \t %d\n",*pa);
    x = *++pa;
    printf("\npa: \t %p\n",pa);
    printf("*pa: \t %d\n\n",*pa);
    y = *pa++;
    
    printf("x: \t %d\n",x);
    printf("y: \t %d\n",y);
        printf("\n\n");    

    printf("a: \t %d\n",a);
    printf("pa: \t %p\n",pa);
    printf("*pa: \t %d\n",*pa);


    printf("\n ----------------------\n");

    pa = &a;
    
    printf("a: \t %d\n",a);
    printf("pa: \t %p\n",pa);
    printf("*pa: \t %d\n",*pa);
    
    x = ++(*pa);
    printf("\npa: \t %p\n",pa);
    printf("*pa: \t %d\n\n",*pa);
    y = (*pa)++;
    
    printf("x: \t %d\n",x);
    printf("y: \t %d\n",y);
    
    printf("\n\n");    

    printf("a: \t %d\n",a);
    printf("pa: \t %p\n",pa);
    printf("*pa: \t %d\n",*pa);

    return 0;
}
