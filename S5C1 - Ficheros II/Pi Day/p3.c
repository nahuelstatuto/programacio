#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() {

    srand(SEED);
    int i, count, n;
    double x,y,val;
    FILE *fout1,*fout2;
    fout1=fopen("p3_in.res","w");
    fout2=fopen("p3_out.res","w");

    printf("n = ");
    scanf("%d", &n);

    count = 0;

    for(i = 0; i < n; ++i) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if( x * x + y * y <= 1 ){
            count++;
            fprintf(fout1,"%lf\t%lf\n",x,y);
        }else{
            fprintf(fout2,"%lf\t%lf\n",x,y);
        }
    }

    val = (double) count / n * 4;
    printf("val:\t  %g\n", val);
    fclose(fout1);
    fclose(fout2);

    return(0);
}

/*plot 'p3_in.res' lc "red", 'p3_out.res' lc "blue"*/
