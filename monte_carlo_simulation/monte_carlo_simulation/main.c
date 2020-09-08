#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double getRandomNumber(const double min, const double max);
int main()
{
	srand((unsigned int)time(NULL));
	for (int count = 0; count < 12; ++count)
	{
		printf("%f\n", getRandomNumber(-0.5, 0.7));
	}

	return 0;
}
double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min) * temp;

	return temp;
}