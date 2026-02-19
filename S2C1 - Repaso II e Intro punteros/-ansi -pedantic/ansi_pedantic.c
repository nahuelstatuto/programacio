/* ansi_pedantic.c

este programa compila sin problemas para gcc y gcc -ansi pero al añadir el -pedantic 
da un warning, pues se define un array de longitud variable que no se permite en ISO C90

*/ 


#include <stdio.h>

int main(void)
{
    int i, n = 4;
    double x[n];

    for (i = 0; i < n; i++)  x[i] = i;

    return 0;
}
