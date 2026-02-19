/* return_ptr.c programa con un warning:

function returns address of local variable

compila, pero error de ejecucion
*/

#include <stdio.h>
#include <stdlib.h>

int* test();

int main() 
{ 
	
	int* p;  
	p = test(); 

	printf("%p\n", p); 
	printf("%d\n", *p);                                                            /*Invalid read of size 4*/
	return 0; 
} 


int* test() 
{ 
	int i = 10;
	return (&i);
} 
