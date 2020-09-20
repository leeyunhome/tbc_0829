#include <stdio.h>
#include <stdbool.h>

int main()
{
	unsigned num, div;
	bool isPrime;	// flag, try bool type

	int flag = scanf("%u", &num);

	/*
		TODO: Check if num is a prime number
		ex) num is 4, try num % 2, num % 3
		ex) num is 5, try num % 2, num % 3 , num % 4
		1과 자기자신 외에는 나눌 수가 없는 숫자
	*/
	
	isPrime = true;
	for (div = 2; div < num; ++div)
	{
		if (num % div == 0)
			isPrime = false;

	}

	if (isPrime)
		printf("%u is a prime number.\n", num);
	else
		printf("%u is not a prime number.\n", num);

	return 0;
}