/* qsort1Z.c 
s'usa qsort() per a ordenar un vector d'enters segons 
un ordre DIFERENT de l'habitual:

i) qualsevol nombre senar es més petit que qualsevol nombre parell

ii) els nombres senars s'ordenen en ordre decreixent

iii) els nombres parells s'ordenen en ordre creixent

o sigui:
   primer van tots els senars, de major a menor,
   després tots els parells, de menor a major

... < 7 < 5 < 3 < 1 < -1 < -3 < -5 < ... < -8 < -6 < -4 < -2 < 0 < 2 < 4 < 6 < 8 <...

CAL FER UNA FUNCIÓ DE COMPARACIÓ adequada a aquest ordre

No usem memòria dinàmica (longitud màxima = N)
Generació aleatòria del vector d'enters a ordenar, entre -99 i +99
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 20

int comparar(const void *, const void *);

int main(void) {
   
   int v[N], n, j;

   printf("n=? (valor entre 1 i %d) \n", N);
   scanf("%d", &n);
   if (n<1 || n>N) exit(1);

   
   srand(time(NULL));
   for (j=0; j<n; j++) 
      v[j] = -99+rand()%199;

   printf("vector inicial: ");
   for (j=0; j<n; j++)  printf("%2d, ", v[j]);
   printf("\n");
   
   qsort(v, n, sizeof(int), comparar);

   printf("vector final:   ");
   for (j=0; j<n; j++)  printf("%2d, ", v[j]);
   printf("\n");

   return 0;
}

/* una funció de comparació adequada a l'ordre donat */
int comparar(const void *p, const void *q) {

   int l, r;
   
   l = *(int *)p;    /* l és el valor apuntat per p */
   r = *(int *)q;    /* r és el valor apuntat per q */
   
   /* cas que els dos valors siguin senars: ordre decreixent */
   if ( (l%2 != 0) && (r%2 != 0) ) return r-l;
   
   /* cas que els dos valors siguin parells: ordre creixent */
   if ( (l%2 == 0) && (r%2 == 0) ) return l-r;
   
   /* cas que un valor és senar i un valor és parell: és menor el senar */
   if (l%2 == 0)  return 1;
   else           return -1;

}
