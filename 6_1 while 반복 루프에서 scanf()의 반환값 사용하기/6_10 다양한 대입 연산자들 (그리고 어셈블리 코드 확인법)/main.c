#include <stdio.h>

int main()
{
	/*
		+=, -=, *=, /=, %=
	*/

	int i = 1024;

	i = i + 10;
	i += 10;

	i %= 4;

	i = i * (1 + 2);
	i *= 1 + 2;
	i *= (1 + 2); // Check precedence

	for (int i = 0; i < 10; i += 2)
		;

	return 0;
}