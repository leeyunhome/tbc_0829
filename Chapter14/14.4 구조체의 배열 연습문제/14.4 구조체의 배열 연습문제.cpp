// 14.4 구조체의 배열 연습문제.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define TMAX 50
#define NMAX 50
#define MAX 3

struct Book
{
	char title[TMAX];
	char author[NMAX];
	float price;
};

int main()
{
	struct Book book[MAX] = { 0, };

	
	for (int i = 0; i < MAX; ++i)
	{
		printf("Input a book title or press [Enter] to stop.\n>>");
		if (scanf("%s", &book[i].title) != 1)
		{
			printf("No book to show.\n");
			break;
		}
		printf("Input the author.\n");
		scanf("%s", &book[i].author);
		printf("Input the price.\n");
		scanf("%f", &book[i].price);
	}

	printf("The list of books:\n");
	for (int i = 0; i < MAX; ++i)
	{
		printf("%s, %s, %lf.\n", book[i].title,
			book[i].author, book[i].price);
	}

	return 0;
}

