#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	int cur = 1;
	char a[100];
	char* head = a;
	gets(a);
	cur = strlen(a)-1;
	while (cur>=0)
	{
		if (a[cur] == ' ' )
		{
			printf("%s ",a+cur+1);
			a[cur] = 0;
		}
		if (a+cur == head)
		{
			printf("%s", a + cur);
			a[cur] = 0;
			break;
		}
		cur--;
	};

	return 0;
}