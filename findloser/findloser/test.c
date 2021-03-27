#include <stdio.h>

int cmp(const int* x,const int* y)
{
	return *x - *y;
}

void FindLoseNum1(int* a,int numSize)
{
	qsort(a,numSize,sizeof(int),cmp);//O(NlogN)
	for (int i = 0; i < numSize; i++)
	{
		if (i != a[i])
		{
			printf("loser:%d\n",i);
			break;
		}
	}

}
void FindLoseNum2(int* a, int numSize)//O(N)
{
	int n = numSize + 1;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += i;
	}
	for (int i = 0; i < numSize; i++)
	{
		sum2 += a[i];
	}
	printf("lose:%d\n",sum1-sum2);
}
void FindLoseNum3(int* a, int numSize)//O(N)
{
	int n = numSize + 1;
	int loser = 0;
	for (int i = 0; i < n; i++)
	{
		loser ^= i;
	}
	for (int i = 0; i < numSize; i++)
	{
		loser ^= a[i];
	}
	printf("loser:%d\n",loser);
}

int main()
{
	int a[] = {3,1,0,2,7,4,6};
	FindLoseNum1(a, sizeof(a) / sizeof(a[0]));
	FindLoseNum2(a, sizeof(a) / sizeof(a[0]));
	FindLoseNum3(a, sizeof(a) / sizeof(a[0]));

	return 0;
}