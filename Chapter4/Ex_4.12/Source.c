#include <stdint.h>
#include <limits.h>
#include <math.h>
#define MAX 3

void itoa(int numb, char str[]);

int main()
{
	int number = -46106;
	char str[MAX];
	itoa(number, str);
	printf("%s", str);
	getchar();
	return 0;
}	
int itoan(int numb, char str[], int n)
{
	if (numb > 0)
	{
		n = itoan(numb/10, str, n);
		if (n >= MAX || n == -1)
		{			
			return -1;
		}
		str[n++] = abs(numb % 10) + '0';
	}
	return n;
}

void itoa(int numb, char str[])
{
	int n = 0;
	if (numb < 0)
	{
		str[n++] = '-';
		numb *= -1;
	}
	n = itoan(numb, str, n);
	if (n == -1)
	{
		printf("out of index exception\n");
		n = 0;
	}
	str[n] = '\0';
}