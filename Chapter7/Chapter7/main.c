#include <stdio.h>

int main()
{
	int num;

	printf("Input a positive integer : ");
	int flag = scanf("%d", &num);

	//if (num % 2 == 0)
	//	printf("%d is even number.\n", num);
	//else // if (number % 2 != 0)
	//	printf("%d is odd number.\n", num);

	printf("%d is %s number.\n", num, ((num % 2) ? "odd" : "even"));

	return 0;
}