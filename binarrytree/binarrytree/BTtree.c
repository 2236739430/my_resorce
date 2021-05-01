#include "BTtree.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

void QueuePush(Queue* q, BTNode* data)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		printf("error\n");
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;
	if (q->rear == NULL)
	{
		q->front = q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = q->rear->next;
	}
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
	{
		return 1;
	}
	return 0;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}


BTNode* QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}

BTNode* QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QNode* move = q->front;
	while (move != q->rear)
	{
		move = move->next;
		size++;
	}
	return size;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->rear = NULL;
}

BTNode* BuyNode(BTDataType* a)
{
	BTNode* New = (BTNode*)malloc(sizeof(BTNode));
	if (New == NULL)
	{
		printf("¿ª±ÙÊ§°Ü\n");
		return;
	}
	New->data = a;
	New->left = New->right = NULL;
}

void BinaryTreeCreate(BTNode** A)
{
	assert(A);
	*A = BuyNode('A');
	BTNode* B = BuyNode('B');
	BTNode* D = BuyNode('D');
	BTNode* E = BuyNode('E');
	BTNode* C = BuyNode('C');
	BTNode* F = BuyNode('F');
	(*A)->left = B;
	(*A)->right = C;
	B->left = D;
	C->left = E;
	C->right = F;
	return A;
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root)
	{
		return 0;
	}
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	return  root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->data == x)
	{
		return root;
	}
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left != NULL)
	{
		return left;
	}
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right != NULL)
	{
		return right;
	}
	return NULL;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	printf("%c ",root->data);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%c ", root->data);
}



int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (!root)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->left,k-1)+BinaryTreeLevelKSize(root->right,k-1);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue p1;
	QueueInit(&p1);
	if (root)
	{
	   QueuePush(&p1, root);
	}
   
	while (!QueueEmpty(&p1))
	{
		BTNode* front = QueueFront(&p1);
		QueuePop(&p1);
		printf("%c ",front->data);

		if (front->left)
		{
			QueuePush(&p1,front->left);
		}
		if (front->right)
		{
			QueuePush(&p1,front->right);
		}
	}
	QueueDestroy(&p1);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue p1;
	QueueInit(&p1);
	if (root)
	{
		QueuePush(&p1, root);
	}

	while (!QueueEmpty(&p1))
	{
		BTNode* front = QueueFront(&p1);
		QueuePop(&p1);
		if (!front)
		{
			break;
		}
		if (front->left)
		{
			QueuePush(&p1, front->left);
		}
		else
		{
			QueuePush(&p1, NULL);
		}
		if (front->right)
		{
			QueuePush(&p1, front->right);
		}
		else
		{
			QueuePush(&p1, NULL);
		}
	}
	while (!QueueEmpty(&p1))
	{
		BTNode* front = QueueFront(&p1);
		QueuePop(&p1);
		if (front)
		{
			return 0;
		}
	}

	QueueDestroy(&p1);
	return 1;
}
