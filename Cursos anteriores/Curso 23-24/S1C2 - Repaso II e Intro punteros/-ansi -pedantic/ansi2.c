/* ansi2.c
A la inversa, este programa compila usando solo gcc pero da error al usar el -ansi
La constante M_PI no es parte de la librería estándar ANSI/ISO de C pero si aparece en GNU
*/


#include <math.h>
#include <stdio.h>

int main(void){
    printf ("el valor de pi es %f\n", M_PI);
    return 0;
}
