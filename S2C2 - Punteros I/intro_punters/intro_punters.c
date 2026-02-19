/* intro_punters.c 

cada case té descripció. La compilació té un warning que està contemplat

*/

#include <stdio.h>
#include <stdlib.h>

void func1();
void func2();
void error1();
void error2();
void sol_error();
void sol_error_no_leak();

int main(void) {
    int num;
    printf(" Escull una opció: \n");
    printf(" 1- Variable i punter\n");
    printf(" 2- Reasignacions\n");
    printf(" 3- Warning en compilació i error\n");
    printf(" 4- Sin warning en compilació i error\n");
    printf(" 5- Sense error! fuga de memòria.\n");
    printf(" 6- Sense error i utilitzan el free().\n");

    scanf("%d", &num);
    printf("\n");

    switch(num){
        case 1:
            /* es fan escriure adreces i continguts */
            func1();
            break;
        case 2:
            /*ús del operadors unaris: &   i   * */
            func2();
            break;
        case 3:
            /*
            us d'un punter sense inicialitzar
            compilació: warning
            execució: violació de segment
            */
            error1();
            break;
        case 4:
            /*
            us d'un punter amb una inicialització NULL
            compilació: CORRECTA
            execució: violació de segment
            */
            error2();
            break;
        case 5:
            /* us d'un punter correctament: guardant memòria explícitament */
            sol_error();
            break;
        case 6:
            /* us d'un punter correctament: guardant memòria explícitament i usant free*/
            sol_error_no_leak();
            break;

    }

    return 0;
}

void func1() {
   
    int i, *pi;

    i = 10;
    pi = &i;

    printf("variable normal int i: \n");
    printf("   adreça:  &i  = %p \n", (void *) &i);
    printf("   valor;    i  = %d \n", i);

    printf("\n");

    printf("variable punter int *pi: \n");
    printf("   adreça:            &pi = %p \n", (void *) &pi);
    printf("   valor:              pi = %p \n", (void *) pi);
    printf("   valor d'on apunta: *pi = %d \n", *pi);

    printf("\n");
}

void func2(){
    int a, *pa;        

    a = 1;    
    pa = &a;   


    /*  &, * són operadors inversos un de l'altre */
    printf("\n S'han fet les assignacions: a = 1; pa = &a. S'escriu: \n");
    printf(" Toca intro per continuar...\n");  
    getchar(); 
    printf("a   = %d \n", a);
    printf("&a  = %p \n", &a);
    printf("pa  = %p \n", pa);
    printf("*pa = %d \n", *pa);


    /* canviar a o *pa és equivalent */

    a = 2; 
    printf("\n S'ha reassignat a = 2. Es torna a escriure: \n");
    printf(" Toca intro per continuar...\n");  
    getchar(); 
    printf("a   = %d \n", a);
    printf("&a  = %p \n", &a);
    printf("pa  = %p \n", pa);
    printf("*pa = %d \n", *pa);

    *pa = 3; 
    printf("\n S'ha reassignat *pa = 3. Es torna a escriure: \n");
    printf(" Toca intro per continuar...\n");  
    getchar(); 
    printf("a   = %d \n", a);
    printf("&a  = %p \n", &a);
    printf("pa  = %p \n", pa);
    printf("*pa = %d \n", *pa);


    /* canvi de pa */
    pa = pa+1;
    printf("\n Es fa pa = pa+1 i es torna a escriure: \n");
    printf(" Toca intro per continuar...\n");  
    getchar(); 
    printf("a   = %d \n", a);
    printf("&a  = %p \n", &a);
    printf("pa  = %p \n", pa);
    printf("*pa = %d \n", *pa);

    printf("\n ¿Continua passant que   a   i   *pa   són iguals?");
    printf("\n Idem &a  i  pa ? \n Explicació?\n");
    printf(" Toca intro per continuar...\n");  
    getchar(); 


    a = 1;    
    pa = &a;

    /* canvi de *pa */
    *pa = *pa+1;
    printf("\n S'han fet les assignacions: a = 1; pa = &a. I es fa *pa = *pa+1 i es torna a escriure: \n");
    printf(" Toca intro per continuar...\n");  
    getchar(); 
    printf("a   = %d \n", a);
    printf("&a  = %p \n", &a);
    printf("pa  = %p \n", pa);
    printf("*pa = %d \n\n", *pa);
}

void error1(){
    int *pa;

    *pa = 2;
    printf("*pa = %d \n", *pa);

}

void error2(){
    int *pa=NULL;

    *pa = 2;
    printf("*pa = %d \n", *pa);

}

void sol_error(){
    int *pa;

    pa = (int *)malloc(sizeof(int));
    *pa = 2;
    printf("*pa = %d \n", *pa);

}

void sol_error_no_leak(){
    int *pa;

    pa = (int *)malloc(sizeof(int));
    *pa = 2;
    printf("*pa = %d \n", *pa);
    free(pa);

}

