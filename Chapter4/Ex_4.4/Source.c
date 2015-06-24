#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int getop(char s[]);
void push(double f);
double pop(void);
double peek(void);
void duplicate(void);
void swipe_top_elements(void);
void clear_stack(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero division \n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			{
				double a = pop();
				double b = fmod(a, op2);
				push(b);
			}
			else
				printf("error: zero division \n");
			break;
		case '?':
			peek();
			break;
		case '#':
			duplicate();
			break;
		case '~':
			swipe_top_elements();
			break;
		case '!':
			clear_stack();
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

int sp = 0;
double val[MAXVAL];
void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, cannot push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
		printf("error: stack empty\n");
	return 0.0;
}

double peek(void)
{
	if (sp > 0)
		return val[sp-1];
	else
		printf("error: stack empty\n");
	return 0.0;
}

void duplicate(void)
{
	push(peek());
}

void swipe_top_elements(void)
{
	double tmp1 = pop();
	double tmp2 = pop();
	push(tmp1);
	push(tmp2);
}

void clear_stack(void)
{
	while (sp > 0)
	{
		val[sp--] = 0;
	}
}



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

int getop(char s[])
{
	int i = 0, c, next;
	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';
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
	while (isdigit(s[++i] = c))
	{
		c = getch();
	}
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}