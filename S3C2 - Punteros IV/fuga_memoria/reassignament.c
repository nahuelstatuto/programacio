/* reassignament.c

fuga de memòria pel reassignament d'un punter
(sense haver fet "free" entre una assignació i la següent)

es genera k vegades un vector de n components (aleatòries a [0, 1])
per a cadascuna de les vegades es calcula la mitjana

resultats:
- execució sense valgrind --> tot sembla correcte
- execució amb valgrind --> ens adonem que falten free's
*/

#include <stdio.h>     
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int k, j, n, i;
   double *a, mitjana; 
  
   printf("k = ? (vegades) \n");
   scanf("%d", &k);

   printf("n = ? (dimensio) \n");
   scanf("%d", &n);
   
   if (k<1 || n<1) return 1;


   srand( time(NULL) );
   for (j=0; j<k; j++) {
      a = (double *)malloc (n*sizeof(double)); /* j>0 -> reassignació */
      if (a == NULL) exit(1);
      
      for (i=0; i<n; i++) 
         a[i] = ( (double)rand() )/RAND_MAX;
      
      /* es calcula la mitjana dels elements generats i s'escriu */
      mitjana = 0;
      for (i=0; i<n; i++) mitjana = mitjana+a[i];
      mitjana = mitjana/n;
      printf("mitjana = %+le \n", mitjana);

   }
   
   free(a);       /*  */

   return 0;
}

