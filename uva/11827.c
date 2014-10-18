
#include <stdio.h>

int num[ 100 ];

int gcd( register int a, register int b ) {
	register int c;
	while ( a != 0 ) {
		c = a; a = b%a; b = c;
	}
	return b;
}

int main() {
	register int c, n, i, j, num_size, max_gcd, t_gcd;

	while ( (c = getchar()) != '\n' );
	num_size = n = 0;
	while ( (c = getchar()) != EOF ) {
		switch ( c ) {
			case ' ': case '\t': {
				if ( n != 0 ) {
					num[ num_size++ ] = n;
					n = 0;
				}
				break;
			}

			case '\n': {
				num[ num_size++ ] = n;

				max_gcd = 1;
				for ( i = 0; i < num_size; ++i )
					for ( j = i + 1; j < num_size; ++j ) {
						t_gcd = gcd( num[i], num[j] );
						if ( t_gcd > max_gcd )
							max_gcd = t_gcd;
					}
				printf("%d\n", max_gcd);
				num_size = n = 0;
				break;
			}

			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9': {
				n *= 10;
				n += c-'0';
				break;
			}
		}
	}

	return 0;
}

