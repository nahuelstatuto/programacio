/* malloc_matrix.c

reservamos memoria para una matriz y 2 vectores. Pintamos la memoria y 
los valores de diferentes formas usando haciendo operaciones sobre la 
memoria

*/

#include <stdio.h>      /* scanf, printf */
#include <stdlib.h>     /* srand, rand, RAND_MAX, malloc, free , exit */ 
#include <time.h>       /* time */

int main(void) {

   int m=3, n=2, i, j;
   double **a, *b, *c, *aux;  /* el punter doble "serà una matriu"  
                           cada punter simple "serà un vector" */
   /* dimensions 
   printf("m, n = ? \n");
   scanf(" %d %d", &m, &n);
   if (m<1 || n<1) {
      printf("dimensions incorrectes \n");
      return 1;
   }*/
   

   /* assignació dinàmica de memòria als vectors + comprovacions */
   b = (double *) malloc(n*sizeof(double));              /* dimensió n */

   c = (double *) malloc(m*sizeof(double));              /* dimensió m */
   if (b == NULL || c == NULL) {
      printf("problemes en malloc de b o c \n");
      exit(1);
   }
   
   printf("La dirección inicial de memoria para b es: %p \n",b);
   printf("La dirección inicial de memoria para c es: %p \n",c);

   printf(" Toca intro per continuar...\n");  
   getchar(); 

   /* assignació dinàmica de memòria a la matriu + comprovacions */
   a = (double **)malloc(m*sizeof(double *));            /* m files */
   if (a == NULL) {
      printf("problemes en malloc de a \n");
      exit(2);
   }
   for (i=0; i<m; i++) {
      a[i] = (double *)calloc(n,sizeof(double));   /* la fila i té n columnes */
      if (a[i] == NULL) {
         printf("problemes en calloc d'algun a[i] \n");
         exit(3);
      }
   }
   for (i=0; i<m; i++) {
      for (j=0; j<n; j++){
          a[i][j] = (i+j)*2.;
          printf("a[%d][%d] = %lf\n", i, j, (i+j)*2.);

      }
   }

   
   printf("\n\n");
   for (i=0; i<m; i++) {
      for (j=0; j<n; j++){
          printf("&a[%d][%d]: %p\t",i,j,&a[i][j]);
          printf("a[%d][%d]: %lf\n",i,j,a[i][j]);

      }
   }

   printf(" Toca intro per continuar...\n");  
   getchar(); 

   printf("\n\n");
   for (i=0; i<m; i++) {
      for (j=0; j<n; j++){
          printf("&a[%d][%d]: %p\t",i,j,*(a+i)+j);
          printf("a[%d][%d]: %lf\n",i,j,a[i][j]);

      }
   }

   printf(" Toca intro per continuar...\n");  
   getchar(); 

   printf("\n\n");
   for (i=0; i<m; i++) {
      for (j=0; j<n; j++){
          aux = *(a+i)+j;
          printf("&a[%d][%d]: %p\t",i,j,aux);
          printf("a[%d][%d]: %lf\n",i,j,*aux);

      }
   }

   /* alliberament de memòria */ 
   for (i=0; i<m; i++) 
      free(a[i]);
   free(a);

   free(b);
   free(c);
   
   return 0;
}

