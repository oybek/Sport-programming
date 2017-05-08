
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define n_max 1002

int n, m;
int a[n_max][n_max],
	lu[n_max][n_max],
	ld[n_max][n_max],
	ru[n_max][n_max],
	rd[n_max][n_max];

#define max4(a, b, c, d) max( max( a, b ), max( c, d ) )

void show( int a[n_max][n_max] )
{
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < m; ++j )
			cout << a[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	//
	scanf("%d %d", &n, &m);
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j )
			scanf("%d", &(a[i][j]));

	//
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j )
		{
			lu[i][j] = max( a[i][j], max( lu[i-1][j], lu[i][j-1] ) );

			ld[n-i+1][j] = max( a[n-i+1][j], max( ld[n-i+2][j], ld[n-i+1][j-1] ) );

			ru[i][m-j+1] = max( a[i][m-j+1], max( ru[i][m-j+2], ru[i-1][m-j+1] ) );

			rd[n-i+1][m-j+1] = max( a[n-i+1][m-j+1], max( rd[n-i+1][m-j+2], rd[n-i+2][m-j+1] ) );
		}

	//
	int ii = 1, jj = 1, tt = inf;
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j )
		{
			int t = max4( lu[i-1][j-1], ld[i+1][j-1], ru[i-1][j+1], rd[i+1][j+1] );
			if( t < tt )
			{
				tt = t;
				ii = i;
				jj = j;
			}
		}

	printf("%d %d", ii, jj );

	return 0;
}

