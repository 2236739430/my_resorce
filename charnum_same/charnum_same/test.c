#include <stdio.h>

void arrayStringsAreEqual(char (*word1)[3], int word1Size, char (*word2)[3], int word2Size){
	int size1 = strlen(*word1) + strlen(*(word1 + 1));
	int size2 = strlen(*word2) + strlen(*(word2 + 1));
	if ((size1) != (size2))
	{
		printf("false");
		return;
	}
	int len1 = 0;
	int len2 = 0;
	char* copy1 = (char*)malloc(sizeof(char)* (size1 + 1));
	memset(copy1, 0, size1 + 1);
	char* copy2 = (char*)malloc(sizeof(char)* (size2 + 1));
	memset(copy2, 0, size2 + 1);
	for (int i = 0; i < size1 + 3; i++)
	{
		if (*(&(**word1) + i) != 0)
		{
			copy1[len1++] = *(&(**word1) + i);
		}printf("%d%d", size1, size2);
	}


	for (int i = 0; i < size2+3; i++)
	{

		if (*(&(**word2) + i) != 0)
		{
			copy2[len2++] = *(&(**word2) + i);
		}
	}

	if (strcmp(copy1, copy2) != 0)
	{
		printf("false");
		return;
	}
	printf("true");
	

}

int main()
{
	char word1[2][3] = { "ab", "c" };
	char word2[2][3] = { "a", "bc" };
	arrayStringsAreEqual(word1,2,word2,2);

	return 0;
}