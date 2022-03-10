#include <stdio.h>

int main (void)
{
	int cnt = 0;
	for (int i = 0; i < 25000; i++)
	{
		for (int j = 0; j < 25000; j++)
		{
			cnt++;
		}
	}
	printf("%d\n", cnt);
}