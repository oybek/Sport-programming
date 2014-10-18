
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*
 * OpenBI - Open  Big Integer Library
 */

#define BI_BASE				1 ## 000 ## 000 ## 000
#define BI_BASE_LEN			9
#define BI_BASE_TYPE		long long /* it holds number 999 999 999 */
#define BI_FIRST_DIG_PRINT	"%lld"
#define BI_BASE_PRINT		"%09lld"

#define PLUS	1
#define MINUS	-1

#ifndef BI_MAX_MEM
#define BI_MAX_MEM 10000
#endif

typedef struct bigint
{
	BI_BASE_TYPE dig[ BI_MAX_MEM ];
	int sign;
	int dign;
} bigint;


void init(bigint *);

void assign_int(bigint *, int);
void assign_str(bigint *, const char *);

void assign_sum(bigint * const, const bigint *, const bigint * const);
void assign_sub(bigint * const, const bigint *, bigint *);

void assign_mul(bigint * const, const bigint *, const bigint *);

void assign_mulb(bigint * const, const bigint *, BI_BASE_TYPE);	/* multiples bigint to number < BI_BASE */
void assign_divb(bigint * const, const bigint *, BI_BASE_TYPE);			/* divides bigint to int */

#define cmp(a, b)		_cmp(a, b, 0)
#define cmp_abs(a, b)	_cmp(a, b, 1)

void print(const bigint *);

/* User doesn't use this functions and macroses */

#define swap(a, b)		tmp = a; a = b; b = tmp;
int _cmp(const bigint *, const bigint *, int);
void zero_justify(bigint *);
void shift(bigint *, int);
BI_BASE_TYPE str_to_int(const char *, const char *);


void init(bigint * a)
{
	a->dign = 1;
	a->sign = PLUS;
	a->dig[ 0 ] = 0;
}

void assign(bigint * a, const bigint * b)
{
	if (a == b) return;
	int i;
	a->sign = b->sign;
	a->dign = b->dign;
	for (i = 0; i < a->dign; ++i) {
		a->dig[i] = b->dig[i];
	}
}

void assign_str( bigint * a, const char * s )
{
	int n;
	const char * sbegin, * send;
	sbegin = send = s;

	a->sign = ( *sbegin == '-' ? ++sbegin, MINUS: PLUS );
	for ( ; *send; ++send );

	s = send;
	for ( a->dign = 0; s > sbegin; a->dign++ ) {
		for ( n = 9; n-- && s > sbegin; )
			--s;
		a->dig[ a->dign ] = str_to_int( s, send );
		send = s;
	}
}

void assign_int( bigint * a, int n )
{
	if ( !n ) {
		init( a ); return;
	}

	a->sign = ( n < 0 ? n = -n, MINUS: PLUS );

	for ( a->dign = 0; n > 0; n /= BI_BASE )
		a->dig[ a->dign++ ] = n % BI_BASE;
}

void assign_sum( bigint * const c, const bigint * a, const bigint * b )
{
	int i, cdign;
	const bigint * tmp;
	BI_BASE_TYPE carry, borrow, cdig;

	if ( cmp_abs(a, b) < 0 ) {
		swap(a, b);
	}

	cdign = a->dign;
	carry = borrow = 0;

	if ( a->sign == b->sign ) {
		for ( i = 0; i < a->dign; ++i ) {
			cdig = ( i < b->dign ? b->dig[i]: 0 );
			cdig += a->dig[ i ] + carry;
			carry = cdig / BI_BASE;
			cdig %= BI_BASE;
			c->dig[ i ] = cdig;
		}
		if ( carry > 0 )
			c->dig[ cdign++ ] = carry;
	} else {
		for ( i = 0; i < a->dign; ++i ) {
			cdig = ( i < b->dign ? -( b->dig[ i ] ): 0 );
			cdig += a->dig[ i ] - borrow;
			borrow = 0;
			if ( cdig < 0 )
			{
				cdig += BI_BASE; 
				borrow = 1;
			}
			c->dig[ i ] = cdig;
		}
	}

	c->sign = a->sign;
	c->dign = cdign;
	zero_justify(c);
}

void assign_sub(bigint * const c, const bigint * a, bigint * b)
{
	if (a == b) {
		init(c);
	} else {
		b->sign = - b->sign;
		assign_sum(c, a, b);
		b->sign = - b->sign;
	}
	return;
}

void assign_mul(bigint * const c, const bigint * a, const bigint * b)
{
	int i;
	bigint * const y	= ( bigint* ) malloc(sizeof (bigint)),
		   * const x	= (c == a || c == b ? ( bigint* ) malloc(sizeof (bigint)): c);

	assign(x, c);
	init(x);
	for ( i = b->dign-1; i >= 0; --i ) {
		assign_mulb(y, a, b->dig[i]);
		shift(x, 1);
		assign_sum(x, y, x);
	}
	x->sign = (a->sign != b->sign ? MINUS: PLUS);
	assign(c, x);

	free((void*) y); free((void*) x);
}

void assign_mulb(bigint * const c, const bigint * a, BI_BASE_TYPE b)
{
	if (b >= BI_BASE) {
		fprintf(stderr, "error: assign_mulb: %lld is greater then base\n", b);
		return;
	}
	if ( b == 0 ) {
		init( c );
		return;
	}
	
	int i;
	BI_BASE_TYPE carry = 0;
	c->sign = ((b < 0 && a->sign == MINUS) || (b > 0 && a->sign == PLUS)
			? PLUS
			: MINUS);

	for ( i = 0; i < a->dign; ++i ) {
		carry = a->dig[ i ] * b + carry;
		c->dig[ i ] = carry % BI_BASE;
		carry /= BI_BASE;
	}
	if ( carry > 0 )
		c->dig[ i++ ] = carry;
	c->dign = i;
	zero_justify( c );
}

void assign_divb( bigint * const c, const bigint * a, BI_BASE_TYPE b )
{
	if (b >= BI_BASE) {
		fprintf(stderr, "error: assign_divb: %lld is greater then base\n", b);
		return;
	}
	if ( b == 0 ) {
		fprintf( stderr, "error: assign_divb: divising by zero\n" );
		return;
	}

	int i;
	BI_BASE_TYPE carry = 0, tmp;

	c->sign = ((b < 0 && c->sign == MINUS) || (b > 0 && c->sign == PLUS)
			? PLUS
			: MINUS);

	c->dign = a->dign;
	for ( i = a->dign-1; i >= 0; i-- ) {
		tmp = a->dig[ i ] + carry * BI_BASE;
		c->dig[ i ] = tmp / b;
		carry = tmp % b;
	}
	zero_justify( c );
}

BI_BASE_TYPE modb(const bigint * a, BI_BASE_TYPE b)
{
	if (b >= BI_BASE) {
		fprintf(stderr, "error: assign_mulb: %lld is greater then base\n", b);
		return -1;
	}
	if ( b == 0 ) {
		fprintf(stderr, "error: assign_modb: divising by zero\n");
		return -1;
	}

	int i;
	BI_BASE_TYPE carry = 0;

	for ( i = a->dign-1; i >= 0; i-- ) {
		carry = a->dig[ i ] + carry * BI_BASE;
		carry %= b;
	}
	return carry;
}

int _cmp(const bigint * a, const bigint * b, int ignore_sign)
{
	if (!ignore_sign && a->sign != b->sign)
		return a->sign - b->sign;

	if (a->dign != b->dign)
		return (ignore_sign ? a->dign - b->dign : (a->sign == PLUS ? a->dign - b->dign : b->dign - a->dign));

	int i;
	for ( i = a->dign -1; i > 0 && a->dig[i] == b->dig[i]; --i );

	return a->dig[i]- b->dig[i];
}

void print(const bigint * a)
{
	int i;
	if ( a->sign == MINUS )
		putchar('-');


	i = a->dign-1;
	printf( BI_FIRST_DIG_PRINT, a->dig[ i ] );
	for ( i--; i >= 0; i-- ) {
		printf( BI_BASE_PRINT, a->dig[ i ] );
	}
	printf( "\n" );
}

void shift(bigint * a, int d)
{
	if ( ( d == 0 ) || ( a->dign == 1 && a->dig[ a->dign-1 ] == 0 ) )
		return;

	int i;
	a->dign += d;

	for ( i = a->dign-1; i >= d; --i )
		a->dig[ i ] = a->dig[ i-d ];
	for ( ; i >= 0; --i )
		a->dig[ i ] = 0;
}

void zero_justify(bigint * const c)
{
	for ( ; c->dign > 1 && c->dig[ c->dign-1 ] == 0; c->dign-- );

	if ( c->dign == 1 && c->dig[ c->dign-1 ] == 0 )
		c->sign = PLUS;
}

BI_BASE_TYPE str_to_int(const char * i, const char * j)
{
	BI_BASE_TYPE n;
	for ( n = 0; i < j; i++ ) {
		n *= 10;
		n += ( BI_BASE_TYPE )( *i-'0' );
	}
	return n;
}

int main() {
	int n, i, j;
	bigint m;
	char s[ 10000 ];

	while (scanf("%d", &n) != EOF) {

		for (i = 1; 1; ++i) {

			for (j = 0; j < i; ++j)
				s[ j ] = '1';
			s[ j ] = '\0';

			assign_str(&m, s);

			if (!modb(&m, n)) {
				printf("%d\n", (int) strlen(s));
				break;
			}
		}
	}

	return 0;
}

