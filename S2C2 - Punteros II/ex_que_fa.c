#include <stdio.h>


void func1(int*, int*);
void func2(int*, int);

int main() {
    int x = 5, y = 10;
    int valor = 7;
    
    printf("1) x = %d, y = %d\n", x, y);
    func1(&x, &y);
    printf("2) x = %d, y = %d\n", x, y);

    printf("3) valor = %d\n", valor);
    func2(&valor, x);
    func2(&y, x);
    printf("4) valor = %d x = %d, y = %d\n", valor, x, y);

    return 0;
}

void func1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void func2(int *a, int b) {
    *a += b;
}