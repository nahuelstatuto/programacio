#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() {

    srand(SEED);
    double rand_num = (double)rand() / RAND_MAX; /* between 0 and 1*/
}