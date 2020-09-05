#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;

	int flag = scanf("%d", &i);
	if (flag != 1)
	{
		printf("ERROR: Wrong input. Terminating.\n");
		exit(1);
	}

	printf("%d", i);

	return 0;
}