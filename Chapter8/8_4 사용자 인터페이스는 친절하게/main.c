#include <stdio.h>

int main()
{
	int count = 0;

	while (1)
	{
		printf("Current count is %d. Continue.\n", count);

		int c = getchar();

		if (c == 'n')
			break;
		else if (c == 'y')
		{
			while (getchar() != '\n')
				continue;

			count++;
		}
		else
		{
			printf("Please input y or n\n");
			while (getchar() != '\n')
				continue;
		}
		
	}

	return 0;
}