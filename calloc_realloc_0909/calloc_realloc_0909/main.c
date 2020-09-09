#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 10;

	int* ptr = NULL;
	//ptr = (int*)malloc(sizeof(int) * n);
	ptr = (int*)calloc(n, sizeof(int));
	if (ptr == NULL)
	{
		printf("ERROR: malloc() failed.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");

	/*
		realloc() KNK p. 422
	*/

	for (int i = 0; i < n; ++i)
	{
		ptr[i] = i + 1;
	}

	n = 20;

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));
	//ptr = (int*)realloc(ptr, n * sizeof(int));
	//if (ptr == NULL)
	//{
	//	printf("ERROR: malloc() failed.\n");
	//	exit(EXIT_FAILURE);
	//}
	printf("%p %p\n", ptr, ptr2);

	printf("%d\n", ptr[0]);
	if (ptr2 == NULL)
	{
		printf("ERROR: malloc() failed.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ptr = NULL;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ptr2[i]);
	}
	printf("\n");

	free(ptr2);

	return 0;
}