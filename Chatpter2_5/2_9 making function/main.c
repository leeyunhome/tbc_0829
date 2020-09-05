#include <stdio.h>
#include <stdlib.h>
//#include <>

#define FW_SUPPORT
#define _Generi

void say_name(void);
void say_hello(void);
int main()
{
	int i = 0;

	i = 1;

	say_hello();
	/*int flag = printf("Hello, World!\n");
	printf("Hello, World!\n");
	printf("Hello, World!\n");
	printf("Hello, World!\n");
	printf("Hello, World!\n");
	printf("flag = %i\n", flag);*/

	return 0;
}
void say_hello(void)
{
	printf("Hello, World!\n");
	atexit(say_name);

	return;
}
void say_name(void)
{
	printf("Neuezeal!\n");
}