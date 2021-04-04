void kLengthApart(int* nums, int numsSize, int k){
	if (numsSize == 1)
	{
		printf("true\n");
		return 0;
	}
	int pos1 = 0;
	int onenum = 0;
	int flag = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 1)
		{
			onenum++;
			if (onenum >= 2)
			{
				if ((i - pos1 - 1) < k)
				{
					flag = 1;
				}
			}
			pos1 = i;
		}

	}
	if (flag == 1)
	{
		printf("false\n");
		return 0;
	}
	if (onenum <= 1)
	{
		printf("true\n");
		return 0;
	}
	printf("true\n");

}

int main()
{
	int a[] = { 1, 0, 0, 1, 0, 1 };
	kLengthApart(a,sizeof(a)/sizeof(a[0]),2);

	return 0;
}