#include<stdio.h>
#include <stdlib.h>        /* exit */
#include<math.h>
#include<float.h>

int main(void) {
int n, i;
float x0,j=1;
double a, b, h, x, eabs, erel;

/* ------- fitxers -------*/ 
FILE *pf;
pf = fopen("error_res.dat", "w");
   if (pf == NULL) { 
      printf("problemes en obrir el fitxer %s \n", "error_res.dat"); 
      exit(1);
   }
/* ------- fitxers -------*/ 

printf("# interval i quantitat de subintervals:");
printf(" a=? b=? n=? \n");
scanf("%le %le %d", &a, &b, &n);
if (n<1 || a>=b) return 1;

/* s’escriu la precisio relativa "oficial" per al tipus float:
minim valor "eps">0 tal que 1+"eps" > 1 */

printf("# FLT_EPSILON = %+.10e \n\n", FLT_EPSILON);
printf("%+.18e\t %+.18e\t \n\n", j, j+FLT_EPSILON/2);


/* es generen n+1 punts equidistants de [a,b],
es calculen els seus "errors de representacio en float",
i s’escriuen, avisant si algun supera "eps" */
h = (b-a)/n;

fprintf(pf, "# x double\t x0 float\t err abs \t err rel\n");

for (i=0; i<=n; i++) {
   x = a+i*h; /* valor "double" */
   x0 = x; /* valor "float" */
   eabs = (x0-x); /* error absolut */
   if (x != 0)
      erel = eabs/x; /* error relatiu */
   else
      erel = 1e+20; /* valor gran arbitrari */

   fprintf(pf, " %+.18e\t %+.8e\t %+.6e\t %+.6e\n", x, x0, eabs, erel); /* ------- fitxers -------*/ 
   
   /*printf(" %+.18e\t %+.8e\t %+.6e\t %+.6e", x, x0, eabs, erel);
   if (fabs(erel)>FLT_EPSILON) printf(" !!!");
   printf("\n");*/
   }
fclose(pf);
return 0;
}
