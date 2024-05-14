/* metodes-simples.c 
es comparen els temps d'execució de 5 mètodes simples d'ordenació
el temps d'execució de tots ells és proporcional a n*n (aprox.)

vectors d'elements "double", generats aleatòriament a [0,1]
per a cada mètode cal tornar a generar el vector

si n <= 10, s'escriuen els vectors inicials i finals (comprovació)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seleccio(int, double *);
void bombolla(int, double *);
void sacsejada(int, double *);
void insercio_lineal(int, double *);
void insercio_binaria(int, double *);

int main(void)
{
   double *v;
   int n, j;
   clock_t t0, t1;
   float t;
   
   /* dimensió, reserva de memòria, i llavor aleatòria */
   printf("n = ? \n");
   scanf("%d", &n);
   if (n<1) exit(1);
   
   v = (double *)malloc(n*sizeof(double));
   if (v == NULL) exit(1);
   
   srand(time(NULL));
   
   /* selecció */
   printf("seleccio \n");
   for (j=0; j<=n-1; j++) 
      v[j] = 1.*rand()/RAND_MAX;
   if (n <= 10) {
      printf("vector inicial: ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t0 = clock();
   seleccio(n, v);
   t1 = clock();
   
   if (n <= 10) {
      printf("vector  final : ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("temps = %.2f seg \n\n", t);
   
   /* bombolla */
   printf("bombolla \n");
   for (j=0; j<=n-1; j++) 
      v[j] = 1.*rand()/RAND_MAX;
   if (n <= 10) {
      printf("vector inicial: ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t0 = clock();
   bombolla(n, v);
   t1 = clock();
   
   if (n <= 10) {
      printf("vector  final : ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("temps = %.2f seg \n\n", t);

   /* sacsejada */
   printf("sacsejada \n");
   for (j=0; j<=n-1; j++) 
      v[j] = 1.*rand()/RAND_MAX;
   if (n <= 10) {
      printf("vector inicial: ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }

   t0 = clock();
   sacsejada(n, v);
   t1 = clock();
   
   if (n <= 10) {
      printf("vector  final : ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }

   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("temps = %.2f seg \n\n", t);

   /* inserció lineal */
   printf("insercio lineal \n");
   for (j=0; j<=n-1; j++) 
      v[j] = 1.*rand()/RAND_MAX;
   if (n <= 10) {
      printf("vector inicial: ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t0 = clock();
   insercio_lineal(n, v);
   t1 = clock();
   
   if (n <= 10) {
      printf("vector  final : ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("temps = %.2f seg \n\n", t);

   /* inserció binària */
   printf("insercio binaria \n");
   for (j=0; j<=n-1; j++) 
      v[j] = 1.*rand()/RAND_MAX;
   if (n <= 10) {
      printf("vector inicial: ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t0 = clock();
   insercio_binaria(n, v); 
   t1 = clock();
   
   if (n <= 10) {
      printf("vector  final : ");   
      for (j=0; j<=n-1; j++) 
         printf("%5.2f ", v[j]); 
      printf("\n");
   }
   
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("temps = %.2f seg \n\n", t);
  
   /* alliberament de memòria i acabar */
   free(v);
   return 0;
}

void seleccio(int n, double *v)
{
   int j, k, index;
   double aux;

   for (j=0; j<n-1; j++) {
      index = j;
      for (k=j+1; k<n; k++)
         if (v[k] < v[index]) 
            index = k;
      aux = v[j];
      v[j] = v[index];
      v[index] = aux;
   }
   return;
}

void bombolla(int n, double *v)
{
   int j, k;
   double aux;

   for (j=0; j<n-1; j++) 
      for (k=n-1; k>=j+1; k--) 
         if (v[k-1]>v[k]) {
            aux = v[k-1];
            v[k-1] = v[k];
            v[k] = aux;
         }
   return;   
}

void sacsejada(int n, double *v)
{
   int esq, dre, index, k;
   double aux;
   
   esq = 1;
   dre = n-1;
   index = n-1;
   do {
      for (k=dre; k>=esq; k--) {
         if (v[k-1] > v[k]) {
	    aux = v[k-1];
	    v[k-1] = v[k];
	    v[k] = aux;
	    index = k;
	 }
      }
      esq = index+1;
      for (k=esq; k<=dre; k++) {
         if (v[k-1] > v[k]) {
	    aux = v[k-1];
	    v[k-1] = v[k];
	    v[k] = aux;
	    index = k;
	 }
      }
      dre = index-1;
   } while (esq <= dre);
   
   return;
}

void insercio_lineal(int n, double *v)
{
   int j, k;
   double aux;

   for (j=1; j<=n-1; j++) {
      aux = v[j];
      k = j-1;
      while (k >= 0 && aux < v[k]) {
         v[k+1] = v[k];
         k = k-1;
      }
      v[k+1] = aux;
   }
   
   return;
}

void insercio_binaria(int n, double *v)
{
   int j, k, esq, dre;
   double aux;
   
   for (j=1; j<=n-1; j++) {
      aux = v[j];
      esq = 0;
      dre = j-1;
      while (esq <= dre) {
         k = (esq+dre)/2;
         if (aux<v[k])  dre = k-1;
         else           esq = k+1;
      }
      for (k=j-1; k>=esq; k--)   v[k+1] = v[k];
      v[esq] = aux;
   }
   
   return;
}
