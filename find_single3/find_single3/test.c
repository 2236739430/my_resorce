#include <stdio.h>
#include <math.h>

int find_single(int* a, int size)
{
	int newSize = size / 3 + 1;
	int* b = (int*)malloc(sizeof(int)*newSize);
	memset(b,0,newSize*4);
	b[0] = a[0];
	int cur = 1;
	for (int i = 1; i < size; i++)
	{
		if (a[i] != b[cur - 1])
		{
			b[cur++] = a[i];
		}
		if (cur == newSize)
		{
			break;
		}
	}
	int ret = 0;
	for (int i = 0; i < newSize; i++)
	{
		ret += b[i];
	}
	ret = ret * 3;
	for (int i = 0; i < size; i++)
	{
		ret -= a[i];
	}
	 
	return abs(ret / 2);
}

int main()
{
	int a[] = {3,3,3,7,6,6,6,9,9,9};
	//printf("%d\n",find_single(a,sizeof(a)/sizeof(a[0])));


	return 0;
}