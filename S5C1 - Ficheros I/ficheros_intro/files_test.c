#include <stdio.h>
 
#define  MAX_LEN  80
 
int main(void)
{
   FILE *stream;
   int l;
   float fp;
   char s[MAX_LEN + 1];
   char c;
 
   stream = fopen("datos.dat", "r");
 
   fscanf(stream, "%s", &s[0]);
   fscanf(stream, "%d", &l);
   fscanf(stream, "%c", &c);
   fscanf(stream, "%f", &fp);
 
   printf("string =\t %s\n", s);
   printf("long double =\t %d\n", l);
   printf("char =\t %c\n", c);
   printf("float =\t %f\n", fp);

   fscanf(stream, "%s", &s[0]);
   printf("string =\t %s\n", s);

   return 0;
}
