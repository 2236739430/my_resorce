#include <stdio.h>

int main()
{
	char e = 'A';
	for(e='A'; e<='D' ; e++)
	{
	   if((e != 'A') + (e == 'C') + (e == 'D') + (e != 'D') == 3 )
	   {
	          printf("%c",e);
	   }
	}

	return 0;
}