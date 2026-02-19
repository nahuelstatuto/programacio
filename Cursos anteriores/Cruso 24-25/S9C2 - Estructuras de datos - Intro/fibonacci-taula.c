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

typedef long int tauFib[N];   // "tauFib" és un tipus nou:
                              // vector de tipus "long int" de N components

typedef struct {
   tauFib t;
   int n;
} taula;                // "taula" és un tipus nou, de dos camps:
                        // un, de nom t, és de tipus "tauFib"
                        // l'altre, de nom n, és de tipus "int"
                        // i contindrà la longitud real de la successió t

void escriureFib( taula );    // funció per a escriure 
//void escriureFib_( tauFib, int );    // funció per a escriure 
                              // una variable de tipus "taula" 

int main (void) 
{
   taula fib;           // fib és una variable de tipus "taula"
   int i, j;
   
   // assignació dels dos elements inicials i de la longitud real
   fib.t[0] = 0;
   fib.t[1] = 1;
   fib.n = 2;

   // càlcul de la resta d'elements, usant la recurrència de Fibonacci
   // i actualització de la longitud real
   while (fib.n < N ) {
      fib.t[fib.n] = fib.t[fib.n-1] + fib.t[fib.n-2];
      ++(fib.n);
   }
   
   // escriptura de la successió generada
   printf( "Nombres de Fibonacci\n" );
   escriureFib(fib);
   
   // eliminació dels elements de la successió que són múltiples de 7:
   // quan se'n troba un,
   //    es mouen tots els de la seva dreta una posició cap a l'esquerra,
   //    s'actualitza la longitud real de la successió
   for (i = 0; i < fib.n; ++i) {
      if (fib.t[i] % 7 == 0) {
         for (j = i + 1; j < fib.n; ++j) {
            fib.t[j-1] = fib.t[j];
         }
         --(fib.n);
      }
   }
   
   // escriptura de la successió resultant
   printf( "Nombres de Fibonacci sense multiples de 7\n" );
   escriureFib(fib);

   return 0;
}

void escriureFib(taula f) 
{
   int i;

   for (i = 0; i < f.n; ++i) {
      printf( " %ld" , f.t[i]);
   }
   printf( "\n" );
   
   return;
}
