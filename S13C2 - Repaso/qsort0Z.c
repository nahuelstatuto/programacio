/* qsort0Z.c 
ordenaci� d'un vector d'enters de n components
funci� de comparaci� "habitual" en la bibliografia

es demana n ("petit")
es generen les dades enteres aleat�riament
es fan escriure els vectors inicial i final

dades enteres generades aleat�riament
*/

#include <stdio.h>
#include <stdlib.h>     /* qsort �s aqu� */
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
      printf("error de mem�ria! \n");
      exit(2);
   }
   
   /* generaci� aleat�ria d'un vector d'enters */
   srand(time(NULL));
   for (j=0; j<n; j++) 
      v[j] = rand()%(2*N);

   printf("vector inicial: ");
   for (j=0; j<n; j++)
      printf("%2d ", v[j]);
   printf("\n");


   /* invocaci� de qsort */
   qsort(v, n, sizeof(int), comparar);


   printf("vector final:   ");
   for (j=0; j<n; j++)
      printf("%2d ", v[j]);
   printf("\n");

   free(v);

   return 0;
}

/* funci� on es defineix la relaci� d'ordre, ha de retornar:
   < 0: si l'element apuntat per p �s   m�s petit que   l'element apuntat per q
    0 :                                    igual a
   > 0:         "          "            m�s gran que        "            "
l'expressi� usada aqu� �s la m�s usada en la bibliografia 
*/
int comparar(const void *p, const void *q) 
{
   return *(int *)p-*(int *)q;
}
