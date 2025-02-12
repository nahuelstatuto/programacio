#include <stdio.h>
#include "funciones.h"

void test(void) {
    printf("%s:%s:%d \n", __FILE__, __func__, __LINE__);
    return;
}