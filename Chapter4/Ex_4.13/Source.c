#include <stdint.h>
#define MAX 100

void reverse(char str[]);

int main()
{
	char str[] = "qwe";
	reverse(str);
	printf("%s", str);
	getchar();
	return 0;
}

int reversen(char str[], int n, int l)
{
	if (str[n] != '\0')
	{
		int ch = str[n];
		n = reversen(str, ++n, l);
		str[l-n--] = ch;
	}
	return n;
}

void reverse(char str[])
{
	int n = 0, l = strlen(str);
	reversen(str, n, l);
}