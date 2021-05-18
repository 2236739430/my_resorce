#include <iostream>

int main()
{
	int a = 10;
	int c = 30;
	int& b = a;
	b = c;
	b = 20;

	return 0;
}