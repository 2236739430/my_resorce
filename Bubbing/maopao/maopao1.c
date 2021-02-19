#include <stdio.h>
#include <string.h>

void maopao(int* a,int b)
{
	int i=0;
	int j=0;
	int tem=0;
	int flag=1;
	for(i=0;i<b;i++)
	{
	for(j=0;j<b-i-1;j++)
	{
		if(*(a+j)>*(a+j+1))
		{
		tem = *(a+j);
		*(a+j)= *(a+j+1);
		*(a+j+1)=tem;
		flag=0;
		}
	}
	if(flag==1)
	{
	break;
	}
	}
}

int main()
{
	int i=0;
	int a[]={1,5,6,9,7,8,4,0};
	int b=sizeof(a)/sizeof(a[0]);
	maopao(a,b);

	return 0;
}