/*
	Name: stack.h
	Copyright: Apache License 2.0
	Author: 瞿相荣
	Date: 23/10/22 21:44
	Description: C语言栈库，版本1.0.0.0
*/

#pragma once

#include"stdlib.h"

#include <stack.h>

STACK* InitStack() {
	STACK* stack = (STACK*)calloc(1,sizeof(STACK));
	stack->base = (stack_node*)calloc(1,sizeof(stack_node));
	if(stack->base==NULL) {
		return NULL;
	}
	stack->top = stack->base;
	stack->length = 0;
	return stack;
}

int ClearStack(STACK* stack) {
	if(stack==NULL) {
		return 0;
	}
	stack_node* tmp = stack->top->prev;
	while(stack->length!=0) {
		free(tmp->next);
		tmp = tmp->prev;
		stack->length--;
	}
	stack->top = stack->base;
	return 1;
}

int DestroyStack(STACK* stack) {
	if(ClearStack(stack)==0) {
		return 0;
	}
	free(stack);
	return 1;
}

int StackEmpty(STACK* stack) {
	if(stack==NULL) {
		return -1;
	}
	if(stack->length==0) {
		return 1;
	} else {
		return 0;
	}
}

int StackLength(STACK* stack) {
	if(stack==NULL) {
		return -1;
	}
	return stack->length;
}

void* GetTop(STACK* stack) {
	if(stack==NULL) {
		return NULL;
	}
	return stack->top->data;
}

int PushStack(STACK* stack,void* data) {
	if(stack==NULL) {
		return 0;
	}
	stack_node* tmp = (stack_node*)calloc(1,sizeof(stack_node));
	if(tmp==NULL) {
		return 0;
	}
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = stack->top;
	stack->top->next = tmp;
	stack->top = tmp;
	stack->length++;
	return 1;
}

void* PopStack(STACK* stack) {
	if(stack==NULL) {
		return NULL;
	}
	if(stack->length==0) {
		return NULL;
	}
	void* data = stack->top->data;
	stack_node* tmp = stack->top->prev;
	free(stack->top);
	stack->top = tmp;
	stack->length--;
	return data;
}

int StackTraverse(STACK* stack,STACK_VISIT visit) {
	if(stack==NULL) {
		return 0;
	}
	stack_node* tmp = stack->base->next;
	int i;
	for(i=0; i<(stack->length); i++) {
		if(visit(tmp->data)==0) {
			break;
		}
		tmp = tmp->next;
	}
	return i;
}


