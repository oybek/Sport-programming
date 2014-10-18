
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

#define MAX_SIDE 821

int a_xsize, a_ysize, maxk = 0;
int a[ MAX_SIDE ][ MAX_SIDE ];

struct state_t {
	int x, y, k;
};

state_t make_state( int x, int y, int k )
{
	state_t tmp;
	tmp.x = x, tmp.y = y, tmp.k = k;
	return tmp;
}

void bfs( int x, int y, int k ) {

	queue<state_t > Q;

	state_t cur;
	Q.push( make_state( x, y, k ) );

	for ( ; !Q.empty(); ) {
		cur = Q.front(); Q.pop();
		a[ cur.x ][ cur.y ] = cur.k;
		maxk = max( cur.k, maxk );

		if ( a[ cur.x-1 ][ cur.y ] == 0 )
			Q.push( make_state( cur.x-1, cur.y, cur.k+1 ) );
		if ( a[ cur.x+1 ][ cur.y ] == 0 )
			Q.push( make_state( cur.x+1, cur.y, cur.k+1 ) );
		if ( a[ cur.x ][ cur.y-1 ] == 0 )
			Q.push( make_state( cur.x, cur.y-1, cur.k+1 ) );
		if ( a[ cur.x ][ cur.y+1 ] == 0 )
			Q.push( make_state( cur.x, cur.y+1, cur.k+1 ) );
	}
}

int main() {
	using namespace std;

	string s;
	cin >> a_ysize >> a_xsize;
	for (int i = 0; i < a_xsize; ++i) {
		cin >> s;
		for (int j = 0; j < a_ysize; ++j) {
			switch (s[j]) {
				case '.': a[i][j] = 0; break;
				case '#': a[i][j] = -1; break;
			}
		}
	}

	for (int i = 0; i < a_xsize; ++i)
		for (int j = 0; j < a_ysize; ++j) {

			if (a[ i ][ j ] == 0 ) {
				int nn = 0;
				nn += a[ i-1 ][ j ] + 1;
				nn += a[ i+1 ][ j ] + 1;
				nn += a[ i ][ j-1 ] + 1;
				nn += a[ i ][ j+1 ] + 1;

				if ( nn == 1 ) {
					bfs( i, j, 1 );
					cout << max( 0, maxk-1 ) << endl;
					return 0;
				}
			}
		}

	cout << 0 << endl;

	return 0;
}

