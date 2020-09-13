#include <stdio.h>

int compute_power(int base, int exp);

int main()
{
	int base = 0;
	int exp = 0;
	int flag = 0;
	int result = 0;


	while ((flag = scanf("%d %d", &base, &exp) == 2))
	{
		//result = 1;

		//for (int itr = 0; itr < exp; ++itr)
		//{
		//	//result *= base;
		//}
		result = compute_power(base, exp);

		printf("Result = %d\n", result);
	}
	


	return 0;
}

int compute_power(int base, int exp)
{
	int result = 1;
	int itr = 0;
	for (itr = 0; itr < exp; ++itr)
	{
		result *= base;
	}
	return result;
}
