#include <stdio.h>
#define MAX 100
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	int number = 0;// -INT_MAX;// -106;
	char str[MAX];
	itob(number, str,2);
	printf("%s", str);
	getchar();
	return 0;
}

void itob(int n, char s[], int b)
{ 
	if (b > 16 || b < 2)
	{
		s = "Incorrect parameters";
		return;
	}
	char template[] = "0123456789ABCDEF";
	int i, sign;
	sign = n;
	i = 0;
	do
	{
		s[i++] = template[abs(n % b)];// + '0';
	} while (n /= b);
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