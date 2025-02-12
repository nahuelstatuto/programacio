/* cerca.c 
cerca lineal i cerca binària en un vector ordenat aleatori
amb tots els elements diferents

el vector és d'enters, per a assegurar les comparacions

es compta el temps en cada cas
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main(void)
{
   int n, j, k, p, marca;
   int *v, elem;
   clock_t t0, t1;
   float t;
   	
   /* dimensió, reserva de memòria i generació aleatòria de dades */
   printf("n = ? \n");
   scanf("%d", &n);
   if (n < 1) return 0;
   
   v = (int *) malloc(n*sizeof(int));
   if (v == NULL) exit(1);
   
   srand(time(NULL));
   v[0] = rand()%2;
   for (j=1; j<n; j++)
      v[j] = v[j-1]+1+rand()%2;        /* es compleix v[j] > v[j-1] */
   
   /* control: quan n es petit, escriptura del vector */
   if (n <= 10) {
      for (j=0; j<n; j++) 
         printf("%d ", v[j]);
      printf("\n");
   }

   printf("v( 0 ) = %d \n", v[0]);
   printf("v(n-1) = %d \n", v[n-1]);
   printf("quin element es vol cercar ? \n");
   scanf("%d", &elem);

   /* cerca lineal */
   t0 = clock();
   
   j = 0;
   while (v[j] < elem && j < n-1) 
      j = j+1;
   printf("lineal : ");
   if (v[j] == elem) printf("   trobat a la posicio = %d ", j);
   else              printf("   no s'ha trobat             ");
   
   t1 = clock();
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("temps = %f seg \n", t);

   /* cerca binària o dicotòmica */
   t0 = clock();
   
   j = 0;
   k = n-1;
   marca = 0;
   while (j <= k && marca == 0) {
      p = (j+k)/2;
      if (v[p] == elem) marca = 1;
      else {
         if (v[p] > elem)  k = p-1;
         else              j = p+1;
      }
   }
   printf("binaria: ");
   if (marca == 1)   printf("   trobat a la posicio = %d ", p);
   else              printf("   no s'ha trobat             ");
   
   t1 = clock();
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("temps = %f seg \n", t);
   
   /* alliberament de memòria i acabament */
   free(v);
   return 0;
}
