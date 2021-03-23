#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>

void beFiboStep(int n)
{
	int f0 = 0;
	int f1 = 1;
	int f2 = 0;
	while (1)
	{
		f2 = f1 + f0;
		if (f2 == n)
		{
			printf("f2=%d\n", f2);
			printf("%d\n", f2 - n);
			break;
		}
		if (n > f1 && n < f2)
		{
			int step = abs(f1 - n) < abs(f2 - n) ? abs(f1 - n) : abs(f2 - n);
			printf("f1=%d\tf2=%d\n%d\n",f1,f2,step);
			break;
		}
		f0 = f1;
		f1 = f2;
	}
}
void test()
{
	int n = 0;
	while (scanf("%d",&n) != EOF)
	{
		beFiboStep(n);
	}

}

int main()
{
	
	test();
	
	return 0;
}