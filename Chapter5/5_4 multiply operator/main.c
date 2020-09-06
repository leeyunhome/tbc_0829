#include <stdio.h>

int main()
{
	double seed_money = 0.0;
	double target_money = 0.0;
	double annual_interest = 0.0;

	int year_count = 0;

	printf("Input seed money : ");
	int flag = scanf("%lf", &seed_money);
	if (flag != 1)
	{
		puts("Wrong input. Terminating.\n");
		exit(1);
	}
	printf("Input target money : ");
	flag = scanf("%lf", &target_money);
	if (flag != 1)
	{
		puts("Wrong input. Terminating.\n");
		exit(1);
	}
	printf("Input annual interest (%%) : ");
	flag = scanf("%lf", &annual_interest);
	if (flag != 1)
	{
		puts("Wrong input. Terminating.\n");
		exit(1);
	}

	double fund = seed_money;

	while (fund < target_money)
	{
		fund = fund + fund * annual_interest / 100.0;
		year_count = year_count + 1;
		printf("Year %d, fund %f\n", year_count, fund);
	}

	printf("I takes %dyears\n", year_count);

	return 0;
}