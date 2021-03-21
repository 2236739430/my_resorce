#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void is_rota(const char* arr1, const char* arr2)
{
	if (strstr(strcat(arr1,"ABCDE"), arr2) == NULL)
	{
		printf("不是旋转得到的\n");
	}
	else
	{
		printf("是旋转得到的\n");
	}
}

void rota(char* arr, int sz)
{
	int i = 0;
	while (sz--)
	{
		char* move = arr;
		char tem = *arr;
		for (i = 0; i < strlen(arr)-1; i++)
		{
			*(move + i) = *(move + i + 1);
		}
		*(move + i) = tem;
	}

}

void test()
{
	char a[] = "abcd";
	rota(a,2);
	printf("rota:%s\n",a);
}

int main()
{
	char a[30] = "ABCDE";
	is_rota(a,"CDEAB");
	test();

	return 0;
}