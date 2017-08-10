
/*
ID: aybek.h2
PROG: camelot
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001

#define R_MAX 27
#define C_MAX 31

int R, C;

int knight_bfs[R_MAX][C_MAX];
int king_bfs[R_MAX][C_MAX];

// will there be knight
bool knight[R_MAX][C_MAX];

pair<int, int> king;
vector< pair<int, int> > knight_coord;

template< class T >
void show_board( const T a[][C_MAX], int r, int c )
{
	for( int i = 0; i < r; ++i )
	{
		for( int j = 0; j < c; ++j )
			cout << setw(2) << a[i][j];
		cout << endl;
	}
}

//
void reset_knight()
{
	for( int i = 0; i < R; ++i )
		for( int j = 0; j < C; ++j )
			knight[i][j] = 0;
}

//
void bfs_knight( int x, int y )
{
	for( int i = 0; i < R; ++i )
	{
		for( int j = 0; j < C; ++j )
			knight_bfs[i][j] = INF;
	}

	queue< tuple<int, int, int> > Q;
	Q.push( make_tuple( x, y, 0 ) );

	while( !Q.empty() )
	{
		tuple<int, int, int> cur = Q.front(); Q.pop();

		int x = get<0>(cur);
		int y = get<1>(cur);
		int w = get<2>(cur);

		if( x >= 0 && x < R && y >= 0 && y < C && knight_bfs[x][y] > w )
		{
			knight_bfs[x][y] = w;

			Q.push( make_tuple( x-2, y-1, w+1 ) );
			Q.push( make_tuple( x-2, y+1, w+1 ) );
			Q.push( make_tuple( x+2, y-1, w+1 ) );
			Q.push( make_tuple( x+2, y+1, w+1 ) );

			Q.push( make_tuple( x-1, y-2, w+1 ) );
			Q.push( make_tuple( x-1, y+2, w+1 ) );
			Q.push( make_tuple( x+1, y-2, w+1 ) );
			Q.push( make_tuple( x+1, y+2, w+1 ) );
		}
	}
}

//
void bfs_king( int x, int y )
{
	for( int i = 0; i < R; ++i )
	{
		for( int j = 0; j < C; ++j )
			king_bfs[i][j] = INF;
	}

	queue< tuple<int, int, int> > Q;
	Q.push( make_tuple( x, y, 0 ) );

	while( !Q.empty() )
	{
		tuple<int, int, int> cur = Q.front(); Q.pop();

		int x = get<0>(cur);
		int y = get<1>(cur);
		int w = get<2>(cur);

		if( x >= 0 && x < R && y >= 0 && y < C && king_bfs[x][y] > w )
		{
			king_bfs[x][y] = w;

			Q.push( make_tuple(   x, y-1, w+1 ) );
			Q.push( make_tuple(   x, y+1, w+1 ) );

			Q.push( make_tuple( x-1,   y, w+1 ) );
			Q.push( make_tuple( x+1,   y, w+1 ) );

			Q.push( make_tuple( x-1, y-1, w+1 ) );
			Q.push( make_tuple( x-1, y+1, w+1 ) );
			Q.push( make_tuple( x+1, y-1, w+1 ) );
			Q.push( make_tuple( x+1, y+1, w+1 ) );
		}
	}
}

//
void find_knight_cells()
{
	for( int i = 0; i < knight_coord.size(); ++i )
	{
		int x = knight_coord[i].first;
		int y = knight_coord[i].second;

		while( knight_bfs[x][y] > 0 )
		{
			knight[x][y] = true;

			if( x-1 >= 0 && y-2 >= 0 && knight_bfs[x-1][y-2] == knight_bfs[x][y]-1 ) { x -= 1; y -= 2; }
			if( x-1 >= 0 && y+2 <  C && knight_bfs[x-1][y+2] == knight_bfs[x][y]-1 ) { x -= 1; y += 2; }
			if( x+1  < R && y-2 >= 0 && knight_bfs[x+1][y-2] == knight_bfs[x][y]-1 ) { x += 1; y -= 2; }
			if( x+1  < R && y+2  < C && knight_bfs[x+1][y+2] == knight_bfs[x][y]-1 ) { x += 1; y += 2; }

			if( x-2 >= 0 && y-1 >= 0 && knight_bfs[x-2][y-1] == knight_bfs[x][y]-1 ) { x -= 2; y -= 1; }
			if( x-2 >= 0 && y+1  < C && knight_bfs[x-2][y+1] == knight_bfs[x][y]-1 ) { x -= 2; y += 1; }
			if( x+2  < R && y-1 >= 0 && knight_bfs[x+2][y-1] == knight_bfs[x][y]-1 ) { x += 2; y -= 1; }
			if( x+2  < R && y+1  < C && knight_bfs[x+2][y+1] == knight_bfs[x][y]-1 ) { x += 2; y += 1; }
		}
	}
}

int main()
{
#ifndef LOCAL
	freopen( "camelot.in", "rt", stdin );
	freopen( "camelot.out", "wt", stdout );
#endif

	char c;
	int n;

	cin >> R >> C;
	cin >> c >> n;

	king.first = c-'A';
	king.second = n-1;

	while( cin >> c >> n )
	{
		knight_coord.push_back( make_pair( c-'A', n-1 ) );
	}

	int best = INF;

	bfs_king( king.first, king.second );

	for( int x = 0; x < R; ++x )
	{
		for( int y = 0; y < C; ++y )
		{
			reset_knight();
			bfs_knight( x, y );

			int knights_min = 0;

			// calc total knight moves
			for( int i = 0; i < knight_coord.size(); ++i )
				knights_min += knight_bfs[knight_coord[i].first][knight_coord[i].second];


			// detect cells where at least one knight will be
			knight[x][y] = 1;
			find_knight_cells();

#ifdef LOCAL
			show_board( knight, R, C );
			cout << endl;
#endif


			int king_min = INF;
			for( int i = 0; i < R; ++i )
				for( int j = 0; j < C; ++j )
				{
					if( knight[i][j] )
						king_min = min( king_min, king_bfs[i][j] );
				}

			best = min( best, knights_min+king_min );
		}
	}

	cout << best << endl;

#ifdef LOCAL
	//show_board( king_bfs, R, C );
#endif

	return 0;
}

