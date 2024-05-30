/* afinitats.c 

es defineix una afinitat de R^n com: 
      x ---> a(x) = Ax + p
on A és una matriu nxn,
   p, x són vectors de R^n 
observem: l'afinitat està determinada per n, A i p


s'usa un tipus estructurat amb 3 camps: 
   dimensió entera: n,
   matriu real nxn: A,
   vector de R^n: p
a més, memòria dinàmica


objectius del programa
   es llegeixen d'un fitxer:
      una dimensió n, 
      dues afinitats, a i b, de dimensió n
   o sigui, es llegeixen n, A, p, B, q (no es repeteix n)

   es calculen i s'escriuen en un fitxer:
      les dues afinitats composició, b(a) i a(b) 
   o sigui: matriu, vector, matriu, vector


explicació dels càlculs que cal fer
suposem
   x -> a(x) = Ax + p
   x -> b(x) = Bx + q
llavors
   b(a(x)) = b(Ax+p) = B(Ax+p)+q = (BA)x + (Bp+q)
   a(b(x)) = ...                 = (AB)x + (Aq+p)
*/

#include<stdio.h>
#include<stdlib.h>


/* tipus estructurat, necessari en diverses funcions */
typedef struct {
   int dim;
   double **mat;
   double *vec;
} afi;


/* funcions */
afi crea_afi(int);            /* malloc's */
void esborra_afi(afi);        /* free's */

afi composa(afi, afi);

void mat_per_mat(double **, double **, double **, int);
void mat_per_vec(double **, double *, double *, int);

void escriure(FILE *, afi);


int main(void) {

   int n, i, j;
   afi a, b, c;
   FILE *fit;
   char nom[20];

   /* lectura de dades d'un fitxer
      no es comprova que les dades siguin correctes */

   printf("fitxer de dades ? (menys 20 caràcters) \n");
   scanf(" %s", nom);
   
   fit = fopen(nom, "r");
   if (fit == NULL) {
      printf("error en fitxer de dades \n");
      exit(1);
   }

   /* dimensió */
   fscanf(fit, " %d", &n);

   /* afinitat a(x): una matriu i un vector */
   a = crea_afi(n);        /* a més de reservar memòria,
                              s'ha omplert el camp a.dim */ 
   
   for (i=0; i<n; i++)
      for (j=0; j<n; j++)
         fscanf(fit, " %le", &a.mat[i][j]);
   for (i=0; i<n; i++)
      fscanf(fit, " %le", &a.vec[i]);

   /* afinitat b(x): una matriu i un vector */
   b = crea_afi(n);        /* idem b.dim */
   
   for (i=0; i<n; i++)
      for (j=0; j<n; j++)
         fscanf(fit, " %le", &b.mat[i][j]);
   for (i=0; i<n; i++)
      fscanf(fit, " %le", &b.vec[i]);

   
   /* càlculs de les dues composicions d'afinitats 
      i escriptura en fitxer (en una funció)
      s'usa el mateix apuntador que per a la lectura */

   fclose(fit);
   
   printf("fitxer de resultats ? (menys de 20 caràcters) \n");
   scanf(" %s", nom);
   fit = fopen(nom, "w");
   if (fit == NULL) {
      printf("error en fitxer de resultats \n");
      exit(1);
   }

   /* composició c = b(a) */
   c = composa(b, a);
   fprintf(fit, "\n  afinitat b(a) :\n");
   escriure(fit, c);

   /* composició c = a(b) */
   esborra_afi(c);               /* per a no tenir un leak de memòria */
   c = composa(a, b);
   fprintf(fit, "\n  afinitat a(b) :\n");
   escriure(fit, c);


   /* tancaments */
   fclose(fit);

   esborra_afi(a);
   esborra_afi(b);
   esborra_afi(c);

   return 0;
}


/* reserva d'espai per a la matriu i el vector d'una afinitat 
   si algun alloc va malament, se surt del programa amb un exit 
   s'omple el camp de la dimensió */
afi crea_afi(int n) {

   int i;
   afi a;

   a.dim = n;

   a.mat = (double **)malloc(n*sizeof(double *));
   if (a.mat == NULL) {
      printf("problemes en a.mat \n");
      exit(2);
   }
   for (i=0; i<n; i++) {
      a.mat[i] = (double *)malloc(n*sizeof(double));
      if (a.mat[i] == NULL) {
         printf("problemes en a.mat[%d] \n", i);
         exit(3);
      }
   }

   a.vec = (double *)malloc(n*sizeof(double));
   if (a.vec == NULL) {
      printf("problemes en a.vec \n");
      exit(4);
   }

   return a;
}


/* alliberament de l'espai d'una afinitat (matriu i vector) */
void esborra_afi(afi a) {

   int i;

   for (i=0; i<a.dim; i++) 
      free(a.mat[i]);
   free(a.mat);
   
   free(a.vec);

   return;
}


/* producte de dues matrius quadrades */
void mat_per_mat(double **b, double **c, double **d, int n) {

   int i, j, k;

   for (i=0; i<n; i++)
      for (j=0; j<n; j++) {
         d[i][j] = 0.;
         for (k=0; k<n; k++) 
            d[i][j] = d[i][j]+b[i][k]*c[k][j];
      }

   return;
}


/* producte de matriu per vector */
void mat_per_vec(double **d, double *x, double *y, int n) {

   int i, j;

   for (i=0; i<n; i++) {
      y[i] = 0.;
      for (j=0; j<n; j++) 
         y[i] = y[i]+d[i][j]*x[j];
   }

   return;
}


/* composició a(b): x -> bx -> a(bx)
recordem les operacions:
      a(b(x)) = A(b(x))+p = A(Bx+q)+p = (AB)x+(Aq+p) 

atenció a la relació: fórmules <-> programació:
   A <-> a.mat, 
   p <-> a.vec, 
   B <-> b.mat, 
   q <-> b.vec
*/
afi composa(afi a, afi b) {

   int i;
   afi c;

   c = crea_afi(a.dim);
   
   /* AB <-> (a.mat)(b.mat) --> resultat a c.mat */
   mat_per_mat(a.mat, b.mat, c.mat, a.dim);

   /* Aq+p <-> (a.mat)(b.vec)+(a.vec) --> resultat a c.vec */
   mat_per_vec(a.mat, b.vec, c.vec, a.dim);
   for (i=0; i<a.dim; i++)
      c.vec[i] = c.vec[i]+a.vec[i];

   return c;
}


/* escriptura en un fitxer
   de la matriu i del vector que defineixen una afinitat */
void escriure(FILE *fit, afi c) {

   int i, j;

   fprintf(fit, "matriu:\n");
   for (i=0; i<c.dim; i++) {
      for (j=0; j<c.dim; j++)
         fprintf(fit, " %+.2le ", c.mat[i][j]);
      fprintf(fit, "\n");
   }

   fprintf(fit, "vector:\n");
   for (i=0; i<c.dim; i++)
      fprintf(fit, " %+.2le \n", c.vec[i]);
   fprintf(fit, "\n");

   return;
}
