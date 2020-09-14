#include <stdio.h>
#include <ctype.h>	// isalpha() and more

/*
	Reference link

*/

int main()
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (islower(ch))
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);

		//for (int i = '0'; i <= '9'; ++i)
		if (isdigit(ch) != 0)
			ch = '*';

		putchar(ch);
	}

	putchar(ch);

	return 0;
}