/* fibonacci-taula.c
Exemple on es treballa amb:
   tipus estrucutra que conté un camps que és un vector (de longitud fixa)
   assignació de varibles estructura
   (no es poden assignar vectors, però sí estructures)
---------------------------------------------------------

Es calculen N termes de la successió de Fibonacci
   x(n) = x(n-1) + x(n-2)
començant a x(0) = 0, x(1) = 1,
guardant-los en una variable d'un tipus estructurat especial

Es fan escriure

Després s'eliminen els elements que són múltiples de 7

Es fan escriure els que queden
*/

#include<stdio.h>
#include<stdlib.h>

#define N 20

typedef long int *tauFib;   // "tauFib" és un tipus nou:
                              // vector de tipus "long int" de N components

typedef struct {
   long int *t;
   int n;
} taula;               

void escriureFib( taula );   
void recur( *taula );   //usando tauFib[20]
void recur( *taula, k );   // memoria dinamica

int main (void) 
{
   taula fib;           // fib és una variable de tipus "taula"
   tauFib a;
   int i, j, k;

   scanf("%d",&k);

   fib.t = (long int *)malloc(k*sizeof(long int));
   a = (tauFib *)malloc(k*sizeof(tauFib));
   //comp

   // assignació dels dos elements inicials i de la longitud real
   fib.t[0] = 0;
   fib.t[1] = 1;
   fib.n = 2;
   while (fib.n < k ) {
      fib.t[fib.n] = fib.t[fib.n-1] + fib.t[fib.n-2];
      ++(fib.n);
   }
   printf( "Nombres de Fibonacci\n" );
   escriureFib(fib);
   for (i = 0; i < fib.n; ++i) {
      if (fib.t[i] % 7 == 0) {
         for (j = i + 1; j < fib.n; ++j) {
            fib.t[j-1] = fib.t[j];
         }
         --(fib.n);
      }
   }   
   printf( "Nombres de Fibonacci sense multiples de 7\n" );
   escriureFib(fib);
   free(fib.t);
   return 0;
}
void escriureFib(taula f) 
{  int i;
   for (i = 0; i < f.n; ++i) {
      printf( " %ld" , f.t[i]);
   }
   printf( "\n" );
   
   return;
}
