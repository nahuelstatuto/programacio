/* puntFunc2.c
llamamos a una funcion que recibe un puntero de funciones para pasarle cualquire funcion con los mismo argumentos
*/
#include <stdio.h> 


void fun1(int);
void fun2(int);
void funSelector(void (*fun)(int));

int main() 
{ 
	funSelector(fun1); 
	funSelector(fun2); 
	return 0; 
}

void fun1(int a){
    printf("Fun1 multiplica por 2: %d\n", a*2); 
} 
void fun2(int a){
    printf("Fun2 suma 10: %d\n", a+10);
} 
void funSelector(void (*fun)(int)) 
{ 
	fun(11); 
} 

