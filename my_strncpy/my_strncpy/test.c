#include <stdio.h>

char* my_strncpy(char* a,const char* b,size_t sz)
{
	char* head = a;
	while (sz--)
	{
		*a = *b;
		a++;
		b++;
	}
	return head;
}

int main()
{
	char a[] = "abcdef";
	char b[] = "aaaaaa";
	my_strncpy(a,b,3);

	return 0;
}