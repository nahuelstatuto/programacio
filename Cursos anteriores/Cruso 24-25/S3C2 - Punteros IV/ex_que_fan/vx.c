/* vx.c
producte escalar de dos vectors
usant memòria dinàmica
(el càlcul es fa en una funció, però no caldria)
FIXEU-VOS EN LES DIVERSES "ORTOGRAFIES"
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
   
double pe(int n, double [], double *);

int main(void) {
   int n=3, i;
   double *u, *v, res;
   u = (double *)malloc(n*sizeof(double));
   v = (double *)malloc(n*sizeof(double));
   if (u==NULL || v==NULL) return 1;

   printf(" primer vector = ?\n");
   for (i=0; i<n; i=i+1)
      scanf("%le", &u[i]);
   
   printf(" segon vector = ?\n");
   for (i=0; i<n; i=i+1)
      scanf("%le", v+i);

   res = pe(n, u, v);
   printf("u·v = %f\n", res);

   return 0;
}
   
double pe(int n, double *u, double v[]) {
   int i;
   double s = 0.;
   
   for (i=0; i<n; i++) s = s+u[i]**(v+i);
   
   return s;
}
