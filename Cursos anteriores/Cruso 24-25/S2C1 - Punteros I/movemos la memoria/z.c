/*
Nos movemos por la memoria
*/

#include <stdio.h>

int main(void){

   int v=1, a=2, b=3, c=5, d=7;

   printf("v=%d, \t adress=%p \n", v, &v);
   printf("a=%d, \t adress=%p \n", a, &a);
   printf("b=%d, \t adress=%p \n", b, &b);
   printf("c=%d, \t adress=%p \n", c, &c);
   printf("d=%d, \t adress=%p \n", d, &d); 

   printf("\n");

   *(&v+1) = 11;
   *(&v+2) = 13;
   *(&v+3) = 17;
   

   printf("v1=%d, \t adress=%p \n", v, &v);
   printf("v2=%d, \t adress=%p \n", *(&v+1), &v+1);
   printf("v3=%d, \t adress=%p \n", *(&v+2), &v+2);
   printf("v4=%d, \t adress=%p \n", *(&v+3), &v+3);
   
   printf("\n");


   printf("a=%d, \t adress=%p \n", a, &a);
   printf("b=%d, \t adress=%p \n", b, &b);
   printf("c=%d, \t adress=%p \n", c, &c);
   printf("d=%d, \t adress=%p \n", d, &d);

   return 0;
}

