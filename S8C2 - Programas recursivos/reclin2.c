/* reclin2.c 
recurrència lineal homogènia de segon ordre a coeficients constants:
      x_n = a x_(n-1) + b x_(n-2)   (a, b: constants fixades)
amb condicions inicials donades: x_0 , x_1      


dades: x_0, x_1 (reals) i n (enter no negatiu)


resultats: x_n, calculat de dues maneres:
   en una funció que fa el càlcul iterativament
   en una funció que fa el càlcul recursivament


es compta el temps d'execució de cada cas
   s'obté que el cas recursiu és molt poc eficient
   (es recomana n = 40, 41, 42, 43,... per a comprovar-ho)


nota 1 (anàlisi de l'algorisme iteratiu):
   la quantitat de càlculs és aproximadament lineal respecte n
   (3n operacions aritmètiques, 3n assignacions)
   per a valors de n tan baixos --> temps insignificant


nota 2 (anàlisi de l'algorisme recursiu):
   el temps d'execució ha de ser aproximadaemnt proporcional
   a la quantitat de vegades que s'invoca efectivament la funció recursiva

   la quantitat d'invocacions de la funció recursiva, en funció de n,
   verifica:
      qu(n) = 1 + qu(n-1) + qu(n-2)
      amb qu(0) = qu(1) = 1
   això es pot resoldre explícitament:
      qu(n) = c1*r1^n + c2*r2^n -1,   |r1|>1, |r2|<1
   asimptòticament: qu(n) ~ r1 qu(n-1)

   el temps d'execució també ha de verificar això


conclusió:
   no és efectiu usar recursivitat per a recurrències de 2on ordre


nota:
   no té cap importància que la recurrència sigui lineal,
   homogènia i a coeficients constants
   per a qualsevol recurrència de 2on ordre passarà una cosa semblant
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define a 1.9
#define b -0.7

double iteracio(double x0, double x1, int n);
double recursio(double x0, double x1, int n);

long int qu = 0;

int main(void) {

   int n;
   double x0, x1, x;
   double arrel, c1, r1, c2, r2, qu_;
   clock_t t0, t1;
   float t;

   printf("n = ? \n");
   scanf("%d",&n);
   x0 = 0.336;
   x1 = 0.7741;

   /*printf("x0, x1, n = ? \n");
   scanf("%le %le %d", &x0, &x1, &n);
   if (n < 0) exit(1);*/

   /* usant la funció iterativa */
   t0 = clock();
   
   x = iteracio(x0, x1, n);
   
   t1 = clock();
   
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   
   printf("iterativament: x_n = %+.8le t = %+.4e \n", x, t );

   
   /* usant la funció recursiva */
   t0 = clock();
   
   x = recursio(x0, x1, n);
   
   t1 = clock();
   
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   
   printf("recursivament: x_n = %+.8le t = %+.4e invocacions: %ld\n", x, t, qu);
   printf("prop = %+.8le\n",(double) qu/t);

   
   /* quantitat d'invocacions de la funció recursiva */
   arrel = sqrt(5.);
   c1 = (arrel+1)/arrel;
   r1 = (1+arrel)/2;
   c2 = (arrel-1)/arrel;
   r2 = (1-arrel)/2;
   qu_ = c1*pow(r1, n) + c2*pow(r2, n) -1;

   printf("n = %d, invocacions funcio recursiva = %.2lf \n", n, qu_);


   return 0;
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
            x = a*x1+b*x0;
            x0 = x1;
            x1 = x;
         }
         return x;
      }

}


double recursio(double x0, double x1, int n) {

   qu=qu+1;

   if (n == 0)
      return x0;
   else if (n == 1)
      return x1;
      else
         return a*recursio(x0, x1, n-1)+b*recursio(x0, x1, n-2);
}

