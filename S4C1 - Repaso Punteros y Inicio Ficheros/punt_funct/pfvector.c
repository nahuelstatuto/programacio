/* pfvector.c
exemple d'ús d'un VECTOR DE PUNTERS A FUNCIÓ

dades:
   dos reals x, y (amb y diferent de 0)
resultat:
   escriure els resultats de les 4 operacions elementals amb x i y
*/

#include <stdio.h>
#include <stdlib.h>

/* les 4 funcions */
double suma(double x, double y) { return x + y; }
double rest(double x, double y) { return x - y; }
double mult(double x, double y) { return x * y; }
double divi(double x, double y) { return x / y; }
   

int main(void) {
   int i;
   double x, y;
   
   /* vector de punters a caràcters (<-> vector de "cadenes")
      declaració i inicialització
      això només servirà per a escriure el resultat d'una manera bonica 
   */
   char *noms[4] = { "sumat amb", "restat amb", "multiplicat per", "dividit per"};
   
   
   /* vector de punters a funció: declaració i 
                                 assignació de valors (adreces de funcions) */
   double (*pf[4])(double, double);
   pf[0] = &suma;
   pf[1] = &rest;
   pf[2] = &mult;
   pf[3] = &divi;
   
   /* comentaris:
      - es poden suprimir els &
      - es pot fer declaració i inicialització a la vegada:
            double (*pf[4])(double, double) = {&suma, &rest, &mult, &divi}; 
      - en aquesta última expressió també es poden treure els &
   */


   /* lectura de dades i comprovació de la y */
   printf(" x = ? y = ? (ha de ser y != 0) \n");
   scanf("%le %le", &x, &y);
   if (y == 0) {
      printf("el segon operand es 0 \n");
      exit(1);
   }
   

   /* les 4 operacions elementals amb aquestes dades */
   for (i=0; i<4; i++)
      printf(" %+le %15s %+le dona %+le \n", x, noms[i], y, (*pf[i])(x, y));
   
   /* comentari:
      es pot canviar (*pf[i]) per pf[i]:
         printf(" %+le %15s %+le dona %+le \n", x, noms[i], y, pf[i](x, y));
   */
   
   return 0;
}
