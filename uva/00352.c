
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_N 25

int N;
char a[ MAX_N ][ MAX_N ];

/* deletes segment of binary ones
 * which belongs to one war eagle */
void deleteSegment(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return;
	if (a[ x ][ y ] == '0')
		return;

	a[ x ][ y ] = '0';

	deleteSegment(x-1, y-1);
	deleteSegment(x-1, y);
	deleteSegment(x-1, y+1);

	deleteSegment(x, y-1);
	deleteSegment(x, y+1);

	deleteSegment(x+1, y-1);
	deleteSegment(x+1, y);
	deleteSegment(x+1, y+1);
}

int main()
{
	FILE * fin = stdin; /*fopen("Bumble.in", "r");*/
	FILE * fout = stdout; /*fopen("Bumble.out", "w");*/

	int i, j, n, in;

	for ( in = 1; fscanf(fin, "%d", &N) != EOF; ++in )
	{
		for ( i = 0; i < N; ++i )
			fscanf(fin, "%s", a[ i ]);

		n = 0;
		for ( i = 0; i < N; ++i )
		for ( j = 0; j < N; ++j )
			if ( a[ i ][ j ] == '1' ) {
				deleteSegment(i, j);
				++n;
			}
		fprintf(fout, "Image number %d contains %d war eagles.\n", in, n); 
	}

	return 0;
}

