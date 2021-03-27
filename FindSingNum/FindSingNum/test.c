#include <stdio.h>

int XOR(int* nums, int numsSize)
{
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	return ret;
}

int* singleNumbers(int* nums, int numsSize)
{
	int ret = XOR(nums, numsSize);
	int pos = 0;
	int* num = (int*)malloc(sizeof(int)* 2);
	memset(num, 0, 8);
	for (int i = 0; i < 32; i++)
	{
		if ((ret >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}
	for (int i = 0; i < numsSize; i++)
	{
		if ((nums[i] >> pos) & 1 == 1)
		{
			num[0] ^= nums[i];
		}
		else
		{
			num[1] ^= nums[i];
		}
	}
	return num;
}

int main()
{
	int a[] = {4,1,4,6};
	int* num = (int*)malloc(sizeof(int)* 2);
	memset(num, 0, sizeof(num));
	num = singleNumbers(a,4);

	return 0;
}