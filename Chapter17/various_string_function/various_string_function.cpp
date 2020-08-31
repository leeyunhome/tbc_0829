// various_string_function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctype.h> // toupper(), tolower()

void ToUpper(char* c);
void ToLower(char* c);
void UpdateString(char* str, int(__cdecl* pf)(int));

int main()
{
	char str[] = "Hello, World";

	void (*pf)(char*);

	pf = ToUpper;	// Name of a function is a pointer.
	// pf = &ToUpper;	// Acceptable
	// pf = ToUpper(str); // Not acceptible in c

	//printf("Input a string and press Enter.\n");
	//if (scanf("%[^\n]%*c", str) != 1)
	//{
	//	printf("ERROR: Wrong input. Terminating");
	//	exit(1);
	//}
	(*pf)(str); //ToUpper(str);
	//pf(str);//K&R X, ANSI OK

	printf("ToUpper %s\n", str);

	pf = ToLower;

	(*pf)(str); //ToUpper(str);

	printf("ToLower %s\n", str);

	/*
		passing function pointers to functions
	*/

	UpdateString(str, toupper);

	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);

	printf("ToLower %s\n", str);

	//Note: __cdecl is function calling convention

	return 0;
}

void ToUpper(char* str)
{
	while (*str != NULL)
	{
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}
void UpdateString(char* str, int(__cdecl* pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}