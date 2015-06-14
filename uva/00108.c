
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_N 100

#define max(a, b) (a) > (b) ? (a): (b)

int N;
int a[ MAX_N ][ MAX_N ];
int S[ MAX_N ][ MAX_N ];

void initS()
{
	int i, j;

	S[0][0] = a[0][0];
	for (i = 1; i < N; ++i)
		S[ 0 ][ i ] = S[ 0 ][ i-1 ] + a[ 0 ][ i ];

	for (j = 1; j < N; ++j)
		S[ j ][ 0 ] = S[ j-1 ][ 0 ] + a[ j ][ 0 ];

	for (i = 1; i < N; ++i)
	for (j = 1; j < N; ++j)
		S[ i ][ j ] = a[ i ][ j ] + S[ i-1 ][ j ] + S[ i ][ j-1 ] - S[ i-1 ][ j-1 ];
}

int subSum(int x1, int y1, int x2, int y2)
{
	int sum = 0;
	sum += S[ x2 ][ y2 ];

	if ( x1 != 0 )
		sum -= S[ x1-1 ][ y2 ];
	if ( y1 != 0 )
		sum -= S[ x2 ][ y1-1 ];

	if ( x1 != 0 && y1 != 0)
		sum += S[ x1-1 ][ y1-1 ];

	return sum;
}

int main()
{
	int x1, y1, x2, y2;
	scanf("%d", &N);

	for (x1 = 0; x1 < N; ++x1)
	for (y1 = 0; y1 < N; ++y1)
		scanf("%d", &a[ x1 ][ y1 ]);

	initS();

	int max_sum = 0;
	for (x1 = 0; x1 < N; ++x1)
	for (y1 = 0; y1 < N; ++y1)
		for (x2 = x1; x2 < N; ++x2)
		for (y2 = y1; y2 < N; ++y2)
			max_sum = max(subSum(x1, y1, x2, y2), max_sum);

	printf("%d\n", max_sum);

	return 0;
}

