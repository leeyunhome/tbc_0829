#pragma once

#include <stdbool.h>

#define TSIZE 45
#define MAXITEMS 10

struct customer
{
	long arrival_time;
	int processtime;
} customer;

typedef struct customer Item;

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef struct queue
{

};
