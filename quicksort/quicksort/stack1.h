#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STData;

typedef struct Stack
{
	STData* data;
	int top;
	int capacity;
}Stack;
// ��ʼ��ջ 
void StackInit(struct Stack* a);
// ��ջ
void StackPush(struct Stack* a, STData data);
// ��ջ 
void StackPop(struct Stack* a);
// ��ȡջ��Ԫ��
STData StackTop(struct Stack* a);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(struct Stack* a);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(struct Stack* a);
// ����ջ 
void StackDestroy(struct Stack* a);