#include <stdio.h>

int main()
{
	char fruit_name[40];	// stores only one character.

	printf("What is your favorate frit?\n");

	scanf("%s", fruit_name);	// be careful with &

	printf("You like %s!\n", fruit_name);

	return 0;
}