/* qsort0Z.c 
ordenació d'un vector d'enters de n components
funció de comparació "habitual" en la bibliografia

es demana n ("petit")
es generen les dades enteres aleatòriament
es fan escriure els vectors inicial i final

dades enteres generades aleatòriament
*/

#include <stdio.h>
#include <stdlib.h>     /* qsort és aquí */
#include <time.h>       /* time */

#define N 100

int comparar(const void *, const void *);

int main(void) 
{
   int *v, n, j;

   printf("n = ? (no passar de %d) \n", N);
   scanf("%d", &n);
   if (n<1 || n>N) exit(1);

   v = (int *) malloc(n*sizeof(int));
   if (v == NULL) {
      printf("error de memòria! \n");
      exit(2);
   }
   
   /* generació aleatòria d'un vector d'enters */
   srand(time(NULL));
   for (j=0; j<n; j++) 
      v[j] = rand()%(2*N);

   printf("vector inicial: ");
   for (j=0; j<n; j++)
      printf("%2d ", v[j]);
   printf("\n");


   /* invocació de qsort */
   qsort(v, n, sizeof(int), comparar);


   printf("vector final:   ");
   for (j=0; j<n; j++)
      printf("%2d ", v[j]);
   printf("\n");

   free(v);

   return 0;
}

/* funció on es defineix la relació d'ordre, ha de retornar:
   < 0: si l'element apuntat per p és   més petit que   l'element apuntat per q
    0 :                                    igual a
   > 0:         "          "            més gran que        "            "
l'expressió usada aquí és la més usada en la bibliografia 
*/
int comparar(const void *p, const void *q) 
{
   return *(int *)p-*(int *)q;
}
