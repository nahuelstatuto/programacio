/* rec1.c 
   
recurrència de primer ordre del tipus:
   x_0 donat
   per a n >= 0:  x_(n+1) = f(x_n), amb f:R --> R  coneguda

problema:   donats f, x0 i n
            calcular x_n


de dos maneres: funció no recursiva (iterativa) i 
                funció recursiva


es compten els temps d'execució
(per tal que siguin significatius, es fa una f(x) costosa)


conclusió:  per a recurrències de 1er ordre,
            els 2 temps d'execució es comporten linealment respecte n
            --> l'eficiència dels dos casos és similar
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* exemple concret de funció f(x): envia [0,1] en [0,1] 
   s'inicialitza M a un valor gran
   per tal que el temps d'executar-se f(x) sigui significatiu */
double f(double x) {

   int M= 1000, i;

   for (i=0; i<M; i++)
      x = 4*x*(1-x);
   
   return x;
}


double iterativa(double x0, int n);
double recursiva(double x0, int n);


int main(void) {
   
   int n;
   double x0, x;
   clock_t t0, t1;
   float t;

   printf("x0 = ? (entre 0 i 1), n = ? (no negatiu) \n");
   scanf("%le %d", &x0, &n);
   if (x0 < 0 || x0 > 1 || n < 0)   return 1;

   /* algorisme iteratiu */
   t0 = clock();
   x = iterativa(x0, n);
   t1 = clock();
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("iterativament: x_n = %+.8le temps = %.3f \n", x, t);

   /* algorisme recursiu */
   t0 = clock();
   x = recursiva(x0, n);
   t1 = clock();
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("recursivament: x_n = %+.8le temps = %.3f \n", x, t);


   return 0;
}


/* funció no recursiva (algorisme iteratiu) */
double iterativa(double x, int n) {

   int i;
   
   for (i=0; i<n; i++)
      x = f(x);
   
   return x;
}


/* funció recursiva */
double recursiva(double x0, int n) {

   double aux;

   if (n == 0)
      return x0;
   else {
      aux = recursiva(x0, n-1);
      return f(aux);
   }
}

