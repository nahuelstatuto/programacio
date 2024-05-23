/* qsort3S.c 
s'usa qsort() de C per a ORDENAR UN VECTOR D'ESTRUCTURES
de fet, es fa de dues maneres diferents:
   primer: segons un camp, de tipus int
   després: segons un altre camp, de tipus float

nota: el tipus estructurat podria tenir molts més camps
      no en té més perquè això és irrellevant per a les ordenacions
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int niub;
   float nota;
} alumne;


/* dues funcions de comparació, una per cada camp */
int comp_niub(const void *, const void *);
int comp_nota(const void *, const void *);


int main(void) 
{
   int n, j;
   alumne *v;
   
   /* quantitat d'elements */
   scanf("%d", &n);
   if (n<1) exit(1);

   v = (alumne *) malloc(n*sizeof(alumne));
   if (v == NULL) {
      printf("error de memòria! \n"); 
      exit(2); 
   }
   
   /* lectura de dades */
   for (j=0; j<n; j++) { 
      scanf("%d", &v[j].niub);
      scanf("%f", &v[j].nota);
   }
   
   printf("llista inicial llegida: \n");
   printf("     niub     nota \n");
   for (j=0; j<n; j++)
      printf("%10d %6.1f \n", v[j].niub, v[j].nota);
   printf("\n");


   /* ordenació segons el camp "niub" */
   qsort(v, n, sizeof(alumne), comp_niub);

   printf("llista ordenada per niub: \n");
   printf("     niub     nota \n");
   for (j=0; j<n; j++)
      printf("%10d %6.1f \n", v[j].niub, v[j].nota);
   printf("\n");


   /* ordenació segons el camp "nota" */
   qsort(v, n, sizeof(alumne), comp_nota);
   
   printf("llista ordenada per nota: \n");
   printf("     niub     nota \n");
   for (j=0; j<n; j++)
      printf("%10d %6.1f \n", v[j].niub, v[j].nota);
   printf("\n");

   free(v);

   return 0;
}


/* funció de comparació segons el camp "niub", de tipus "int"
primer cal passar de (punter a "void") a (punter al tipus "alumne")
després cal accedir als valors dels camps
(hi ha dues maneres de fer-ho: usant   ->    o usant      * i . )
*/

/*
int comp_niub(const void *p, const void *q) 
{
   return ((alumne *)p)->niub - (*(alumne *)q).niub;
}
*/

int comp_niub(const void *p, const void *q) 
{
   int esq, dre;
   esq = ((alumne *)p)->niub;
   dre = ((alumne *)q)->niub;
   
   return esq-dre;
}


/* funció de comparació segons el camp "nota", de tipus "float"
la funció de comparació ha de retornar un "int"
*/
int comp_nota(const void *p, const void *q) 
{
   alumne l, r;
   float d;
   
   l = *(alumne *)p;
   r = *(alumne *)q;
   d = l.nota - r.nota;
   if (d<0 )      return -1;
   else
      if (d>0)    return 1;
      else        return 0;
}
