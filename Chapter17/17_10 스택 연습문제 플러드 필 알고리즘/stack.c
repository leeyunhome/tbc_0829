#include "stack.h"

void Initialize(Stack* stack)
{
	stack->top = -1;
}

bool IsFull(const Stack* stack)
{
	if (stack->top == MAX_STACK_SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmpty(const Stack* stack)
{
	if (stack->top == -1)
		return true;
	else
		return false;
}
void Push(Stack* stack, element item)
{
	if (IsFull(stack))
		printf("Stack is full. cannot add.\n");
	else
	{
		stack->items[++stack->top] = item;
	}
}
element Pop(Stack* stack)
{
	if (IsEmpty(stack))
		printf("Stack is empty. cannot remove.\n");
	else
	{
		element temp = stack->items[stack->top--];
		return temp;
	}
}
