/* pftrapezis.c
exemple de funció tal que UN PARÀMETRE ÉS UN PUNTER A FUNCIÓ

la funció implementa el mètode dels trapezis, se li passa:
   la funció a integral (o sigui, un apuntador a funció)
   els dos límits d'integració (dos reals)
   la quantitat de trapezis (un enter positiu)

al "main" es volen calcular (aproximadament) dues integrals 
   cadascuna es fa diverses vegades,
   duplicant cada vegada el nombre de trapezis
*/

#include <stdio.h>
#include <math.h>

/* prototipus (els noms dels paràmetres no caldrien (ni la f) */
double trapezis(double (*f)(double), double a, double b, int n);
double f1(double x);
double f2(double x); 


int main(void) {
   double a, b, res;
   int n, qu, i;


   /* integral de la funció f1 */
   printf("\ninterval [a, b] de la funció f1 ? \n");
   scanf("%le %le", &a, &b);
   
   printf("vegades que es fa trapezis a f1 (duplicant-ne la quantitat) ? \n");
   scanf("%d", &qu);
   if (qu > 30) return 1;   /* es convenient posar un màxim */
   
   printf("\nfuncio f1 \n %s  %6s %16s \n", "i", "n", "T(n)");
   n = 1;
   for (i = 1; i <= qu; i++) {
      res = trapezis(f1, a, b, n);   /* també correcte &f1 */
      printf("%2d %10d   %+23.15le \n", i, n, res);
      
      n = 2*n;
   }


   /* integral de la funció f2 */
   printf("\ninterval [a, b] de la funció f2 ? \n");
   scanf("%le %le", &a, &b);
   
   printf("vegades que es fa trapezis a f2 (duplicant-ne la quantitat) ? \n");
   scanf("%d", &qu);
   if (qu > 30) return 1;   /* es convenient posar un màxim */
   
   printf("\nfuncio f2 \n %s  %6s %16s \n", "i", "n", "T(n)");
   n = 1;
   for (i = 1; i <= qu; i++) {
      res = trapezis(&f2, a, b, n);    /* també correcte f2 */
      printf("%2d %10d   %+23.15le \n", i, n, res);
      
      n = 2*n;
   }

   return 0;
}


/* mètode dels trapezis per a calcular integrals definides */
double trapezis(double (*f)(double), double a, double b, int n) {
   double h, x, sum;
   int i;
   
   h = (b-a)/n;

   sum = ((*f)(a)+(*f)(b))/2;    /* també correcte: sum = (f(a)+f(b))/2; */

   for (i = 1; i < n; i++) {
      x = a + i*h;
      sum += (*f)(x);            /* també correcte: sum += f(x); */
   }
   
   return sum*h;
}

/* funcions que es volen integrar */
double f1(double x)
{
   return exp(-x*x);
}

double f2(double x) 
{
   if (x == 0) return 1;
   else        return sin(x)/x;
}

