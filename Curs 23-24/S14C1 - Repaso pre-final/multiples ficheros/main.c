/* ejemplo para compilar 2 (o más) ficheros.

gcc -c main.c funciones.c -Wall -ansi
gcc -o main.exe main.o funciones.o -lm
./main.exe

*/

#include <stdio.h>
#include "funciones.h"

int main(void){
    printf("%s:%s:%d \n", __FILE__, __FUNCTION__, __LINE__);
    test();
    return 0;
}