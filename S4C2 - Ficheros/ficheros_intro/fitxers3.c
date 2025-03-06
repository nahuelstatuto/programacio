/* fitxers3.c
(és un exercici dels apunts del departament)
trobar la longitud de la línia més llarga d'un fitxer

- es llegeix caràcter a caràcter mitjançant la funció getc:
      int getc( FILE *stream )

- llegeix el següent caràcter del fitxer apuntat per "stream"
- avança l'indicador de posició dins del fitxer
- retorna el caràcter llegit (passat a tipus "int"),
   o bé EOF (si no ha pogut llegir)

com que es llegeix caràcter a caràcter,
per a separar les línies cal usar que el final de línia és '\n'
*/

#include <stdio.h>
#include <stdlib.h>        /* exit */

int main(void) {

   int l, lmax, k;
   char nom[31], c;
   FILE *dades;
   
   /* dades */
   printf("fitxer de dades ? (maxim 30 caracters) \n");
   scanf("%s", nom);

   dades = fopen(nom, "r");
   if (dades == NULL) { 
      printf("no s'obre el fitxer %s \n", nom); 
      exit(1);
   }
   
   /* inicialitzacions */
   k = 1;                  /* línia */
   l = 0;                  /* longitud */
   lmax = 0;               /* longitud màxima */
   
   c = getc(dades);        /* lectura del primer caràcter */

   while (c != EOF) {      /* EOF = final de fitxer, 
                              en moltes configuracions, -1 va bé */
      if (c != '\n') {     /* '\n' vol dir "final de línia" */
         l = l+1;          /* no som a final de línia -> incrementem la longitud */
      
      } else {             /* s'ha acabat una línia */   
         printf("seguiment: linia k = %d longitud l = %d \n", k, l);
         if (l > lmax) 
            lmax = l;
         l = 0;
         k = k+1;
      
      }
         
      c = getc(dades);     /* lectura del següent caràcter */
   }

   printf("longitud maxima: lmax = %d \n", lmax);

   fclose(dades); 

   return 0;
} 
