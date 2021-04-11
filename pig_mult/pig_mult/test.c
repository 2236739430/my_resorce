#include <stdio.h>

int pig_mult(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2 * 1;
	}
	if (n == 3)
	{
		return 3 * 2 / 1;
	}
	if (n == 4)
	{
		return 4 * 3 / 2 + 1;
	}
	return n * (n - 1) / (n - 2) + (n - 3) - pig_mult(n - 4);
}


int clumsy(int N)
{
	return pig_mult(N);

}

int main()
{
	int n = 10;
	int b = clumsy(n);

	return 0;
}