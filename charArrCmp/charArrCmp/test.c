#include <stdio.h>

int main()
{
	char a[][4] = {"abc","def","hhh"};
	//printf("%d\n",sizeof(a));//12
	//for (int i = 0; i < sizeof(a); i++)
	//{
	//	printf("%c\t",*((&(**a))+i));
	//}
	int end1 = 0;
	for (int i = 0; i < sizeof(a); i++)
	{
		if (*(&(**a) + i) == 0)
		{
			end1++;
		}
	}
	printf("%d\n",end1);

	return 0;
}