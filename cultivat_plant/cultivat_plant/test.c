#include <stdio.h>

 void canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
	if (n == 0)
	{
		printf("true");
	}
	else
	{
		int k = 0;
		int cmp = 0;
		for (int i = 0; i < flowerbedSize; i++)
		{
			if (flowerbed[0] == 0 && k == 0)
			{
				k = -2;
			}
			if (flowerbed[i] == 1)
			{
				k = i - k;
				if ((k - 2) / 2 > 0)
				{
					cmp += (k - 2) / 2;
				}
				k = i;
			}
			if (i == (flowerbedSize - 1) && flowerbed[i] != 1)
			{
				k = i - k;
				if (k / 2 > 0)
				{
					cmp += k / 2;
				}
			}

		}
		if (cmp >= n)
		{
			printf("true");
		}
	}


	printf("false");
}
int main()
{
	int a[] = {0,1,0};
	canPlaceFlowers(a,3,1);


	return 0;
}