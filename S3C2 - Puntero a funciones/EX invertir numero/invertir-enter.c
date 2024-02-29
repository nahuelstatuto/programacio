/* invertir-enter.c 
inversió de l'ordre dels dígits d'un enter, en una funció
cal fer a part: el signe i els zeros al final
ATENCIÓ: si la dada no cap en una variable int, no va bé
*/

#include <stdio.h>      /* printf, scanf */ 
#include <stdlib.h>     /* abs */

void invertir(int *);

int main(void)
{
   int m;

   printf("Aneu entrant enters, un a un. \n");
   printf("Vigileu que no estigguin fora del rang del tipus int ! \n");
   printf("Per a acabar, entreu 0. \n"); 
   
   scanf("%d", &m);
   while (m != 0) {
      printf("nombre llegit   = %d \n", m);
      invertir(&m);
      printf("nombre invertit = %d \n", m);      
      scanf("%d", &m);
   }
   printf("s'ha llegit el valor 0 \n");
   
   return 0;
}

/* funció que inverteix els dígits d'un enter
si té zeros al final, no es posen a davant
*/
void invertir(int *m) 
{
   int qu, digits[10], i, index = +1;;
   
      if (*m < 0) {
         index = -1;
         *m = -(*m);
      }
   /* s'eliminen els zeros del final (de fet, no cal fer-ho) */
   while ( *m % 10 == 0) 
      *m = *m /10;

   /* dígits que han quedat: se separen i es compten */
   qu = 0;
   while ( *m > 0) {
      digits[qu] = *m % 10;
      qu = qu+1;
      *m = *m /10;
   }
   
   /* construcció del número invertit */
   *m = 0;
   for (i=0; i<qu; i++)  
      *m = *m *10+digits[i];

   /* signe */
   if (index == -1) *m = -(*m);

   return;
}
