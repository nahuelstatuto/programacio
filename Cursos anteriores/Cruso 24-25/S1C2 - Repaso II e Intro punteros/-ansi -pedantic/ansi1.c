/* ansi1.c

El nombre de variable asm es válido bajo el estándar ANSI/ISO,
pero este programa no compila en GNU C porque asm es una
palabra reservada de la extensión GNU C

gcc -c ansi_pedantic.c            no compila, da error 
gcc -c ansi_pedantic.c -ansi      compila perfecto

*/

#include <stdio.h>


int main(void){
   const char asm[] = "6502";
   printf ("la cadena asm es ’%s’\n", asm);
   return 0;
}
