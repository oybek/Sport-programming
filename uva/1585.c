
#include <stdio.h>

int tn, ts, t;
char s[100], * c;

int main()
{
	for (scanf("%d", &tn); tn--; )
	{
		scanf("%s", s);

		ts = t = 0;
		for (c = s; *c; ++c)
			ts += (t = (*c == 'O' ? t+1 : 0 ));

		printf("%d\n", ts);
	}

	return 0;
}

