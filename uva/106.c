
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int gcd(int a, int b) {
	int c;
	for ( ; a != 0; ) {
		c = a; a = b%a; b = c;
	}
	return b;
}

#define MEM_SIZE 1000000

int main()
{
	int N, i, a, b, x, y, z;
	char mem[ MEM_SIZE ];

	for ( ; scanf( "%d", &N ) != EOF; )
	{
		memset(mem, 0, N);
		a = b = 0;

		for ( i = 1; 1; ++i )
		{
			x = i*3, y = i*4, z = i*5;
			if (z > N)
				break;

			mem[ x ] = mem[ y ] = mem[ z ] = 1;
			printf("gcd(%d, %d, %d) = %d\n", x, y, z, gcd(x, gcd(y, z)));
			if ( gcd(x, gcd(y, z)) == 1 )
				++a;

		}

		for ( i = 1; i <= N; ++i )
		{
			b += !mem[ i ];
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}

