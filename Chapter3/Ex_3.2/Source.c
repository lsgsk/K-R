#include <stdio.h>
#define MAXARRAY 100

int escape(char s[], char c[]);
int unescape(char s[], char c[]);

int main()
{
	char basestr[] = "qw\teas\ndzxc";
	char escapestr[MAXARRAY];
	char unescapestr[MAXARRAY];

	printf("=> %s\n", basestr);
	escape(basestr, escapestr);
	printf("=> %s\n", escapestr);
	unescape(escapestr, unescapestr);
	printf("=> %s\n", unescapestr);
	getchar();
	return 0;
}


int escape(char s[], char c[])
{
	int i = 0; int j = 0;
	while (s[i])
	{
		switch (s[i])
		{
		case '\n':
			c[j++] = '\\';
			c[j] = 'n';
			break;
		case '\t':
			c[j++] = '\\';
			c[j] = 't';
			break;
		default:
			c[j] = s[i];
			break;
		}
		i++;
		j++;
	}
	c[j] = 0;
}

int unescape(char s[], char c[])
{
	int i = 0; int j = 0;
	while (s[i])
	{
		if (s[i] == '\\')
		{
			i++;
			switch (s[i])
			{
			case 'n':
				c[j++] = '\n';
				i++;
				continue;
			case 't':
				c[j++] = '\t';
				i++;
				continue;
			}
		}
		c[j++] = s[i++];
	}
	c[j] = 0;
}