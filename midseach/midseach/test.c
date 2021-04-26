#include <stdio.h>
#include <string.h>

void test(int* a, int sz,int val)
{
	int left = 0;
	int right = sz;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == val)
		{
			printf("%d\n",a[mid]);
			break;
		}
		if (a[mid] < val)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	printf("Ã»ÕÒµ½\n");
} 

int main()
{
	int a[] = {11, 22, 33, 44, 52, 67, 111};
	int sz = sizeof(a)/sizeof(a[0]);
	test(a,sz,1000);

	return 0;
}