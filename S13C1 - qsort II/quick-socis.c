#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
   char nom[21];
   char cognom1[41];
   char cognom2[41];
   int dni;
} persona;

int cmpNoms(const void *prim, const void *seg);
int cmpDni(const void *prim, const void *seg);

#define N 10

int main(void) {
   persona elem, *ap, **aq, vec[N], *pOrdNom[N], *pDni[N];
   int i;

   FILE *pfl;
   pfl = fopen("socis.txt", "r");
   if (pfl == NULL) {
      printf("Error obertura fitxer origen \n");
      return 1;
   }

   for (i=0; i<N; i++) {
      fscanf(pfl,"%s %s %s %d", vec[i].nom, vec[i].cognom1, 
            vec[i].cognom2, &vec[i].dni);

      pOrdNom[i] = vec+i;
      pDni[i] = vec+i;
   }

   fclose(pfl);

   for (i=0; i<N; i++)
      printf("%3d %-10s %-20s %-20s %8d\n", i, pOrdNom[i]->nom, 
               pOrdNom[i]->cognom1, pOrdNom[i]->cognom2, 
               pOrdNom[i]->dni);

   qsort(pOrdNom, N, sizeof(persona*), cmpNoms);

   puts("\nOrdenats per Cognom");
   for (i=0; i<N; i++)
      printf("%3d %-10s %-20s %-20s %8d\n", i, pOrdNom[i]->nom, 
               pOrdNom[i]->cognom1, pOrdNom[i]->cognom2,
               pOrdNom[i]->dni);

   qsort(pDni, N, sizeof(persona*), cmpDni);

   puts("\nOrdenats per DNI");
   for (i=0; i<N; i++)
      printf("%3d %-10s %-20s %-20s %d\n", i, pDni[i]->nom,
               pDni[i]->cognom1, pDni[i]->cognom2, pDni[i]->dni);

   /*elem.nom[0]= '\0';
   elem.cognom1[0] ='\0';
   elem.cognom2[0] = '\0';
   elem.dni = 4444;
   ap = &elem;
   aq = (persona**)bsearch(&ap, pDni, N, sizeof(persona*), cmpDni);

   if (aq == NULL) {
       puts("l'element no es a la llista");
   } else {
       printf("l'element es %s %s %s\n", (*aq)->nom, (*aq)->cognom1,
               (*aq)->cognom2);
   }*/

   return 0;
}

int cmpNoms(const void *prim, const void *seg) {
   persona *p1,*p2;
   int val;

   p1 = *(persona**)prim;
   p2 = *(persona**)seg;
   
   val = strcmp(p1->cognom1, p2->cognom1);
   if (val != 0) return val;
   val = strcmp(p1->cognom2, p2->cognom2);
   if (val != 0) return val;
   val = strcmp(p1->nom, p2->nom);
   return val;
}

int cmpDni(const void *prim, const void *seg) {
   persona *p1,*p2;
   p1 = *(persona**)prim;
   p2 = *(persona**)seg;
   
   return p1->dni - p2->dni;
}