#include <stdio.h>

int main()
{
	int num, sum = 0;
	int status;

	printf("Enter an integer (q to quit) : ");
	status = scanf("%d", &num);

	while (status == 1/*scanf("%d", &num) == 1*/)
	{
		sum = sum + num;

		printf("Enter next integer (q to quit) : ");
		status = scanf("%d", &num);
	}

	printf("Sum = %d\n", sum);

	return 0;
}