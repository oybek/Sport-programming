
#include <stdio.h>

#define MAXN 10 ## 000 ## 001
#define PRIMEN 700 ## 000

#define NOT 1
#define YES 0

#define PRIME(n) is_prime[ (n) ] == YES

int primesn;
int primes[ PRIMEN ];
unsigned char is_prime[ MAXN ];

void gen_primes( register int n )
{
	register int i, j;

	for ( i = 0; i < n; ++i )
		is_prime[i] = 0;

	is_prime[0] = is_prime[1] = NOT;

	for ( i = 2; i*i <= n; ++i )
		if ( !is_prime[ i ] )
			for ( j = i*i; j <= n; j += i)
				is_prime[ j ] = NOT;

	primesn = 0;
	for ( i = 2; i <= n; ++i )
		if ( is_prime[ i ] == YES )
			primes[ primesn++ ] = i;
}

int main()
{
	gen_primes( MAXN );

	int n, found;
	char s[ 1000 ];
	register int i, j, k, m;

	while ( scanf("%s", s) != EOF )
	{
		if ( s[0] == '-' ) n = 0;
		else sscanf(s, "%d", &n);

		found = 0;
		for ( i = 0; (i < primesn) && (primes[i] < n); ++i )
		for ( j = i; (j < primesn) && (primes[j] < n); ++j )
		for ( k = j; (k < primesn) && (primes[k] < n); ++k )
		{
			m = n - primes[i] - primes[j] - primes[k];

			if ( (m > 0) && (is_prime[m] == YES) )
			{
				found = 1;
				printf("%d %d %d %d\n", primes[i], primes[j], primes[k], m);
				i = j = primesn; /* in order to break all loops */
				break;
			}
		}

		if ( found == 0 )
			printf("Impossible\n");
	}


	return 0;
}

