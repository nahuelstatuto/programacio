/* llista1.c 
es té una llista amb 2 elements com a m�nim

es canviar d'ordre els 2 primers
(només es pot usar un punter auxiliar  p
i només es poden reassignar punters)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
      int ordre;
      struct nodo *next;
}element;

int main(void)
{
   element a,*inici,*p;
   int n;
   printf("%u\n", sizeof(element));
   printf("%u\n", sizeof(a.ordre));
   printf("%u\n", sizeof(a.next));
   printf("quantitat d'elements de la llista ? \n");
   scanf("%d", &n);
   if (n<2) exit(1);
   inici = NULL;
   while (n>0) {
      p = (element *)malloc(sizeof(element));
      p->ordre = n;
      p->next = inici;
      inici = p;
      n = n-1;
   }   
   printf("Llista original: \n");
   p = inici;
   while (p != NULL) {
      printf(" %3d ", p->ordre);
      p = p->next;
   }
   printf("\n");

   
   p = inici;
   inici = p->next;
   p->next = inici->next;
   inici->next = p;
   
   /* escrivim la llista final */
   printf("Llista final: \n");
   p = inici;
   while (p != NULL) {
      printf(" %3d ", p->ordre);
      p = p->next;
   }
   printf("\n");

   /* allibament de mem�ria */
   while (inici != NULL) {
      p = inici;
      inici = p->next;
      free(p);
   }
   
   return 0;
}

