#include <stdio.h>
#include <limits.h>
#define MAXARRAY 128

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	int number = INT_MIN;// -106;
	printf("%d %d \n", number, abs(number));
	char str[MAXARRAY];
	itoa(number, str);
	printf("%s", str);
	getchar();
	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;
	sign = n;
	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while (n /= 10);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}