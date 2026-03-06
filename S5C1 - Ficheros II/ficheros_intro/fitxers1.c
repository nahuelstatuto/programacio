/* fitxers1.c

Exemple de:
   - lectura de dades d'un fitxer DE NOM FIXAT
   - escriptura de resultats en un fitxer DE NOM FIXAT
(és més normal llegir els noms dels fitxers d'informació)


Aplicació concreta:
   - es llegeixen valors enters del fitxer "f1.dad" 
      (quantitat indeterminada, fins a EOF = "final de fitxer")
   - es calcula:
      quantitat de valors 
      valor màxim 
      mitjana
   - escriptura dels 3 valors anteriors en "f1.res"


Explicació de la funció de lectura: 
   - s'usa la funció de "stdio.h"
            int fscanf(FILE *stream, ...)
   - es llegeix del fitxer apuntat pel punter "stream"
   - els ... indiquen formats i variables que es llegeixen (com per a "scanf")
   - retorna el nombre de variables llegides
     si no hi ha dades, retorna la macro EOF
     (en moltes configuracions, es pot canviar EOF per -1, però no és ansi C)
*/

#include <stdio.h>

int main(void) {

   int n, qu, max;
   float mitj;
   FILE *fin, *fout;      /* aquest tipus especial "FILE"
                             i els punters a aquest tipus
                             s'usen per a "obrir" i "tancar" fitxers */ 
   

   /* obertura del fitxer de dades */
   fin = fopen("f1.dad", "r");            /* "r" vol dir read */
   if (fin == NULL) { 
      printf("no s'obre f1.dad \n"); 
      return 1;
   }
   
   /* lectura de dades del fitxer que s'ha obert  
      i càlculs: quantitat, màxim i mitjana */
   qu = 0;
   mitj = 0.;
   
   while (fscanf(fin, "%d", &n) != EOF) { /* lectura de dades, mentre n'hi hagi */
      
      qu = qu+1;
      mitj = mitj+n;
      
      if (qu == 1) 
         max = n;
      
      else 
         if (n>max) max = n;
   }


   /* obertura del fitxer d'escriptura 
      i escriptura dels resultats */
   fout = fopen("f1.res", "w");           /* "w" vol dir write */
   if (fout == NULL) { 
      printf("no s'obre f1.res \n"); 
      return 1;
   }

   if (qu == 0) 
      fprintf(fout, "no hi havia dades \n");
   
   else {
      mitj = mitj/qu;
      fprintf(fout," quantitat = %d \n", qu);
      fprintf(fout," maxim = %d \n", max);
      fprintf(fout," mitjana = %f \n", mitj);
   
   }


   /* TANCAMENT dels fitxers oberts */
   fclose(fin); 
   fclose(fout);
   
   /*Comentaris:
      1) Si no es fa explícitament el tancament,
         es fa per defecte en sortir del programa.
         És millor fer-ho explícitament.

      2) El fitxer de dades es podia tancar abans, 
         tan aviat com ja les havíem llegit totes.

      3) En aquest exemple concret:
            primer es llegeixen totes les dades
            després s'escriuen tots els resultats
         per tant, es podia usar un sol punter a FILE, reaprofitant-lo */

   return 0;
} 
