#include <stdio.h>

int main()
{
	int number;

	int flag = scanf("%d", &number);

	// minimum 127 levels of nestings

	if (number > 5)
	{
		if (number < 10)
			printf("Larger than 5 smaller than 10\n");
		else
			printf("Larger than 10\n");
	}
	else
		printf("Less than or equal to 5");

	// Compilers ignore indenting

	return 0;
}