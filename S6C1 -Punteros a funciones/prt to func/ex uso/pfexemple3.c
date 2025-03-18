/* pfexemple3.c

exemple d'ús d'un punter a funcions

les 4 operacions elementals amb enters

*/

#include <stdio.h>
   
int suma(int, int);
int resta(int, int);
int producte(int, int);
int divisio(int, int);

int main(void) {

   int a, b;
   char op;
   int (*pf)(int, int);    /* aquí es declara que "pf"
                           és una variable punter a funcions de prototipus
                                 int nom(int, int);
                           */
   printf(" a b ? (enters) \n");
   scanf(" %d %d", &a, &b);

   printf(" operacio ? (s, r, p, d) \n");
   scanf(" %c", &op);

   switch (op) {
      case 's': 
         pf = suma;        /* o també  pf = &suma;   */
         break;
      
      case 'r': 
         pf = resta;       /* idem */
         break;
      
      case 'p': 
         pf = producte;    /* idem */
         break;
      
      case 'd': 
         pf = divisio;     /* idem */
         break;
      
      default:
         pf = NULL;
   }

   if (pf == NULL)
      printf("caracter d'operacio incorrecte \n");
   
   else
      printf("resultat = %d \n", pf(a, b));
      /* o bé
      printf("resultat = %d \n", (*pf)(a, b)); 
      */
   

   return 0;
}


int suma(int a, int b) {
   return a+b;
}


int resta(int a, int b) {
   return a-b;
}


int producte(int a, int b) {
   return a*b;
}


int divisio(int a, int b) {
   return a/b;
}
