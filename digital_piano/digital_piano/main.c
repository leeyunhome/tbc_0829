#include <stdio.h>
#include <Windows.h>
#include "MyHeader.h"

#define NUM_KEYS 4

char key_list[] = { 'a', 's', 'd', 'f' };
float frequency_list[] = { 261.626 , 293.665, 329.628, 349.228 };

float getFrequencyFromKey(char key);
void playSound(void);

int main()
{
	while (1)
	{
		playSound();
	}

	return 0;
}
void playSound(void)
{
	char ch = 0;

	ch = getch();
	Beep(getFrequencyFromKey(ch), 500);

	//for (int idx = 0; idx < NUM_KEYS; ++idx)
	//{
	//	if (key_list[idx] == ch)
	//	{
	//		Beep(frequency_list[idx], 500);
	//	}
	//}
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

	return;
}
float getFrequencyFromKey(char key)
{
	for (int idx = 0; idx < NUM_KEYS; ++idx)
	{
		if (key_list[idx] == key)
		{
			return frequency_list[idx];
		}
	}

	return 0.0f;
}

