#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char* arr)
{
	int n = strlen(arr);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if ((arr[j + 1] - '0') < (arr[j] - '0'))
			{
				char tem = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tem;
			}
		}
	}
}

int main()
{
	char arr[21] = "asdcfergdksldksldks";
	while (1)
	{
		scanf("%s", arr);
		if (strlen(arr) == 0)
		{
			break;
		}
		sort(arr);
	}
	return 0;
}