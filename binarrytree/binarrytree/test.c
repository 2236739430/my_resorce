#include "BTtree.h"

void test()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	BinaryTreeCreate(&A);
	printf("%d\n\n", BinaryTreeSize(A)); 
	printf("%d\n\n", BinaryTreeLeafSize(A)); 
	BTNode* D = BinaryTreeFind(A,'D');
	printf("%c\n\n", D->data);
	BinaryTreeLevelOrder(A);
	int bool1 = BinaryTreeComplete(A);
	if (bool1 == 1)
	{
		printf("����ȫ������\n\n");
	}
	else
	{
		printf("������ȫ������\n\n");
	}
	printf("%d\n\n", BinaryTreeLevelKSize(A, 3));
	BinaryTreeDestory(&A);
}

int main()
{
	test();

	return 0;
}