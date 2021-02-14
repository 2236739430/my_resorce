#include <stdio.h>
#include <string.h>

char* my_strcat(char* a,const char* b)
{
	 char* x = a;
	 while(*a)
	 {
	      a++;
	 }
	 while(*a++=*b++)
	 {
	  ;
	 }
	 return x;
}

int main()
{
	char a[] = "abc";
	char b[] = "efg";
	my_strcat(a,b);
	printf("%s",a);

	return 0;
}