/*
	Name: stack.h
	Copyright: Apache License 2.0
	Author: 瞿相荣
	Date: 23/10/22 21:44
	Description: C语言栈库，版本1.0.0.0
*/


#ifndef STACK_H
#define STACK_H

#include"stdlib.h"

typedef int (*STACK_VISIT)(void*);					//遍历的函数指针接口

typedef struct _STACK_ELEMENT_TYPE {					//栈的元素，采用双向链表式结构
	void* data;									//数据域
	struct _STACK_ELEMENT_TYPE* next;			//下一个
	struct _STACK_ELEMENT_TYPE* prev;			//上一个
} stack_node;

typedef struct {
	stack_node* top;								//栈顶
	stack_node* base;								//栈底
	int length;										//长度
} STACK;

STACK* InitStack();									//初始化一个栈，成功返回栈指针，否则返回NULL
int ClearStack(STACK* stack);						//清空一个栈，成功返回1，否则返回0
int DestroyStack(STACK* stack);						//销毁一个栈，成功返回1，否则返回0
int StackEmpty(STACK* stack);						//判断栈是否为空，是则返回1，否则返回0，出错返回-1
int StackLength(STACK* stack);						//返回栈的长度，出错返回-1
void* GetTop(STACK* stack);							//返回栈顶元素数据，出错返回NULL
int PushStack(STACK* stack,void* data);				//入栈 ，成功返回1，否则返回0
void* PopStack(STACK* stack);						//出栈并返回出栈的数据，错误返回NULL
int StackTraverse(STACK* stack,STACK_VISIT visit);	//从栈底到栈顶依次调用visit函数
//要求visit函数参数为数据，visit返回1代表处理成功，并开始处理下一个元素
//返回0代表处理失败，StackTraverse则终止处理并退出
//返回成功处理的元素个数

#endif

