#include <stdio.h>

int main()
{
	/* open file stream to read */
	FILE* ifp = NULL;

	if (NULL == (ifp = fopen("input.txt", "r")))
	{
		printf("Cannot open file.\n");
		return;
	}

	int start_age = 25;
	int end_age = 120;
	double start_salary = 0.4;
	double salary_increase = 0.03;

	fscanf(ifp, "%d %d %f %f", &start_age, &end_age, &start_salary, &salary_increase);

	double annual_salary = start_salary;
	double income_sum = 0;
	double sum_salary = 0;

	/* open file stream to write */
	FILE* file = NULL;

	if (NULL == (file = fopen("income.txt", "w")))
	{
		printf("Cannot open file.\n");
		return -1;
	}

	for (int age = start_age; age <= 54; age++)
	{
		income_sum += annual_salary * 0.7;
		sum_salary += annual_salary;

		printf("%d %f %f\n", age, annual_salary, income_sum);
		fprintf(file, "%d %f %f\n", age, annual_salary, income_sum);
		
		if (age != 54) 
		{
			annual_salary *= (1.0 + salary_increase);
		}
	}

	annual_salary *= 0.5;

	for (int age = 55; age <= 60; age++)
	{
		income_sum += annual_salary * 0.7;
		sum_salary += annual_salary;

		printf("%d %f %f\n", age, annual_salary, income_sum);
		fprintf(file, "%d %f %f\n", age, annual_salary, income_sum);
	}

	const double salary_average = sum_salary / (double)(60 - start_age + 1);
	
	for (int age = 61; age <= end_age; age++)
	{
		income_sum += salary_average;

		printf("%d %f %f\n", age, salary_average, income_sum);
		fprintf(file, "%d %f %f\n", age, salary_average, income_sum);
	}

	fclose(file);

	return 0;
}