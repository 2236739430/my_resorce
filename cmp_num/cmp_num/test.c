#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


void find_two_diff_num(int arr[], int sz, int *p1, int *p2)
{
	int i = 0;
	int ret = 0;
	int pos = 0;
	*p1 = 0;//����1�ĵ�ַ
	*p2 = 0;//����2 �ĵ�ַ
	//1.���������������ͬΪ0������Ϊ1���ʳ������ε������Ϊ0
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];//ѭ�������һ�εĽ����5^6,������101^110=011
	}
	//2.��ret��������Ϊ1��һλ
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)//��һ�����������ĺ���λΪ1
		{
			pos = i;
			break;
		}
	}
	//����
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			(*p1) ^= arr[i];//���������ε��������ʾ������ɳ������ε�posΪ1��Ҳ��Ӱ�졣
		}
	}
	(*p2) = (*p1) ^ ret;
}


int main()
{
	int arr[] = { 1, 2, 4, 4, 5, 6, 8, 1, 6, 2, 9, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);//�����С
	int num1 = 0;//����1
	int num2 = 0;//����2
	find_two_diff_num(arr, sz, &num1, &num2);
	printf("num1=%d,num2=%d\n", num1,num2);
	system("pause");

	return 0;
}
