#include <stdio.h>

int main()
{
	printf("%s\n", "1\a");
	printf("%s\n", "2\f");
	printf("%s\n", "3\r");
	printf("%s\n", "4\v");
	getchar();
	return 0;
}