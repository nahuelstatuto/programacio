/* dames8.c 
problema de les 8 dames, es calculen TOTES les solucions
Convenis:
1)
es numeren les files i les columnes de 0 a 7
es numeren les diagonals "creixents" de 0 a 14 començant a la casella (0,0)
es numeren les diagonals "decreixents" de 0 a 14 començant a la casella (7,0)
2)
es posarà una dama a cada columna; per tant, no cal mirar amenaces per columnes
3)
una solució es representa com un vector x[8] d'enters tal que
         x[k] = j vol dir: la dama de la COLUMNA k és a la FILA j
4)
s'usen vectors f[8], c[15], d[15], amb valors a {0,1} per a controlar, respectivament,
amenaces per files, per diagonals creixents i per diagonals decreixents
Exemples:
      f[2]=0 vol dir que NO hi ha cap dama en la FILA 2
      c[4]=1 vol dir que SÍ que hi ha una dama en la DIAGONAL CREIXENT 4
      d[8]=0 vol dir que NO hi ha una dama en la DIAGONAL DECREIXENT 8
*/

#include <stdio.h> 

void prova(int);     /* funció recursiva que implementa el "backtracking" */
void escriure(int, int[]);       /* funció per a escriure una solució */
int f[8], c[15], d[15], x[8], qu = 0;     /* variables globals,
                                             qu compta les solucions */
	
int main(void)
{
   int i;

   /* inicialització: totes les files i diagonals estan desocupades*/
   for (i=0; i<8; i++) f[i] = 0;
   for (i=0; i<15; i++) {c[i] = 0; d[i] = 0;}

   /* s'invoca la funció recursiva que va posant les dames, 
      començant per la de la columna 0 */
   prova(0);

   return 0;
}

/* intent de posar la dama de la columna  k */
void prova(int k)
{
   int j;
   
   /* com que es volen totes les solucions, cal mirar totes les files j */
   for (j=0; j<8; j++) {
      /* la condició de si és factible x(k)=j és molt fàcil */
      if ( f[j] + c[k+j] + d[k-j+7] == 0 ) {
         /* printf("es posa la dama de la columna k= %d en la fila j= %d\n", k, j); */
         x[k] = j;
         /* es fan constar les amenaces d'aquesta dama acabada de posar */
         f[j] = 1;
         c[k+j] = 1;
         d[k-j+7] = 1;
         
         if (k < 7)        /* encara cal posar més dames */
            prova(k+1);
         else {            /* ja s'han posat les 8 dames: es té una solució */
            qu = qu+1;
            escriure(qu, x);
         }
	 
         /* com que es volen totes les solucions, cal mirar més possibilitats */ 
         /* printf("es retira la dama de la columna k= %d i la fila j= %d\n", k, j); */
         f[j] = 0;
         c[k+j] = 0;
         d[k-j+7] = 0;
      }
   }
   
   return;
}

void escriure(int qu, int x[])
{
   int i;

   printf("solucio numero %2d:  ", qu);
   for (i=0; i<8; i++)
      printf(" %d ", x[i]);
   printf("\n");
}
