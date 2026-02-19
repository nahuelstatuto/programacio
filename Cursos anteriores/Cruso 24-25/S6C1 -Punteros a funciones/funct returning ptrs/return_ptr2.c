/* return_ptr2.c programa correcto
valgrind avisa de fuga de memoria
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
        
    int i=10, *j;
    j = (int*)malloc(sizeof(int));
    if(j==NULL){
		printf("problemes de memoria\n");
		exit(1);
	}
    *j=i;
	return (j);
} 
