// Chapter14.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>




int main()
{
	typedef struct complex {
		float real;
		float imag;
	} COMPLEX;	// typedef struct complex COMPLEX

	typedef struct { double width; double height; } rect;// No tag
	rect r1 = { 1.1, 2.2 };
	rect r2 = r1;
	printf("%f %f\n", r2.width, r2.height);

	return 0;
}
