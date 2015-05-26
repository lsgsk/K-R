#include <stdio.h>
#include <limits.h>

void GetChar()
{
	printf("Get all char \n");
	char c = 0;
	do
	{
		printf("%i ", c);
		c++;
	} while (c != 0);
	printf("\n");
}

void GetShort()
{
	printf("Get all shart \n");
	short s = 0;
	do
	{
		printf("%i", s);
		s++;
	} while (s != 0);
	printf("\n");
}

int main()
{	
	GetChar();
	//GetShort();
	getchar();
	return 0;
}