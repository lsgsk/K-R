#include <stdint.h>
#include <limits.h>
#define MAX 100

void itoa(int n, char s[], int l);
void reverse(char s[]);

int main()
{
	int number = 106;
	char str[MAX];
	itoa(number, str,10);
	printf("%s", str);
	getchar();
	return 0;
}

void itoa(int n, char s[], int l)
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
	for (; i < l; )
	{
		s[i++] = ' ';
	}
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