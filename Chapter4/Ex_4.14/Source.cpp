#include <stdio.h>
#define SWAP(t, x, y) {t z=x;x=y;y=z;}

int main()
{
	int x = 5, y = 9;
	SWAP(int, x, y);
	printf("%d - %d", x,y);
	getchar();
	return 0;
}