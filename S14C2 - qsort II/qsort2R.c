/* qsort2R.c 
ús de qsort() per a comparar un vector d'elements "double"
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(const void *, const void *);

int main(void) 
{
   double *v;
   int n, j;

   printf("n = ? \n");
   scanf("%d", &n);
   if (n<1) exit(1);

   v = (double *) malloc(n*sizeof(double));
   if (v == NULL) {  printf("error de memòria! \n");  exit(2); }

   srand(time(NULL));
   for (j=0; j<n; j++) 
      v[j] = (double)rand()/RAND_MAX;

   printf("vector inicial: ");
   for (j=0; j<n; j++)  printf("%.3lf ", v[j]);
   printf("\n");
   
   /* invocació de qsort */
   qsort(v, n, sizeof(double), comp);

   printf("vector final:   ");
   for (j=0; j<n; j++)  printf("%.3lf ", v[j]);
   printf("\n");

   free(v);

   return 0;
}

/* una funció de comparació de valors "double"
atenció: s'ha de retornar necessàriament un enter
*/
int comp(const void *prim, const void *seg) 
{
   double *p, *q;
   int valor;
   
   /* passem els (punters a void) a (punters a double) */
   p = (double *)prim;
   q = (double *)seg;
   
   /* ara comparem els valors apuntats pels punters i
      omplim una variable entera amb un valor adequat a cada cas
   */
   valor = 0;
   if (*p < *q)      valor = -1;
   else if (*p > *q) valor = +1;

   return valor;
}
