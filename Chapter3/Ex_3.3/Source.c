#include <stdio.h>
#define MAX 100

void expend(char s1[], char s2[]);

int main()
{
	char str1[] = "qefea-dk";
	char str2[] = "a-z";
	char str3[] = "a-b-c";
	char str4[] = "a-z0-9";
	char str5[] = "-a-z";
	char str6[] = "f-b-f";
	char strresult[MAX];
	expend(str1, strresult);
	printf("%s => %s\n", str1, strresult);
	expend(str2, strresult);
	printf("%s => %s\n", str2, strresult);
	expend(str3, strresult);
	printf("%s => %s\n", str3, strresult);
	expend(str4, strresult);
	printf("%s => %s\n", str4, strresult);
	expend(str5, strresult);
	printf("%s => %s\n", str5, strresult);
	expend(str6, strresult);
	printf("%s => %s\n", str6, strresult);
	getchar();
	return 0;
}

void expend(char s1[], char s2[])
{
	int i = 0; int j = 0;
	while (s1[i] != 0)
	{
		if (s1[i] == '-' && i != 0 && s1[i + 1] != 0)
		{
			int ex = s1[i - 1] + 1;
			while (ex < s1[i + 1])
			{
				s2[j++] = ex++;
			}
			i++;
		}
		else
		{
			s2[j++] = s1[i++];
		}
	}
	s2[j] = 0;
}