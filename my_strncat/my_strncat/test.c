#include <stdio.h>
#include <string.h>

void my_strncat(char* a,char* b,int c)
{
	while(*a)
	{
	     a++;
	}
	while(c)
	{
	     *a++ = *b++;
		 c--;
	}
	if(c==0)
	{
	     *a = '\0';	
	}
}

int main()
{
	char a[] = "abcd";
	my_strncat(a,a,3);
	printf("%s",a);

    return 0; 
}