#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
/////////////////////////////////////////////
//strlen


size_t my_strlen(const char* arr)
{
	size_t i = 0;
	while (*arr)
	{
		i++;
		arr++;
	}
	return i;
}

void test_my_strlen()
{
	char a[] = "abcdef";
	int b = my_strlen(a);
	printf("my_strlen:%d\nstrlen:%d\n",b,strlen(a));
}
/////////////////////////////////////////////////
//strcpy和strncpy

char* my_strncpy(char* arr1, const char* arr2,size_t sz)
{
	char* head = arr1;
	while (sz-- && *arr2)
	{
		*arr1++ = *arr2++;
	}
	*arr1 = 0;
	return head;
}
void test_my_strncpy()
{
	char a[] = "abc";
	printf("my_strncpy:%s\n",my_strncpy(a,"a",4));
}

char* my_strcpy(char* arr1, const char* arr2)
{
	char* head = arr1;
	while (*arr2)
	{
		*arr1++ = *arr2++;
	}
	*arr1 = 0;
	return head;
}
void test_my_strcpy()
{
	char a[] = "**********";
	printf("my_strcpy:%s\n",my_strcpy(a,"abc"));
}
void test1()
{
	char a[] = "abc";
	/*strcpy(a,"ABCDEFG");*///左边比右边字符长会出错，栈溢出
	strcpy(a,"*");//输出*，直接把abc替换掉而不是输出*bc
	printf("strcpy:%s\n",a);
	strncpy(a, "",4);
	printf("strcpy:%s\n", a);
}
/////////////////////////////////////////////////
//strcat和strncat
char* my_strncat(char* arr1, const char* arr2, size_t sz)
{
	char* head = arr1;
	while (*arr1)
	{
		arr1++;
	}
	while (sz-- && *arr2)
	{
		*arr1++ = *arr2++;
	}
	*arr1 = 0;
	return head;
}

void test_my_strncat()
{
	char a[80] = { 0 };
	printf("my_strncat:%s\n", my_strncat(a,"*****",3));
}

char* my_strcat(char* arr1, const char* arr2)
{
	char* head = arr1;
	while (*arr1)
	{
		arr1++;
	}
	while (*arr2)
	{
		*arr1++ = *arr2++;
	}
	return head;
}

void test_my_strcat()
{
	char a[80] = { 0 };
	printf("my_strcat:%s\n",my_strcat(a,"*****"));
}
/////////////////////////////////////////////////
//strcmp和strncmp

int my_strncmp(const char* arr1, const char* arr2, size_t dex)
{
	int sz = 0;
	while ((*arr1 || *arr2) && dex--)
	{
		if (*arr1 != *arr2)
		{
			if ((int)strlen(arr1) - (int)strlen(arr2) != 0)
			{
				return (int)strlen(arr1) - (int)strlen(arr2);
			}
			else
			{
				return -1;
			}
		}
		arr1++;
		arr2++;
	}
}

void test_my_strncmp()
{
	char a[] = "abc";
	char b[] = "abcf";
	printf("my_strncmp返回值:%d\n", my_strncmp(a, b,3));
}

int my_strcmp(const char* arr1, const char* arr2)
{
	int sz = 0;
	while (*arr1 || *arr2)
	{
		if (*arr1 != *arr2)
		{
			if ((int)strlen(arr1) - (int)strlen(arr2) != 0)
			{
				return (int)strlen(arr1) - (int)strlen(arr2);
			}
			else
			{
				return -1;
			}
		}
		arr1++;
		arr2++;
	}

}

void test_my_strcmp()
{
	char a[] = "abc";
	char b[] = "abcf";
	printf("my_strcmp返回值:%d\n", my_strcmp(a, b));
}

void test2()
{
	char a[] = "abc";
	char b[] = "abcd";
	printf("strcmp不相等但一样长返回值:%d\n",strcmp(a,b));//-1
}
/////////////////////////////////////////////////////////
//strstr

char* my_strstr(const char* arr1, const char* arr2)
{
	char* head1 = arr1;
	char* head2 = arr2;
	while (*arr2 && *arr1)
	{
		if (*arr1 == *arr2)
		{
			arr1++;
			arr2++;
		}
		else
		{
			arr1++;
			arr2 = head2;
			head1 = arr1;
		}
	}
	return head1;
}

void test_my_strstr()
{
	char a[] = "abcdef";
	printf("my_strstr:%s\nstrstr:%s",my_strstr(a,"cd"),strstr(a,"cd"));
}
/////////////////////////////////////////////////////////
//memcpy与strcpy类似但是可以在任意类型下使用

void* my_memcpy(void* dest, const void* src, size_t count)//void* 不能用
{
	void* head = dest;
	char* p1 = (char*)dest;
	char* p2 = (char*)src;
	while (*p2 && count--)
	{
		*p1++ = *p2++;
	}
	*p1 = 0;
	return head;
}
void test_my_memcpy()
{
	char a[] = "abcdef";
	printf("memcpy:%s\n", (char*)my_memcpy(a, "abc", 6));
}

void test3()
{
	char a[] = "abcdef";
	printf("memcpy:%s\n",(char*)memcpy(a,"abc",6));

}
/////////////////////////////////////////////////////////
//memmove count结束不置零

void* my_memmove(void* dest, const void* src, size_t count)
{
	void* head = dest;
	char* p1 = (char*)dest;
	char* p2 = (char*)src;
	int i = 0;
	if (p2 > p1)
	{
		for (i = 0; i < count; i++)
		{
			*(p1+i) = *(p2+i);
		}
	}
	else
	{
		for (i = count - 1; i >= 0; i--)
		{
			*(p1 + i) = *(p2 + i);
		}
	}

	return head;
}

void test_my_memmove()
{
	char a[] = "123456789";
	char b[] = "123456789";
	/*printf("memmove:%s\n",memmove(a+2,a,4));*/
	printf("my_memmove:%s\n", my_memmove(a+2, a, 4));
}
/////////////////////////////////////////////////////////
void test()
{
		const char*str1 = "abcdef";
		const char*str2 = "bbb";
		if (strlen(str2) - strlen(str1)>0)//strlen返回无符号数，负数值很大
		{
			printf("str2>str1\n");
		}
		else
		{
			printf("srt1>str2\n");
		}
}


/////////////////////////////////////////////
int main()
{
	/*test();
	test1();
	test_my_strlen();
	test_my_strcpy();
	test_my_strcat();
	test2();
	test_my_strcmp();
	test_my_strncmp();
	test_my_strncpy();
	test_my_strncat();
	test_my_strstr();
	test3();
	test_my_memcpy();
	test_my_memmove();*/

	return 0;
}