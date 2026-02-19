/* rec2.c 

recurrència de segon ordre (no lineal):
      x_0, x_1 coneguts
      per a n >= 2, x_n = f(x_(n-1), x_(n-2), n)
(f és una funció coneguda fixada)

- es llegeixen x_0, x_1 i n (verificant unes condicions)
   es calcula i escriu x_n
   de dues maneres:
      en una funció recursiva
      en una funció no recursiva (sinó iterativa)

- es compten els temps d'execució

- es compta la quantitat total de vegades que s'entra a la funció recursiva
(usant una variable global, cosa POC RECOMANABLE)
per a comprovar que és aproximadament proporcional al temps d'execució

es pot veure que aquesta quantitat coincideix amb la calculable teòricament
   qu(0) = qu(1) = 1
   qu(n) = 1 + qu(n-1) + qu(n-2)

   notant s = sqrt(5), és qu(n)  =  (s+1)/s * ( (1+s)/2 )**n + 
                                    (s-1)/s * ( (1-s)/2 )**n - 1
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long int qu = 0;

/* funció que defineix la recurrència de segon ordre */
double f(double y1, double y2, int n) {
   return 0.3+0.5*y1*(1.-y2)+0.2/n;
}


double recursio(double x0, double x1, int n);
double iteracio(double x0, double x1, int n);


int main(void) {

   int n;
   double x0, x1, x;
   double arrel, c1, r1, c2, r2, q;
   clock_t t0, t1;
   float t;

   printf("x0, x1, n = ? \n");
   scanf("%le %le %d", &x0, &x1, &n);
   if (n < 0 || x0 < 0 || x0 > 1 || x1 < 0 || x1 > 1)    exit(1);


   /* quantitat teòrica d'invocacions de la funció recursiva */
   arrel = sqrt(5.);
   c1 = (arrel+1)/arrel;
   r1 = (1+arrel)/2;
   c2 = (arrel-1)/arrel;
   r2 = (1-arrel)/2;
   q = c1*pow(r1, n) + c2*pow(r2, n) -1;

   printf("n = %d  \n", n);
   printf("\ninvocacions teòriques de la funcio recursiva = %.2lf \n", q);


   /* càlcul usant la funció recursiva */
   t0 = clock();
   x = recursio(x0, x1, n);
   t1 = clock();
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("\nrecursivament dona x_n = %+.8le temps = %+.2f \n", x, t);
   printf("\ninvocacions efectives de la funcio recursiva = %.ld \n", qu);


   /* càlcul usant la funció iterativa */
   t0 = clock();
   x = iteracio(x0, x1, n);
   t1 = clock();
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("\niterativament dona x_n = %+.8le temps = %+.2f \n\n", x, t);

   return 0;
}


double recursio(double x0, double x1, int n) {

   double y1, y2;

   qu = qu+1;

   if (n == 0)
      return x0;
   
   else if (n == 1)
      return x1;
   
   else {
      y1=recursio(x0, x1, n-1);
      y2=recursio(x0, x1, n-2);
      return f(y1, y2, n);
   }

}


double iteracio(double x0, double x1, int n) {

   int i;
   double x;

   if (n == 0)
      return x0;
   
   else if (n == 1)
      return x1;
   
   else {
      for (i=2; i<=n; i++) {
         x = f(x1, x0, i);
         x0 = x1;
         x1 = x;
      }
      return x;
   }

}

