#include <stdio.h>
#define MAX 100

void strcat(char *s1, char *s2)
{
	while (*s1 != '\0')
		s1++;	
	while (*s1++ = *s2++);
	return;
}

int main()
{
	char concatString[MAX] = { 0 };
	char str1[] = "Hello ";
	char str2[] = "world";
	strcat(concatString, str1);
	strcat(concatString, str2);
	printf(concatString);
	getchar();
	return 0;
}