#include <stdio.h>

#define SIZE 5

int main()
{
	/* example */
	int numbers[SIZE] = { 0, };
	int sum = 0;
	float average = 0.0f;

	for (int itr = 0; itr < SIZE; ++itr)
	{
		printf("Enter %d numbers : ", SIZE);
		int flag = scanf("%d", &numbers[itr]);
	}
	
	for (int itr = 0; itr < SIZE; ++itr)
	{
		sum += numbers[itr];
	}

	//printf("Sum = %d\n", sum);

	// average
	average = (float)sum / (float)SIZE;

	printf("Avg = %.2f\n", average);

	/* Motivation */
	//int i1 = 0;
	//int i2 = 1;
	//int i3 = 2;
	//// ...

	//printf("%d\n", i1);
	//printf("%d\n", i2);
	//printf("%d\n", i3);
	//// ...

	//int my_arr[SIZE];

	//// prepare for array data
	//for (int i = 0; i < SIZE; ++i)//index
	//{
	//	my_arr[i] = i * i;
	//	//1 + 2; // dummy
	//}

	//// print array data
	//for (int i = 0; i < SIZE; ++i)
	//	printf("%d ", my_arr[i]);

	//// TODO: try debugger

	return 0;
}