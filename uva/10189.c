#include <stdio.h>

#define MAXX 102
#define MAXY 102

int main()
{
	char a[ MAXX ][ MAXY ];

	int lenx, leny;
	int i, j;
	long ind = 0l;

	for (i = 0; i < MAXX; i++)
		for (j = 0; j < MAXY; j++)
			a[i][j] = 0;

	while (1) {
		scanf("%d%d", &lenx, &leny);

		if (!lenx)
			break;
		if (ind)
			printf("\n");
		ind++;

		for (i = 1; i <= lenx; i++)
			scanf("%s", (a[ i ]+1));

		for (i = 1; i <= lenx; i++)
			for (j = 1; j <= leny; j++)
				if (a[i][j] != '*') {
					int n = 0;

					if (a[i-1][j-1] == '*')
						n++;
					if (a[i-1][j] == '*')
						n++;
					if (a[i-1][j+1] == '*')
						n++;
					if (a[i][j-1] == '*')
						n++;
					if (a[i][j+1] == '*')
						n++;
					if (a[i+1][j-1] == '*')
						n++;
					if (a[i+1][j] == '*')
						n++;
					if (a[i+1][j+1] == '*')
						n++;

					a[ i ][ j ] = n;
				}

		printf("Field #%ld:\n", ind);
		for (i = 1; i <= lenx; i++) {
			for (j = 1; j <= leny; j++) {
				if (a[i][j] == '*')
					printf("*");
				else
					printf("%d", a[i][j]);
			}
			printf("\n");
		}

		for (i = 1; i <= lenx; i++)
			for (j = 1; j <= leny; j++)
				a[i][j] = 0;
	}

	return 0;
}

