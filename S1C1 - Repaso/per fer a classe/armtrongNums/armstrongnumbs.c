#include<stdio.h>
#include<math.h>

int main()
{
    int n, sum = 0, t, a;

    printf("nombre?\n");
    scanf("%d", &n);

    t = n;
    while(n != 0)
    {
        a = n%10;
        sum += a*a*a;
        n = n/10;
    }

    if(sum == t)  printf("%d és un nombre d'Armstrong.\n", t);
    else printf("%d NO és un nombre d'Armstrong.\n", t);

    return 0;
}
