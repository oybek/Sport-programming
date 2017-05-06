
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

using namespace std;

#define n_MAX 10

int n, m;
bitset< n_MAX > a[ n_MAX ];

int killNCount( int x, int y )
{
	if( x >= 0 && x < n && y >= 0 && y < m && a[ x ][ y ] )
	{
		a[ x ][ y ] = 0;

		return 1
			+ killNCount( x-1, y-1 )
			+ killNCount( x-1,   y )
			+ killNCount( x-1, y+1 )

			+ killNCount(   x, y-1 )
			+ killNCount(   x, y+1 )

			+ killNCount( x+1, y-1 )
			+ killNCount( x+1,   y )
			+ killNCount( x+1, y+1 );
	}

	return 0;
}

int main()
{
	cin >> n >> m;
	for( int i = 0; i < n; ++i )
	{
		for(int j = 0; j < m; ++j )
		{
			int t;
			cin >> t;
			a[ i ][ j ] = t ? 1 : 0;
		}
	}
	int ans = 0;
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < m; ++j )
			ans = max( ans, killNCount( i, j ) );
	}
	cout << ans;

	return 0;
}

