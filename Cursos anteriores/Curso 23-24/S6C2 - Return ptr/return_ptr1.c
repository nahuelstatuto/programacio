/* return_ptr1.c 
funciona correctamente
da errores en el valgrind por usar memoria no reservada
*/

#include <stdio.h>
#include <stdlib.h>

int* test();

int main() 
{ 
	
	int* p;  
	p = test(); 

	printf("%p\n", p); 
	printf("%d\n", *p); 
	return 0; 
} 


int* test() 
{ 
        
    int i=10,*j;
    j=&i;
	return (j);
} 
