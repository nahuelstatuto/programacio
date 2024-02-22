/* poten2.c

donada una matriu A quadrada nxn es fa:
   s'inicialitzen
      y vector de dimensió n amb valors aleatoris a [-1,+1]
      x <--- y / |y||
   s'itera, per a k=1,2,...,p
      y <--- Ax
      x <--- y / ||y||

es vol observar si el vector x tendeix a estabilitzar-se o no

resultats:
- el vector x tendeix a estabilizar-se "gairebé sempre", 
però potser excepte el signe

- si s'executa diverses vegades amb la mateixa matriu,
encara que canviï el vector aleatori inicial y,
tendeix a estabilitzar-se al mateix vector x

en aquest exemple es recorda: 
   com treballar amb vectors i matrius (molts for's)
   com s'usen les funcions
   ús de rand()
*/

#include <stdio.h>         /* scanf, printf */      
#include <stdlib.h>        /* rand, srand, exit */     
#include <time.h>          /* time */     
#include <math.h>          /* sqrt */     

#define N 3

void Ax(int n, double a[N][N], double x[N], double y[N]);
double norma2(int n, double y[N]);
double euc_dist(int n, double y1[N], double y[N]);

int main(void){ 

   int n, i, j, k, p;
   double a[N][N], x[N], y[N], y1[N], aux, eps=1e-6;
   double matrix[3][3] = {
            {1,2,0},
            {-2,1,2},
            {1,3,1},
            };


   /* dimensió */
   printf("# n = ? \n");
   scanf(" %d", &n);
   if (n < 0 || n > N) {
      printf("n incorrecte \n");
      exit(1);
   }
   
   /* lectura de dades a[][] i p */
   /*printf("# matriu A per files = ? \n");
   for (i=0; i<n; i++) 
      for (j=0; j<n; j++) 
         scanf(" %le", &a[i][j]);
   */
   printf("# p = ? (enter positiu) \n");
   scanf(" %d", &p);
   if (p < 1) {
      printf("p incorrecte \n");
      exit(2);
   }
   
   /* vectors inicials */
   srand((unsigned)time(NULL));
   for (i=0; i<n; i++) 
      y[i] = -1.+2.*rand()/RAND_MAX;

   aux = norma2(n, y);
   for (i=0; i<n; i++) 
      x[i] = y[i]/aux;

   printf("k=%d, x: \n", 0);
   for (i=0; i<n; i++)
      printf("%+.4lf,", x[i]);
   printf("\n");

   /* iteració */
   for (i=0; i<n; i++)  y1[i] = x[i];
   
   for (k=1; k<=p; k++) {
      Ax(n, matrix, x, y);
      aux = norma2(n, y);
      for (i=0; i<n; i++) 
         x[i] = y[i]/aux;
      
      printf("k=%d, x: \n", k);
      for (i=0; i<n; i++)
         printf("%+.4lf,", x[i]);
      printf("\n");

      if (euc_dist(n,y1,x)<eps){
        printf("\n\n");        
        printf("convergeix a:\n");
        for (i=0; i<n; i++)  printf("%+.4lf,", x[i]);
        printf("\n");
        printf("amb el VAP %+.4lf \n", aux);
        printf("\n");
        return 0;         
      } else {
        for (i=0; i<n; i++)  y1[i] = x[i];
      }
       
   }
   
   
  
   return 0;
}

/* producte de matriu per vector */
void Ax(int n, double a[N][N], double x[N], double y[N]) {

   int i, j;

   for (i=0; i<n; i=i+1) {
      y[i] = 0;
      for (j=0; j<n; j=j+1) 
         y[i] = y[i]+a[i][j]*x[j];
   }

   return;
}

/* normalització d'un vector en norma-2 */
double norma2(int n, double y[N]) {
 
   int i;
   double norm = 0;

   for (i=0; i<n; i=i+1)
      norm = norm+y[i]*y[i];

   norm = sqrt(norm);

   return norm;
}

/* distancia euclideana d'un parell de vectors */
double euc_dist(int n, double y1[N], double y[N]) {
 
   int i;
   double norm = 0;

   for (i=0; i<n; i=i+1)
      norm = norm+(y1[i]-y[i])*(y1[i]-y[i]);

   norm = sqrt(norm);

   return norm;
}
