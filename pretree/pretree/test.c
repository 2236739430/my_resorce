#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


typedef struct pretree
{
	char data;
	struct pretree* left;
	struct pretree* right;
}ptree;

ptree* treecreat(char* str, int* i)
{
	if (str[*i] == '#')
	{
		(*i)++;
		return NULL;
	}
	ptree* node = (ptree*)malloc(sizeof(ptree));
	node->data = str[(*i)++];
	node->left = treecreat(str, i);
	node->right = treecreat(str, i);
	return node;
}

void print(ptree* root)
{
	if (root == NULL)
	{
		return;
	}
	print(root->left);
	printf("%c \n", root->data);
	print(root->right);
}

int main()
{
	char str[100] = { 0 };
	scanf("%s", str);
	int i = 0;
	ptree* tree = treecreat(str, &i);
	print(tree);

	return 0;
}