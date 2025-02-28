/* m.c 
assignaci� din�mica de mem�ria per a calcular la mitjana d'una s�rie de
nombres reals
*/
#include <stdio.h>
#include <stdlib.h>

float func1(int, float *);   /* es poden posar noms, per� no cal */

int main(void) {
   int n, i;
   float *v, value;

   scanf("%d", &n);
   if (n<1) return 1;

   v = (float *)malloc(n*sizeof(float));
   if (v==NULL) {
      printf("problemes de mem�ria\n");
      return 1;
   }
   
   for (i=0; i<n; i++) 
      scanf("%f", &v[i]);     /* &(*(v+i)) tamb� va b� */;
   
   value = func1(n, v);
   printf(" value = %f \n", value);
   
   free(v);

   return 0;
}

float func1(int m, float *a) {
   float s = 0.;
   int i;

   for (i=0; i<m; i++) 
      s += a[i];           /*  *(a+i) tamb� va b� */
   s = s/m;

   return s;
}
