#include <stdio.h>

//#define FW_JETSON

int input_int();
int main()
{

#ifdef FW_JETSON
	int num1 = 0, num2 = 0, sum = 0;

	printf("Input two integers\n");

	while (1)
	{
		if (scanf("%d%d", &num1, &num2) == 2) break;
		else
		{
			printf("Please input two integers. Try again.\n");
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	sum = num1 + num2;

	printf("%d plus %d = %d\n", num1, num2, sum);
#else // FW_JETSON
	float    won = 0.0f;
	float dollar = 0.0f;

	printf("Input Won\n");

	while (1)
	{
		if (scanf("%f", &won) == 1)
		{
			break;
		}
		else
		{
			printf("Please input an integer. Try again.\n");
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	
	dollar = 0.00084f * won;
	printf("%f won is %.6f dollar", won, dollar);

#endif // FW_JETSON
	return 0;
}
