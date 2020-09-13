#include <stdio.h>

int main()
{
	int secret_code = 337;
	int guess = 0;

	//printf("Enter secret code : ");
	//while (scanf("%d", &guess) == 1)
	//{
	//	if (guess == secret_code)
	//	{
	//		printf("Good!\n");
	//		return;
	//	}
	//	printf("Enter secret code : ");
	//}

	do
	{
		printf("Enter secret code : ");
		scanf("%d", &guess);
	} 
	while (guess != secret_code);

	printf("Good!\n");

	return 0;
}