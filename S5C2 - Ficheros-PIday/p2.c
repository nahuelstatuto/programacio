#include <stdio.h>
#include <math.h>

void new_term(long  double *, double *, int *);

int main()
{
    long double aprox = 3.0,real, eps = 1e-17;
    double n=2.0;
    int sign = 1;

    FILE *fin;
    fin = fopen("p2.dad","r");
    fscanf(fin,"%LF",&real);
    fclose(fin);

    while(fabs(aprox-real)>eps) new_term(&aprox ,&n, &sign);


    printf("real:\t%.60LF\n",real);
    printf("aprox:\t%.60LF \t iterations: %d\n", aprox,(int) n/2);
    printf("error:\t%.60LF\n",real-aprox);

    return 0;
}

void new_term(long double *aprox, double *n, int *sign)
{
    *aprox = *aprox + (*sign * (4 / ((*n) * (*n + 1) * (*n + 2))));
    *sign = *sign * (-1);
    *n += 2;
}
