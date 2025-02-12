/* opers.c 
operacions de increment i decrement. basics
l'ides és que ells diguin que mostra cada printf
*/

#include<stdio.h>

int main() {

    int a = 3;
    int x, y, z;

    printf("a: \t %d\n",a);
    
    x = ++a;
    y = a;
    z = a++;
    
    printf("x: \t %d\n",x);
    printf("y: \t %d\n",y);
    printf("z: \t %d\n",z);
    printf("a: \t %d\n",a);

    return 0;
}
