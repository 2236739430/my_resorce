#include <stdio.h>
#include <math.h>

char * addStrings1(char * num1, char * num2){
	char* head1 = num1;
	char* head2 = num2;
	int size1 = 0;
	int size2 = 0;
	while (*head1)
	{
		head1++;
		size1++;
	}
	while (*head2)
	{
		head2++;
		size2++;
	}
	int len = (size1 >= size2) ? size1 : size2;
	int bigsize = (size1 >= size2) ? size1 : size2;
	int min = (size1<size2) ? size1 : size2;
	char* big = (size1 >= size2) ? num1 : num2;
	char* res = (char*)malloc(sizeof(char)*(len + 2));
	res[len + 1] = 0;
	int flag = 0;
	while (size1-- && size2--)
	{
		if (num1[size1] + num2[size2] - 2 * '0' >= 10)
		{
			res[len] = (num1[size1] + num2[size2] - ':' + flag);//ASCII码值没有10故不能直接-10
			flag = 1;
			if (res[len] - '0' >= 10)
			{
				flag += 1;
				res[len] -= 10;
			}
			len--;
		}
		else
		{
			res[len] = num1[size1] + num2[size2] - '0' + flag;
			if (res[len] - '0' >= 10)
			{
				flag = 1;
				res[len] -= 10;
			}
			else
			{
				flag = 0;
			}
			len--;
		}
	}
	for (int i = bigsize - min - 1; i >= 0; i--)
	{
		res[len] = big[i] + flag;
		if (res[len] - '0' >= 10)
		{
			flag = 1;
			res[len] -= 10;
		}
		else
		{
			flag = 0;
		}
		len--;
	}
	if (flag == 1)
	{
		res[len] = flag + '0';
		len--;
	}

	return res + len + 1;

}
char* addStrings2(char* num1, char* num2) 
{
	int i = strlen(num1) - 1;
	int j = strlen(num2) - 1;
	int big = fmax(i, j);
	int add = 0;
	char* ans = (char*)malloc(sizeof(char)* (big + 3));
	ans[big + 2] = 0;
	int len = 0;
	while (i >= 0 || j >= 0 || add != 0) 
	{
		int x = i >= 0 ? num1[i] - '0' : 0;
		int y = j >= 0 ? num2[j] - '0' : 0;
		int result = x + y + add;
		ans[len++] = '0' + result % 10;
		add = result / 10;
		i--, j--;
	}
	// 计算完以后的答案需要翻转过来
	for (int i = 0; i < len/2; i++) {
		int t = ans[i];
		ans[i] = ans[len - i - 1];
		ans[len - i - 1] = t;
	}
	return ans;
}

int main()
{
	char a[] = "99";
	char b[] = "11";
	//printf("%s\n", addStrings1(a, b));//法1
	printf("%s\n", addStrings2(a, b));//法2

	return 0;
}