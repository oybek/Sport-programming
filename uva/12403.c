
#include <stdio.h>

int main()
{
	int tt, t;
	register int price = 0;
	char s[ 8 ];

	scanf("%d", &tt);
	while (tt--)
	{
		scanf("%s", s);
		switch (s[0])
		{
			case 'd':
				scanf("%d", &t);
				price += t;
				break;

			case 'r':
				printf("%d\n", price);
				break;
		}
	}

	return 0;
}

