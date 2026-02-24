/* parentfirst.c
fuga de memòria per "alliberament del pare abans que els fills"
es recomana:
   sense -g i sense valgrind
   amb -g i amb valgrind
   amb -g, amb valgrind i amb --leak-check=full
*/
#include <stdio.h>     
#include <stdlib.h>

int main(void)
{
   int m, n, i, j, k, **a, *b; 
   
   printf("entra dims m i n de la matriu mxn: \n");

   scanf("%d %d", &m, &n);
   
   a = (int **)malloc (m*sizeof(int *));
   if (a == NULL) exit(1);
   for (i=0; i<m; i++) {
      a[i] = (int *)malloc (n*sizeof(int));
      if (a[i] == NULL) exit(1);
   }
   b = (int *)malloc (m*n*sizeof(int));
   if (b == NULL) exit(1);

   printf("entra els mxn elements: \n");
   for (i=0; i<m; i++) 
      for (j=0; j<n; j++) 
         scanf("%d", &a[i][j]);
   
   /* posem a[][] en b[] */
   k = 0;
   for (i=0; i<m; i++) 
      for (j=0; j<n; j++) { 
         b[k] = a[i][j];
         k = k+1;
      }
   
   /*for (i=0; i<n; i=i+1) free(a[i]);*/ /*  */
   free(a);

   printf("vector b: \n");
   for (i=0; i<k; i++) printf("%+d ", b[i]);
   printf("\n");
   
   free(b);

   return 0;
}
