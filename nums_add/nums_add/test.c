#include <stdio.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int num = K;
	int Ksize = 0;
	while (num)
	{
		Ksize++;
		num /= 10;
	}
	int len = Ksize > ASize ? Ksize + 1 : ASize + 1;
	int* new1 = (int*)malloc(sizeof(int)*len);
	int len1 = ASize - 1;
	int len2 = len - 1;
	memset(new1, 0, sizeof(int)*len);

	int add = 0;

	while (K != 0 || len1 >= 0 || add != 0)
	{
		int count = 0;
		int a = len1 >= 0 ? A[len1] : 0;
		count = a + K % 10 + add;
		add = count / 10;
		new1[len2] = count % 10;
		K = K / 10;
		len1--;
		len2--;
	}
	*returnSize = len - len2 - 1;
	return new1 + len2 + 1;
}

int main()
{
	int a[] = {0};
	int K = 23;
	int returnsize = 0;
	int* p = addToArrayForm(a,1,K,&returnsize);

	for (int i = 0; i < returnsize; i++)
	{
		printf("%d\n",*(p+i));
	}

	return 0;
}