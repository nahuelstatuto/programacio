#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c, determinant, r1, r2, real, imag;
    
    printf("a, b i c:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    determinant = b*b - 4*a*c; 

    if(determinant >= 0)
    {
        r1 = (-b + sqrt(determinant))/2*a;
        r2 = (-b - sqrt(determinant))/2*a;
        printf("solucions: %.4lf , %.4lf ", r1, r2);
    }   
    else
    {
        real = -b/(2*a);
        imag = sqrt(-determinant)/(2*a);
        printf("solucions: %.4lf + i%.4lf , %.4lf - i%.4lf ", real, imag, real, imag);
    }
    printf("\n");
    return 0;
}
