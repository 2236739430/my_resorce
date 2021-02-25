#include <stdio.h>
#include <string.h>

void* my_memcpy(void *str1, const void *str2, size_t n)
{
	void* x = str1;
	while (n--)
	{
		*((char*)str1)++ = *((char*)str2)++;
	}
	return x;
}

int main()
{
	int a[] = { 1, 2, 3, 4 };
	int b[10] = { 0 };
	char c[] = "abcd";
	char d[] = "********";
	my_memcpy(b, a, 16);
	my_memcpy(d, c, 16);

	return 0;
}