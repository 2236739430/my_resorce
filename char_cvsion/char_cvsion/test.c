#include <stdio.h>
#include <string.h>

void char_cvsion(char* p,int size)
{
	int i = 0;
	char b[20];
	char* bb = b;
	char* c = p;
	while (size--)
	{
		*bb = *p;
		if (*p == ' ')
		{
			*bb = '%';
			*++bb = '2';
			*++bb = '0';
		}
		bb++;
		p++;
	}
	for (i = 0; i < sizeof(b); i++)
	{
		*(c + i) = b[i];
	}
}

int main()
{
	char a[] = "abc def yz";
	int size = sizeof(a);
	char_cvsion(a,size);
	
	printf("%s",a);

	return 0;
}