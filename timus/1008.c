
/*
http://acm.timus.ru/problem.aspx?space=1&num=1008
*/

#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define sheet_side 10+1

#define sqr(n) (n)*(n)

char sheet[ sheet_side ][ sheet_side ];

void sheet_show( void ) {
	int i, j;
	for ( i = 1; i < sheet_side; ++i ) {
		for ( j = 1; j < sheet_side; ++j )
			printf("%d", sheet[i][j]);
		printf("\n");
	}
}

void bfs( int x, int y ) {
	queue<pair<int, int> > Q;
}

int main() {
	int pixn, x, y, x1 = 0, y1 = 0;

	memset(sheet, 0, sqr(sheet_side));
	scanf("%d", &pixn);
	while ( pixn-- ) {
		scanf("%d%d", &x, &y);
		sheet[ x ][ y ] = 1;

		if ( !x1 && !y1 )
			x1 = x, y1 = y;
	}
	sheet_show();

	return 0;
}

