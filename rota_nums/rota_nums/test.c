#include <stdio.h>

void rotate(int* nums, int numsSize, int k){
	while (k--)
	{
		int tem = nums[numsSize - 1];
		for (int i = numsSize - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = tem;
	}

}

int main()
{
	int a[] = {0,1,2,3,4,5,6,7};
	rotate(a,sizeof(a)/sizeof(a[0]),3);

	return 0;
}