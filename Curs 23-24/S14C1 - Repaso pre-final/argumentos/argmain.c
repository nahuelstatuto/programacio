#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int a, b, c, aux;
   FILE *pf;
   printf("%d\n", argc);
   if (argc == 3) {

      printf("Execucio del programa %s \n", argv[0]);
      printf("Es llegiran dades del fitxer %s \n", argv[1]);
      printf("S'escriuran resultats en el fitxer %s \n\n", argv[2]);
      printf("nada %s \n\n", argv[3]);

      pf = fopen(argv[1], "r");
      if (pf == NULL) {
         printf("Dificultats en obrir el fitxer de dades \n");
         exit (1);
      }
      fscanf(pf, "%d %d %d", &a, &b, &c);
      fclose(pf);

      if (a>b) {  aux = b; b = a;   a = aux; }
      if (b>c) {  aux = c; c = b;   b = aux; }
      if (a>b) {  aux = b; b = a;   a = aux; }

      pf = fopen(argv[2], "w");
      if (pf == NULL) {
         printf("Dificultats en obrir el fitxer de resultats \n");
         exit (1);
      }

      fprintf(pf, " %d\n %d\n %d\n", a, b, c);

      fclose(pf);

   } else {
      printf("Nombre d'arguments incorrecte \n");

   }

   return 0;
}