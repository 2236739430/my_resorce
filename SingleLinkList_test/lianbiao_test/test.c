#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void print(struct ListNode* p)
{
	while (p != NULL)
	{
		printf("%d",p->val);
		p = p->next;
	}

}

struct ListNode* deleteDuplicates(struct ListNode* head){
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* stop = NULL;
	struct ListNode* pre = head;
	struct ListNode* pro = head->next;
	while (pre != NULL && pro != NULL)
	{
		if (pre->val == pro->val)
		{
			while (pre->val == pro->val )
			{
				pre = pro;
				pro = pro->next;
				if (pro == NULL)
				{
					break;
				}
			}
			if (stop == NULL)
			{
				head = pro;
				pre = pro;
				if (pro == NULL)
				{
					return head;
				}
				pro = pro->next;
			}
			else
			{
				stop->next = pro;
				pre = pro;
				if (pro == NULL)
				{
					break;
				}
				pro = pro->next;
			}
		}
		else
		{
			stop = pre;
			pre = pro;
			pro = pro->next;
		}
	}

	return head;
}

void test()
{
	/*struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
	struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* e = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* f = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* g = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	a->val = 1;
	a->next = b;
	b->val = 2;
	b->next = c;
	c->val = 3;
	c->next = d;
	d->val = 3;
	d->next = e;
	e->val = 4;
	e->next = f;
	f->val = 4;
	f->next = g;
	g->val = 5;
	g->next = NULL;*/

	/*struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* e = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);

	a->val = 1;
	a->next = b;
	b->val = 1;
	b->next = c;
	c->val = 1;
	c->next = d;
	d->val = 2;
	d->next = e;
	e->val = 3;
	e->next = NULL;*/
	
	struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
	struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);

	a->val = 1;
	a->next = b;
	b->val = 1;
	b->next = NULL;

	deleteDuplicates(a);
	print(deleteDuplicates(a));


}

int main()
{
	test();

	return 0;
}