#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++);

	sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	int exp; int k;
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
	}
	
	int exsign = s[i] == '-' ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (exp = 0; isdigit(s[i]); i++)
	{
		exp = exp * 10 + (s[i] - '0');
	}
	double number = sign * val / power;
	for (k = exp; k > 0 ; k--)
	{
		if (exsign == 1)
			number *= 10;
		else
			number /= 10;
	}
	return number;
}

int main()
{
	printf("Our number: %f \n", atof("15.45"));
	printf("Our number: %f \n", atof("-15.45e3"));
	printf("Our number: %f \n", atof("1.45e-4"));
	printf("Our number: %f \n", atof("-1.45e+4"));
	getchar();
	return 0;
}