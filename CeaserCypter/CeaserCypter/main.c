#include <stdio.h>

#define MAX_LEN 31

int main()
{
	char ch[31] = { 0, 0 };

	scanf("%s", ch);

	for (int i = 0; i < strlen(ch); ++i)
	{
		ch[i] = ch[i] + 3;
		if (ch[i] > 90)
		{
			ch[i] = 65;
		}

	}

	printf("%s\n", ch);
	//char ch;
	//char en;
	//while (1)
	//{
	//	int flag = scanf("%c", &ch);
	//	if (flag != 1)
	//	{
	//		printf("Wrong input.\n");
	//	}

	//	for (int i = 0; i < 3; ++i)
	//	{
	//		en = ch + 3;
	//	}
	//	for (int i = 0; i < 3; ++i)
	//	{
	//		printf("%c", en);
	//	}
	//	printf("\n");

	//	if (ch == '\n')
	//	{
	//		break;
	//	}
	//		
	//}
	//
	//
	//printf("%c", ch);

	return 0;
}