/* quicksort.c 
implementació del mètode d'ordenació quicksort 
basat en la versió de:
Vancells,J. & López, E.. Programació: Introducció a l'algorísmica

Característiques:
- n  dades aleatòries de tipus  float , a [0,1]
- usant memòria dinàmica
- comptant el temps d'execució de la part d'ordenació
- comprovant que funciona (escrivint vectors inicial i final quan  n <= N)
- el pivot d'un subvector qualsevol és el seu primer element
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void recursiva(float *v, int inici, int final);
int particio(float *v, int esquerra, int dreta);

int main(void)
{
   float *v, t;
   int n, j;
   clock_t t0, t1;

   /* quantitat d'elements i memòria dinàmica */
   /*printf("n = ? \n");
   scanf("%d", &n);
   if (n<1) exit(1);
   */
   n=5;

   v = (float *) malloc(n*sizeof(float));
   if (v == NULL) {  
      printf("error al malloc! \n");  
      exit(2); 
   }

   /* generació aleatòria dels elements a ordenar */
   srand(time(NULL));
   for (j=0; j<n; j++)
      v[j] = (float)rand()/RAND_MAX;            /* a [0, 1] */

   v[0]=3.;
   v[1]=5.;
   v[2]=9.;
   v[3]=1.;
   v[4]=7.;
   
   /* escriptura de comprovació */
   if (n <= N) { 
      printf("vector inicial: ");
      for (j=0; j<n; j++)
         /*printf("%.2f ", v[j]);*/
         printf("%d ", (int) v[j]);
      printf("\n\n");
   }


   /* mètode, temps i escriptura */ 
   t0 = clock();
   recursiva(v, 0, n-1);
   t1 = clock();
   
   t = (float)(t1-t0)/CLOCKS_PER_SEC;
   printf("\nn=%d, temps= %.3f \n", n, t);


   /* escriptura de comprovació */
   if (n <= N) { 
      printf("vector final:   ");
      for (j=0; j<n; j++)  
         /*printf("%.2f ", v[j]);*/
         printf("%d ", (int) v[j]);
      printf("\n");
   }

   /* alliberament de la memòria */
   free(v);

   return 0;
}


/* funció que ordena (recursivament)
   el subvector entre els índexs: inici i final */
void recursiva(float *v, int inici, int final)
{
   int posiciopivot, j;
   
   /* condició per a parar la recursivitat: 
      quan hi ha un sol element (inici=final) -> no es fa res */
   if (inici < final) {
      
      /* es fa la partició respecte al pivot = primer element */
      posiciopivot = particio(v, inici, final);
      printf("Vector parcialment ordenat:\n");
      for (j=inici; j<final+1; j++)
         /*printf("%.2f ", v[j]);*/
         printf("%d ", (int) v[j]);
      printf("\n");

/*
   printf("ini=%d, fin=%d, pospiv=%d\n", inici, final, posiciopivot);
*/

      /* cal ordenar (recursivament) els dos subvectors separats pel pivot */
      recursiva(v, inici, posiciopivot-1);	        
      recursiva(v, posiciopivot+1, final);
   }

   return;
}


/* "partició": reordenació dels elements entorn del pivot triat
   a la sortida:
      - l'element pivot és al seu lloc definitiu
      - tots els de la seva esquerra són més petit o iguals que ell
      - tots els de la seva dreta són més grans que ell
   es retorna l'índex del pivot
*/
int particio(float *v, int esquerra, int dreta)
{
   int ipivot, limitdreta, j;
   float aux;

   printf("Dintre de particio amb esquerra:%d, dreta: %d\n",esquerra,dreta);
	
   ipivot = esquerra;
   limitdreta = dreta;
   dreta = dreta+1;

   do {
      /* es busca, des de l'esquerra i augmentnat l'índex,
                  el primer element major que el pivot */
      do {
         esquerra = esquerra+1;
      } while (v[esquerra] <= v[ipivot] && esquerra < limitdreta);
      
      /* es busca, des de la dreta i disminuint l'índex,
                  el primer element menor o igual que el pivot */
      do {
         dreta = dreta-1;
      } while (v[dreta] > v[ipivot]);
   
      /* si no s'han creuat els dos índexs trobats, 
         s'intercavien els continguts
         i es continua buscant més índexs similars */
      printf("\nesq=%d,\t v[esq]=%d\ndret=%d,\t v[dret]=%d\n", esquerra, (int) v[esquerra], dreta, (int) v[dreta]);
      if (esquerra < dreta) {
         printf("Fem v[esq] <--> v[dreta]\n");
         aux = v[esquerra];
         v[esquerra] = v[dreta];
         v[dreta] = aux;
      }
      /* escriptura de comprovació */
      for (j=0; j<limitdreta+1; j++)
         /*printf("%.2f ", v[j]);*/
         printf("%d ", (int) v[j]);
      printf("\n");
   } while (esquerra < dreta);

   /* s'arriba aquí quan els índexs "esquerra" i "dreta" s'han creuat
      es posa el pivot al seu lloc intercanviant-lo amb v[dreta] */
   printf("\nipivot=%d,\t v[nipivot]=%d\ndret=%d,\t v[dret]=%d\n", ipivot, (int) v[ipivot], dreta, (int) v[dreta]);
   printf("Fem v[ipivot] <--> v[dreta]\n\n");
   aux = v[ipivot];             
   v[ipivot] = v[dreta];	      
   v[dreta] = aux;              

   /* es retorna la posició del pivot */
   return dreta;
}
