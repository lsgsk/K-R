#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower = -100,
		upper = 300,
		step = 20;

	celsius = lower;
	printf("Convert celsius to  fahr\n");
	while (celsius <= upper)
	{
		fahr = (celsius / 5.0 * 9.0) + 32.0;
		printf("%6.1f %3.0f \n", celsius, fahr);
		celsius += step;
	}
	getchar();
	return 0;
}