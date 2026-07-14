#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   double x, y;
} punt;

int dist0(const void *prim, const void *seg);

#define N 10

int main(void) {
   punt vect[N];
   int i;

   for (i = 0; i < N; i++) {
      vect[i].x = 5 - 2*i;
      vect[i].y = 0;
   }

   for (i = 0; i < N; i++)
      printf("%3d %13.6e %13.6e\n", i, vect[i].x, vect[i].y);

   qsort(vect, N, sizeof(punt), dist0);

   printf("\n");
   for (i = 0; i < N; i++)
      printf("%3d %13.6e %13.6e\n", i, vect[i].x, vect[i].y);

   return 0;
}

/* la distancia a l'origen ens donara la relació d'ordre */

int dist0(const void *prim, const void *seg) {
   punt *p;
   double d1, d2;
   int valor = 0;

   p = (punt*)prim;
   d1 = (p->x)*(p->x) + (p->y)*(p->y);
   p = (punt*)seg;
   d2 = (p->x)*(p->x) + (p->y)*(p->y);

   if (d1 < d2) 
      valor = -1;
   else  if (d1 > d2) 
      valor = 1;

   return valor;
}
