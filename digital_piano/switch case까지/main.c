#include <stdio.h>
#include <stdbool.h>

int main()
{
	for (int i = 0; i < 3; ++i)
	{
		// do something
		printf("Inner loop %d\n", i);
	}

	while (1)
	{
		char c = getch();

		if (c == 'a') continue;

		putch(c);

		if (c == 'x') break;
	}
	return 0;
}