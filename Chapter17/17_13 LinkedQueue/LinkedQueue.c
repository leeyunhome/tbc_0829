#include "LinkedQueue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}

static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}

void InitializeQueue(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;

	pq->n_items = 0;
}
bool QueueIsFull(const Queue* pq)
{
	return pq->n_items >= MAXITEMS ? true : false;
}
bool QueueIsEmpty(const Queue* pq)
{
	return pq->n_items == 0 ? true : false;
}
int QueueItemCount(const Queue* pq)
{
	return pq->n_items;
}

bool EnQueue(Item item, Queue* pq)
{
	if (QueueIsFull(pq))
	{
		printf("Queue is full. Cannot enqueue\n");
		return false;
	}
	else
	{
		pq->front = (Node*)malloc(sizeof(Node));
		pq->rear = (Node*)malloc(sizeof(Node));
		pq->front->next = pq->rear;
		pq->rear->item = item;
		pq->n_items++;
		return true;
	}
}
bool DeQueue(Item* pitem, Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("Queue is empty. Cannot dequeue.\n");
		return false;
	}
	else
	{
		*pitem = pq->front->item;
		pq->n_items--;

		return true;
	}
}
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void (*func)(Item item));