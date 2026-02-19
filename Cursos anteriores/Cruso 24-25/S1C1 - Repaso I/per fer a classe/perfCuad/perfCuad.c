#include<stdio.h>
#include<math.h>
#include<float.h>

int main(void) {
int n, aux;

printf("# nombre:");
scanf("%d", &n);
if (n<1) return 1;

aux = sqrt(n);

if (n==aux*aux) printf("# %d és un cuadrat perfecte: %d**2 = %d\n", n,aux,n);
else printf("# %d no és un cuadrat perfecte\n", n);

return 0;
}
