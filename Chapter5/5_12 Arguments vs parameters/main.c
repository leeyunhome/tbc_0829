#include <stdio.h>

void draw(int n);	// ANSI function prototype declaration

int main()
{
	int i = 5;
	char c = '#';	// 35
	float f = 7.1f;

	draw(i);// i��� ������ �ִ� ��ó�� �������� �����δ� ���� �ִ� ��
	draw((int)c);
	draw((int)f);

	/* Arguments vs. Parameters */
	// actual argument, actual parameter -> argument (values)
	// formal argument, formal parameter -> parameter (variables)

	return 0;
}
void draw(int n)
{
	/*for (int count = 0; count < n; count++)
	{
		printf("*");
	}*/
	while (n-- > 0)
		printf("*");
	printf("\n");
}