// 14.23_typedef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

/*

*/

char char3[3] = { 'A', 'B', 'C' };

char(*complicated_function1())[3] // Function Returns Pointer To Char[3]
{
	return &char3;	// Returns a pointer to char[3]
}

typedef char(*FRPTC3())[3];	// Function Returns Pointer To Char[3]
typedef char(*(*PTFRPTC3)())[3];

char(*(*fptr1)())[3] = complicated_function1;

FRPTC3* fptr2 = complicated_function1;
PTFRPTC3 fptr3 = complicated_function1;

/* Use typedef to make declarations simpler */

typedef char c3[3];

c3* complicated_function2()
{
	return &char3;// Returns a pointer to char[3]
}

int main()
{

	return 0;
}
