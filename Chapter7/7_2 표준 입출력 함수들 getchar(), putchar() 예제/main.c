#include <stdio.h>	// getchar(), putchar()

int main()
{
	/*
		1. Introduce getchar(), putchar()
		2. Use while loop to process character sequence
		3. Filter a specific character
		4. Convert numbers to asterisks
		5. Lower characters to Upper characters
	*/

	char ch;

	//ch = (char)getchar();// buffer
	//putchar(ch);

	//while (ch != '\n')// Use '\n' to find the end of a sentence
	while ((ch = (char)getchar()) != '\n')
	{
		if (ch >= '0' && ch <='9')
			ch = '*';
		
		if (ch >= 'a' && ch <= 'z')
			ch -= 'a' - 'A';
		else if (ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';
		//if (ch == 'f' || ch == 'F')
		//{
		//	ch = 'X';
		//}
		/*else if (ch == 'F')
		{
			ch = 'X';
		}*/
		putchar(ch);
	}
	
	putchar(ch);

	return 0;
}