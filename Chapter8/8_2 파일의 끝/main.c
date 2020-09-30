#include <stdio.h>

int main()
{
	int c;

	/*while ((c = getchar()) != EOF)
		putchar(c);*/

	// stream
	while (1)
	{
		c = getchar();
		printf("%d\n", c);
		if (c == EOF)
			break;
	}

	return 0;
}