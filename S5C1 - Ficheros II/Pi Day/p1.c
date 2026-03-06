#include <stdio.h>
#include <stdlib.h>

int main() {
    int *r,n; 
    int i, k;
    int b, d;
    int c = 0;

    FILE *fout;    
    
    printf("N digitos = \n");
    scanf("%d",&n);    
    
    n = (n/4)*14;

    fout = fopen("p1.res","w");

    r=(int*)malloc((n+1)*sizeof(int));
    for (i = 0; i < n; i++) r[i] = 2000;
    r[i] = 0;

    for (k = n; k > 0; k -= 14) {
	    d = 0;

	    i = k;
	    for (;;) {
	        d += r[i] * 10000;
	        b = 2 * i - 1;

	        r[i] = d % b;
	        d /= b;
	        i--;
	        if (i == 0) break;
	        d *= i;
	    }
        
	    fprintf(fout,"%.4d\n", c + d / 10000);
	    c = d % 10000;
    }
    
    fclose(fout);
    return 0;
}
