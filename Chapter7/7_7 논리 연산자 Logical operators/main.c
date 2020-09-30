#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>

#define PERIOD '.'

int main()
{
	/* Character counting example */

	//char ch;
	//int count = 0;

	//while ((ch = getchar()) != PERIOD)
	//{
	//	if (ch != '\n' && ch != ' ')
	//		count++;
	//}

	//printf("%d", count);

	/*
		Alternatives in iso646.h

	*/

	/*
		opertor precedence in c
	*/

	//int a = 1, b = 2, c = 3, d = 4;

	//a > b&& b > c || b > d;
	//((a > b) && (b > c)) || (b > d);

	/*
		Short-circuit Evaluation

		- Logical expressions are evaluated from left to right
		- && and || are equence points
	*/

	//int temp = (1 + 2) * (3 + 4);

	//printf("Before : %d\n", temp);

	//if (temp == 0 && (++temp == 1024)) {
	//	// do nothing
	//};

	//printf("After : %d\n", temp);

	return 0;
}