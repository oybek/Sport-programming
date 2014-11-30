
#include <stdio.h>

char * s, ss[16];
unsigned int a, b, d;

int main()
{
	while ( gets(ss) != NULL )
	{
		s = ss;

		b = *s-'0';
		while (*++s != ' ')
		{
			b *= 10;
			b += (*s - '0');
		}

		a = *++s-'0';
		while (*++s != '\0')
		{
			a *= 10;
			a += (*s - '0');
		}

		d = a-b;
		printf("%u\n", a/d + (a%d > 0));
	}

	return 0;
}

