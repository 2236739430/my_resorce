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
// 初始化栈 
void StackInit(struct Stack* a);
// 入栈
void StackPush(struct Stack* a, STData data);
// 出栈 
void StackPop(struct Stack* a);
// 获取栈顶元素
STData StackTop(struct Stack* a);
// 获取栈中有效元素个数 
int StackSize(struct Stack* a);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(struct Stack* a);
// 销毁栈 
void StackDestroy(struct Stack* a);