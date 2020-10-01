#include "stack.h"
#include <stdio.h>

void Initialize(Stack* stack)
{
	//stack->items->key = 0;
	stack->top = -1;
}
bool IsFull(const Stack* stack)
{
	if (stack->top == MAX_STACK_SIZE - 1)
	{
		return true;
	}

	return false;
}
bool IsEmpty(const Stack* stack)
{
	if (stack->top == - 1)
	{
		return true;
	}

	return false;
}
void Push(Stack* stack, element item)
{
	if (IsFull(stack) == false)
	{
		stack->top++;
		stack->items[stack->top] = item;
	}
	else
	{
		printf("Stack is full. Cannot push.\n");
	}
	
}
element Pop(Stack* stack)
{
	if (IsEmpty(stack) == false)
	{
		element temp = stack->items[stack->top];
		(stack->top)--;
		return temp;
	}
	else
	{
		printf("Stack is empty. Cannot remove.\n");
		element temp = { -1 };// place holder, dummy
		return temp;
	}
}