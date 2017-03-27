
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

class Pos
{
	public:
		int x, y;
		Pos( int x = 0, int y = 0 ) : x( x ), y( y ) {}
		bool operator== ( const Pos& a ) const { return x == a.x && y == a.y; }
		bool operator!= ( const Pos& a ) const { return !operator==( a ); }
};

using namespace std;

int n, m;
int a[ 101 ][ 101 ];

Pos start, finish;

void floodFill( int x, int y, int depth )
{
	if( x < 0 || x >= n || y < 0 || y >= m || a[ x ][ y ] != 0 )
		return;

	a[ x ][ y ] = depth;
	floodFill( x-1, y, depth+1 );
	floodFill( x+1, y, depth+1 );
	floodFill( x, y-1, depth+1 );
	floodFill( x, y+1, depth+1 );
}

int main()
{
	//reading
	int T;
	cin >> T;
	while ( T-- )
	{
		cin >> n >> m;

		for( int i = 0; i < n; ++i )
		{
			string s;
			cin >> s;
			for( int j = 0; j < m; ++j )
			{
				switch( s[ j ] )
				{
					case '*': a[ i ][ j ] = 0; finish = Pos( i, j ); break;
					case 'M': a[ i ][ j ] = 0; start = Pos( i, j ); break;
					case 'X': a[ i ][ j ] =-1; break;
					case '.': a[ i ][ j ] = 0; break;
				}
			}
		}
		int ron_ans;
		cin >> ron_ans;

		floodFill( start.x, start.y, 1 );

		for( int i = 0; i < n; ++i )
		{
			for( int j = 0; j < m; ++j )
			{
				if( a[i][j] == -1 )
					cout << "[]";
				else
					cout << setw(2) << a[i][j];
			}
			cout << endl;
		}

		int ans = 0;
		do {
			if( finish.x-1 >= 0 && a[ finish.x-1 ][ finish.y ] == a[ finish.x ][ finish.y ]-1 )
				--finish.x;
			if( finish.x+1  < n && a[ finish.x+1 ][ finish.y ] == a[ finish.x ][ finish.y ]-1 )
				++finish.x;

			if( finish.y-1 >= 0 && a[ finish.x ][ finish.y-1 ] == a[ finish.x ][ finish.y ]-1 )
				--finish.y;
			if( finish.y+1  < m && a[ finish.x ][ finish.y+1 ] == a[ finish.x ][ finish.y ]-1 )
				++finish.y;

			int t = 0;
			if( finish.x-1 >= 0 && a[ finish.x-1 ][ finish.y ] != -1 ) ++t;
			if( finish.x+1  < n && a[ finish.x+1 ][ finish.y ] != -1 ) ++t;
			if( finish.y-1 >= 0 && a[ finish.x ][ finish.y-1 ] != -1 ) ++t;
			if( finish.y+1  < m && a[ finish.x ][ finish.y+1 ] != -1 ) ++t;
			if( t > 2 )
				++ans;
		} while ( finish != start );

		cout << ans << endl;
		cout << ( ron_ans == ans ? "Impressed" : "Oops!" ) << endl;
	}

	return 0;
}

