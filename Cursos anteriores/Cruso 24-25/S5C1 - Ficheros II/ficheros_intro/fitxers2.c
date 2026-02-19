/* fitxers2.c
Exemple de:
   - lectura i escriptura en fitxers dels quals CAL LLEGIR ELS NOMS

Aplicació: 
el fitxer de dades conté:
   - el grau n d'un polinomi
   - els coeficients c_0, c_1, ..., c_n del polinomi (base natural)
   - els extrems d'un interval [a, b]
   - la quantitat m de subintervals en què es dividirà l'interval

es fan els càlculs adequats per a escriure, 
   en el fitxer de resultats:
      - molts valors x_i, y_i de la gràfica del polinomi
   per pantalla:
      - el màxim i el mínim "discrets" del polinomi en l'interval
*/

#include <stdio.h>
#include <stdlib.h>

double horner(int, double *, double);     /* per a avaluar el polinomi */

int main(void) {

   int n, i, m;
   double *c, a, b, h, x, px, xmax, xmin, pmax, pmin;
   char file[31];       /* per als noms del fitxers (reutilització) */
   FILE *pf;            /* per a poder-los obrir i tancar */
  
  
   /* fitxer de dades */
   printf("input file = ? (maxim 30 caracters) \n");
   scanf("%s", file);
   pf = fopen(file, "r");                    /* OBERTURA amb "r" */
   if (pf == NULL) { 
      printf("problemes per a obrir el fitxer %s \n", file); 
      exit(1);
   }


   /* lectura de les dades i memòria dinàmica */
   fscanf(pf, "%d", &n);
   c = (double *)malloc( (n+1)*sizeof(double));
   if (c == NULL) {
      printf("problemes en la memoria del vector c \n");
      exit(1);
   }
   for (i=0; i<=n; i++)
      fscanf(pf, "%le", &c[i]);
   fscanf(pf, "%le %le %d", &a, &b, &m);
   
   fclose(pf);                               /* TANCAMENT */


   /* fitxer on escriure punts de la gràfica del polinomi */
   printf("output file = ? (maxim 30 caracters) \n");
   scanf("%s", file);
   pf = fopen(file, "w");                    /* OBERTURA, amb "w" */
   if (pf == NULL) { 
      printf("problemes per a obrir el fitxer %s \n", file); 
      exit(2);
   }
  

   /* algorisme */

   /* inicialitzacions */
   px = horner(n, c, a);
   fprintf(pf, "%+.10le %+.10le \n", a, px);
   
   xmax = a;
   pmax = px;
   xmin = a;
   pmin = px;
   h = (b-a)/m;

   /* avaluacions en els punts discrets,
      i actualitzacions, quan calgui */
   for (i=1; i<=m; i++) {
      x = a+i*h;   
      px = horner(n, c, x);
      
      fprintf(pf, "%+.10le %+.10le \n", x, px);
      
      if (px > pmax) {
         xmax = x;
         pmax = px;
      }
      else if (px < pmin) {
         xmin = x;
         pmin = px;
      }
   }
   
   fclose(pf);


   /* escriptura del màxim i el mínim per pantalla */ 
   printf("xmax = %+.10le pmax = %+.10le \n", xmax, pmax);
   printf("xmin = %+.10le pmin = %+.10le \n", xmin, pmin);
   

   free(c);

   return 0;
} 


/* avaluació d'un polinomi en un punt
   per l'algorisme de Horner */
double horner(int n, double *c, double x) {

   int i;
   double p;

   p = c[n];
   for (i=n-1; i>=0; i=i-1)
      p = c[i]+x*p;

   return p;
}
