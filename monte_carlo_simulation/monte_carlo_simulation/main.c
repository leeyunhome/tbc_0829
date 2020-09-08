#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

double getRandomNumber(const double min, const double max);
bool isInsideCircle(const double x, const double y);
int main()
{
	FILE* file = NULL;
	if ((file = fopen("circle.txt", "w")) == NULL)
	{
		printf("ERROR: Cannot open file.\n");
		exit(1);
	}
	srand((unsigned int)time(NULL));
	for (int count = 0; count < 10000; ++count)
	{
		const double x = getRandomNumber(0, 1);
		const double y = getRandomNumber(0, 1);
		
		if (isInsideCircle(x, y) == true)
		{
			printf("%f, %f\n", x, y);
			fprintf(file, "%f, %f\n", x, y);
		}
	}

	if (fclose(file) != 0)
	{
		printf("ERROR: Cannot close file.\n");
	}

	return 0;
}
double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min) * temp;

	return temp;
}
bool isInsideCircle(const double x, const double y)
{
	// 사각형 안에 정확히 들어가는 원 정의
	const double x_c = 0.5, y_c = 0.5;
	const double radius = 0.5;
	double f = (x - x_c)*(x - x_c) + (y - y_c) * (y - y_c) - radius * radius;
	if (f < 0.0)
	{
		return true;
	}
	else if (f > 0.0)
	{
		return false;
	}
	else
	{
		return true;
	}
}