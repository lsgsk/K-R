#include <stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
		{
			high = mid - 1;
		}
		else if (x > v[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;	
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && v[mid] != x)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
		{
			high = mid - 1;
		}
		else if (x > v[mid])
		{
			low = mid + 1;
		}
	}
	return v[mid] == x ? mid : -1;
}

int main()
{	
	int arr[] = { 2, 4, 5, 8, 12, 15, 20, 21, 25, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", binsearch(21, arr, n));
	printf("%d\n", binsearch2(21, arr, n));
	getchar();	
	return 0;
}
