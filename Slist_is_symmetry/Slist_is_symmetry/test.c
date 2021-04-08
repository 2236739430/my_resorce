#include <stdio.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

void issymmetry(struct ListNode* A)
{
	if (A == NULL)
	{
		printf("true\n");
		return;
	}
	int step1 = 0;
	struct ListNode* move = A;
	struct ListNode* midmove = A;
	while (move != NULL)
	{
		step1++;
		move = move->next;
	}
	int gomidstep = step1 / 2;
	while (gomidstep--)
	{
		midmove = midmove->next;
	}
	step1 = step1 / 2 - 1;
	while (step1)
	{
		int step2 = step1;
		struct ListNode* moveA = A;
		while (step2--)
		{
			moveA = moveA->next;
		}
		if (moveA->val != midmove->val)
		{
			printf("false\n");
			return;
		}
		midmove = midmove->next;
		step1--;
	}
	printf("true\n");

}

void test()
{
	struct ListNode* a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* a4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	a1->val = 1;
	a1->next = a2;
	a2->val = 2;
	a2->next = a3;
	a3->val = 2;
	a3->next = a4;
	a4->val = 1;
	a4->next = NULL;
	issymmetry(a1);
	

}

int main()
{
	test();

	return 0;
}