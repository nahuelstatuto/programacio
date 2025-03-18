/* puntFunc1.c
ejemplo de puntero a funcion y de las formas en las que se puede 
declarar y llamar
*/

#include <stdio.h>

void fun(int);

int main()
{ 
	/* Declaración del puntero y asignacion */
	void (*puntero1)(int) = &fun;
    void (*puntero2)(int) = fun;

	/* Se puede hacer también de la siguiente forma 
	void (*fun_ptr)(int); 
	fun_ptr = &fun; 
	*/

	/* llamamos a la función con el puntero */
	(*puntero1)(10);
	puntero2(25);

	fun(3);

	return 0; 
} 

void fun(int a) 
{ 
	printf("El valor de a es: %d\n", a); 
} 
