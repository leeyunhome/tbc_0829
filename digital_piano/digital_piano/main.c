#include <stdio.h>
#include <Windows.h>

#define NUM_KEYS 3
float frequency_list[] = { 261.626 , 293.665, 329.628 };
float key[] = { 'a', 's', 'd' };
int main()
{
	char ch = 0;

	ch = getchar();

	for (int idx = 0; idx < NUM_KEYS; ++idx)
	{
		if (key[idx] == ch)
		{
			Beep(frequency_list[idx], 500);
		}
	}
	//switch (ch)
	//{
	//case 'a':
	//	Beep(261.626, 500);
	//	break;
	//case 's':
	//	Beep(293.665, 500);
	//	break;
	//case 'd':
	//	Beep(329.628, 500);
	//	break;
	//default:
	//	break;
	//}

	return 0;
}