#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int getch(void);
void ungetch(int);
int getfloat(float *pn)
{
	int c, sign, next;
	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		int next = getch();
		if (!isdigit(next))
		{
			ungetch(next);
			ungetch(c);
			return 0;
		}
		c = next;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if (c == '.')
	{
		c = getch();
		int dot = 1;
		for (;isdigit(c); c = getch())
		{
			*pn = *pn * 10 + (c - '0');
			dot *= 10;
		}
		*pn /= dot; // все равно, б**ть не верно
	}
	*pn *= sign;	
	if (c != EOF)
		ungetch(c);
	return c;

}

int main()
{
	float array[SIZE];
	for (int i = 0; i < SIZE && getfloat(&array[i]) != EOF; i++);
	getch();
	return 0;
};


#define BUFFERSIZE 100
char buf[BUFFERSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFERSIZE)
		printf("error: too many chars\n");
	else
		buf[bufp++] = c;
}