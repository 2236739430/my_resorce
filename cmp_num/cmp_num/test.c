#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


void find_two_diff_num(int arr[], int sz, int *p1, int *p2)
{
	int i = 0;
	int ret = 0;
	int pos = 0;
	*p1 = 0;//数字1的地址
	*p2 = 0;//数字2 的地址
	//1.把所有数字异或，相同为0，相异为1，故出现两次的数异或为0
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];//循环到最后一次的结果是5^6,即就是101^110=011
	}
	//2.找ret二进制中为1的一位
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)//上一步两个数异或的后两位为1
		{
			pos = i;
			break;
		}
	}
	//分组
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			(*p1) ^= arr[i];//异或出现两次的消除，故就算碰巧出现两次的pos为1，也不影响。
		}
	}
	(*p2) = (*p1) ^ ret;
}


int main()
{
	int arr[] = { 1, 2, 4, 4, 5, 6, 8, 1, 6, 2, 9, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);//数组大小
	int num1 = 0;//数字1
	int num2 = 0;//数字2
	find_two_diff_num(arr, sz, &num1, &num2);
	printf("num1=%d,num2=%d\n", num1,num2);
	system("pause");

	return 0;
}
