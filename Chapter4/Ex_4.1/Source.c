#include <stdio.h>
#define MAXLINE 100
char pattern[] = "qwe";

int strrindex(char source[], char searchfor[])
{
	int i, j, k; int found = -1;
	for (i = 0; source[i] != '\0'; i++)
	{
		for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++);
		if (k > 0 && searchfor[k] == '\0')
		{
			found = i;
		}
	}
	return found;
}

int main()
{
	char line[] = "jqweaetqwr4qrqwezdh ejga qwe";
	int rightIndex = strrindex(line, pattern);
	printf("Index %d",  rightIndex);
	getchar();
	return 0;
}