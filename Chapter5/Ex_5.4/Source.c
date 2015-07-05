#include <stdio.h>
#define MAX 100
typedef int bool;
#define true 1
#define false 0

int strend(char *str1, char *str2)
{
	char *temp= str2;
	bool equal = false;
	while (*str1 != 0)
	{
		if (*str2 != 0 && *str1 == *str2)
		{
			str2++;
			equal = true;
		}
		else
		{
			str2 = temp;
			equal = false;
		}
		str1++;		
	}
	return equal;
}

int main()
{
	char string[] = "qweasdzxc";
	char s1[] = "zxc";
	char s2[] = "qwe";
	char s3[] = "asd";
	printf("%s\n", strend(string, s1) ? "true" : "false");
	printf("%s\n", strend(string, s2) ? "true" : "false");
	printf("%s\n", strend(string, s3) ? "true" : "false");
	getchar();
	return 0;
}