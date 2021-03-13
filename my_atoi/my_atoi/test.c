#include <stdio.h>
#include <math.h>

int my_atoi(const char* str)
{
	int a = 0;
	int b = 0;
	char* fast = str;
	while (*fast)
	{
		b++;
		fast++;
	}
	while (*str)
	{
		a += (*str - 48) * pow(10,b-1);
		b--;
		str++;
	}
	return a;
}

int main()
{
	char a[] = "123456";
	int b = my_atoi(a);
	printf("%d",b);

	return 0;
}