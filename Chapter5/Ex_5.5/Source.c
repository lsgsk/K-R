#include <stdio.h>
#define MAX 100

void strncpy(char *s, char *t, int n)
{
	int i = 0;
	while ((i++ < n) && (*s++ = *t++));
}

void strcat(char *s1, char *s2, int n)
{
	while (*s1 != '\0')
		s1++;
	int i = 0;
	while ((i++ < n) && (*s1++ = *s2++));
}


int strcmp(char *s1, char *s2, int n)
{
	int i = 0;
	for (; (i < n) && (*s1 == *s2); s1++, s2++, i++)
	{
		if (*s1 == '\0')
			return 0;
	}
	return *s1 - *s2 == 0 ? 0 : *s1 - *s2 > 0 ? 1 :-1;	
}

int main()
{
	char resultString[MAX] = { 0 };
	char s1[] = "qwe";
	char s2[] = "asdzxc";
	strncpy(resultString, s1, 50);
	printf("%s\n",resultString);
	strcat(resultString, s2, 3);
	printf("%s\n", resultString);
	printf("%d\n", strcmp(resultString, s2, 2));
	printf("%d\n", strcmp(resultString, s1, 2));
	getchar();
	return 0;
}