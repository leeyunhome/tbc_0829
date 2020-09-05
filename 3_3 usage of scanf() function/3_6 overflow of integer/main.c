#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	unsigned int u_max = 0 - 1;
	signed int i_min = INT_MAX + 3;
	// 0000 - 1 = 1111

	//printf("%u", u_max);

	// i to binary representation
	char buffer[33];
	_itoa(i_min, buffer, 2);

	// print decimal and binary
	printf("decimal: %u\n", i_min);
	printf("binary: %s\n", buffer);

	//unsigned int i = 0b11111111111111111111111111111111;
	//unsigned int u = UINT_MAX;

	//unsigned int u_max = UINT_MAX;
	//unsigned int u_min = 0;
	//signed int i_max = INT_MAX;
	//signed int i_min = INT_MIN;

	//printf("max of uint = %u\n", u_max);
	//printf("min of uint = %u\n", u_min);
	//printf("max of int = %d\n", i_max);
	//printf("min of int = %d\n", i_min);

	//int a = printf("%u\n", sizeof(unsigned int));
	//printf("%u", sizeof(i));
	//printf("%d", a);

	return 0;
}