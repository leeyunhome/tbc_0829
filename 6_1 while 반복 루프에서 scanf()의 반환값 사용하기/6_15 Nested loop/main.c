#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'
#define LAST_CHAR 'L'

int main()
{
	//int r;	// row loop
	//int c;	// character loop
	//for (r = 0; r < NUM_ROWS; ++r)// outer row loop
	//{
	//	for (c = FIRST_CHAR; c <= LAST_CHAR; ++c) // inner character loop
	//		printf("%c ", c);
	//	printf("\n");
	//}

	//int r;	// row loop
	//int c;	// character loop
	//for (r = 0; r < NUM_ROWS; ++r)// outer row loop
	//{
	//	for (c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c) // inner character loop
	//		printf("%c ", c);
	//	printf("\n");
	//}

	//int r;	// row loop
	//int c;	// character loop
	//for (r = FIRST_CHAR; r <= LAST_CHAR; ++r)// outer row loop
	//{
	//	for (c = r; c <= LAST_CHAR; ++c) // inner character loop
	//		printf("%c ", c);
	//	printf("\n");
	//}

	const char last_char = 'L';
	const int num_rows = last_char - FIRST_CHAR + 1;

	int r;	// row loop
	int c;	// character loop

	for (r = 0; r < num_rows; ++r)
	{
		for (c = FIRST_CHAR + r; c < FIRST_CHAR + num_rows; ++c)
			printf("%c ", c);
		printf("\n");
	}

	return 0;
}