#include <stdio.h>
#include <ctype.h>
#define MAX 100

void reverse(char s[]);

int getline(char *str, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		*str++ = c;
	if (c == '\n')
	{
		*str++ = c;
	}
	*str++ = '\0';
	return i;
}

int atoi(char *s)
{
	int n = 0, sign;
	while (isspace(*s++));
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	while (isdigit(*s))
	{
		n = 10 * n + (*s - '0');
		s++;
	}
	return sign * n;
}

void itoa(int n, char *s)
{
	int sign = n < 0 ? -1 : 1;
	int i = n < 0 ? 1 : 0;
	do
	{
		*s++ = abs(n % 10) + '0';
		i++;
	} while (n /= 10);
	if (sign < 0)
	{
		*s++ = '-';
	}
	*s = '\0';
	s -= i;
	reverse(s);
}

void getop(char *s)
{
	int i = 0, c, next;
	while ((*s = c = getch()) == ' ' || c == '\t');
	*++s = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	if (c == '-')
	{
		next = getch();
		if (!isdigit(next) && next != '.')
		{
			return c;
		}
		c = next;
	}
	else
	{
		c = getch();
	}
	while (isdigit(*s++ = c))
	{
		c = getch();
	}
	if (c == '.')
	{
		while (isdigit(*s++ = c = getch()));
	}
	*s = '\0';
	if (c != EOF)
		ungetch(c);
}

int strindex(char *s, char *t)
{
	char *p; char *lt = t; 
	int i = 0, k;
	while (*s++)
	{
		p = s; t = lt; k = 0;
		while (*p == *t && *t != '\n')
		{
			p++;
			t++;
			k++;
		}		
		i++;
		if (*t == '\0' && k > 0)
		{
			return i;
		}
	}
	/*for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			return i;
	}*/
	return -1;
}



int main()
{
	char string[MAX] = { 0 };
	//getline(string, MAX); //1
	//itoa(-123, string); printf("%s\n", string); //2
	//printf("%d\n", atoi("+567")); //3
	//getop(string); printf("%s\n", string); //4
	//printf("%d\n", strindex("qweasdzxc", "xcv")); //5
	getchar();
	return 0;
}

void reverse(char s[])
{
	//признано нецелесообразным =)
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}