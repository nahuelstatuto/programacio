/*
Nos movemos por la memoria
*/

#include <stdio.h>

int main(void){

   int v=1, a=2, b=3, c=5, d=7;

   printf("v=%d, \t direccio=%p \n", v, &v);
   printf("a=%d, \t direccio=%p \n", a, &a);
   printf("b=%d, \t direccio=%p \n", b, &b);
   printf("c=%d, \t direccio=%p \n", c, &c);
   printf("d=%d, \t direccio=%p \n", d, &d); 

   printf("\n");

   *(&d+1) = 11; /*c*/
   *(&d+2) = 13; /*b*/
   *(&d+3) = 17; /*a*/   

   printf("v1=%d, \t direccio=%p \n", d, &d);
   printf("v2=%d, \t direccio=%p \n", *(&d+1), &d+1);
   printf("v3=%d, \t direccio=%p \n", *(&d+2), &d+2);
   printf("v4=%d, \t direccio=%p \n", *(&d+3), &d+3);
   
   printf("\n");


   printf("a=%d, \t direccio=%p \n", a, &a);
   printf("b=%d, \t direccio=%p \n", b, &b);
   printf("c=%d, \t direccio=%p \n", c, &c);
   printf("d=%d, \t direccio=%p \n", d, &d);

   return 0;
}

