// Selection Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void printArray(int arr[], int size);

int main()
{
	int arr[] = { 63, 21, 20, 10, 33 };
	
	printf("sizeof(arr): %d \n", sizeof(arr));
	printArray(arr, sizeof arr / sizeof(int));

	return 0;
}

void printArray(int arr[], int size)
{
	for (int element = 0; element < size; ++element)
	{
		printf("%d ", arr[element]);
	}
	printf("\n");
}