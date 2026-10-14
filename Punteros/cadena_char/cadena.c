/* cadena.c 
ús elemental de punter a una cadena de caràcters
*/
#include <stdio.h>
#include <string.h>        /* per a strlen */

int main(void) {
   char frase[40] = "Me gusta programar en C";
   char * pc;
   int i;

   /*printf("escriu qualsevol cosa:\n");
   scanf("%39[0-9a-zA-Z ]", frase);*/

   pc = frase;
   
   printf("Espai reservat              %lu \n", sizeof(frase));
   printf("Espai ocupat                %lu \n", strlen(frase));
   
   printf("Direcció                    %p \n", frase);
   printf("Direcció                    %p \n", &frase);
   printf("Valor del punter            %p \n", pc);
   
   printf("Contingut                   %s \n", frase);
   printf("Contingut¿?                 %d \n", *frase); /* per què?*/
   printf("Contingut usant el punter   %s \n", pc);
   
   printf("El desè caràcter de la cadena és                 %c \n", frase[9]);
   printf("El desè caràcter usant notació de punters és     %c \n", *(frase+9));
   printf("El desè caràcter usant el punter és              %c \n", *(pc+9));
   printf("El desè caràcter usant el punter com a vector és %c \n", pc[9]);

   

   /*------------  PART I  ---------------------------------------------*/



   printf("Escriptura de la frase:  \n");
  
   printf("mètode 1:\n");
   for (i=0; i<strlen(frase); i++) printf("%c", frase[i]);
   printf("\n");
   
   printf("mètode 2:\n");
   while (*pc != '\0') printf("%c", *pc++);
   printf("\n");

   printf("mètode 3:\n");
   for (i=0; i<strlen(frase); i++) printf("%c", *(pc+i));
   pc = frase;   /* és necessari? */
   for (i=0; i<strlen(frase); i++) printf("%c", *(pc+i));
   printf("\n");
   


   /*------------  PART I  ---------------------------------------------*/   



   /* printf("respuesta: %d", (int) frase[0]);
   C guarda chars como int usando codigo ASCII ==> 
   '0' <-> 48, '1' <-> 49, ... , 'M'<-> 77, etc */


   return 0;
}
