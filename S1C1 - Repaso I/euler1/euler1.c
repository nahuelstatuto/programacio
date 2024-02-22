/* euler1.c

mètode d'Euler per a integrar:   y' = f(x, y), x de [a, b]
                                 y(a) = ya

   y <--- y + h f(x, y)
   x <--- x+h

es coneix la solució exacta s(x)

es defineixen les constants a, b, ya 
              i les funcions s(x) i f(x, y)

es practica: redirigir la sortida amb >
            i pintar punts de fitxers amb gnuplot

a més, cal notar que l'error del mètode aproximat es comporta com O(h) o O(1/n)
o sigui, si és duplica n, l'error é divideix per 2 (aproximadaemnt)
         si n es multiplica per 10, l'error es divideix per 10 (aproximadament)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* dades de y'=y^2+2x-x^4 a [0, 1], y(0)=0, solució s(x)=x^2 */

#define a 0.
#define ya 0.
#define b 1.

double s(double x) {
   return x*x;
}

double f(double x, double y) {
   return y*y+2*x-x*x*x*x;
}


/* dades de y'=-y+x^3-4x+3 a [0, 3], y(0)=1, solució s(x)=1+x(x-1)(x-2) */
/*
#define a 0.
#define ya 1.
#define b 3.

double s(double x) {
   return 1+x*(x-1)*(x-2);
}

double f(double x, double y) {
   return -y+x*x*x-4*x+3;
}
*/

int main(void) {

   int n, k;
   double x, y, h, err, errmax;
   char nom[31];

   /* càlculs i resultats en un fitxer */
   printf("fitxer de resultats ? (maxim 30 caracters) \n");
   scanf("%s", nom);

   /* ------- fitxers -------*/ 
   FILE *pf;
   pf = fopen(nom, "w");
      if (pf == NULL) { 
         printf("problemes en obrir el fitxer \n");
         exit(1);
      }
   /* ------- fitxers -------*/ 
   
   printf("# n = ? \n");
   scanf(" %d", &n);
   if (n < 1) return 1;

   h = (b-a)/n;         /* pas d'integració */

   /* generació de valors de la solució aproximada i 
      càlcul de l'error màxim 
      (es fan escriure les ternes: x, y, error)
      */
   x = a;
   y = ya;
   errmax = 0.;
   fprintf(pf," %+.8le %+.8le %.4le \n", x, y, 0.); 
   for (k=0; k<n; k++) {
      y = y+h*f(x, y);
      x = x+h;
      err = fabs(y-s(x));
      fprintf(pf," %+.8le %+.8le %.4le \n", x, y, err); 
      if (err > errmax)
         errmax = err;
   }

   printf("# n = %d, errmax = %le \n", n, errmax);
   fclose(pf);
   return 0;
}

/*gnuplot> set key left top
  gnuplot> plot 'euler50.dat' u 1:2 pt 7 ps 0.5, 'euler200.dat' u 1:2 pt 7 ps 0.5, 'euler500.dat' u 1:2 pt 7 ps 0.5*/

