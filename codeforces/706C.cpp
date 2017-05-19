
#include <bits/stdc++.h>

#define inf (1ll<<62)
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define n_max 100001

int n;
int c[ n_max ];
string s[ n_max ];
i64 dp[ n_max ][ 2 ];

int main()
{
	//
	scanf( "%d", &n );

	for( int i = 0; i < n; ++i )
	{
		scanf( "%d", c+i );
	}

	for( int i = 0; i < n; ++i )
	{
		char t[ n_max ];
		scanf( "%s", t );
		s[ i ] = string( t );
	}

	//
	dp[ 0 ][ 0 ] = 0;
	dp[ 0 ][ 1 ] = c[ 0 ];

	for( int i = 1; i < n; ++i )
	{
#define r(s) string( s.rbegin(), s.rend() )
		if( s[ i-1 ] <= s[ i ] )
		{
			if( r( s[ i-1 ] ) <= s[ i ] )
			{
				dp[ i ][ 0 ] = min( dp[ i-1 ][ 0 ], dp[ i-1 ][ 1 ] );
			}
			else
			{
				dp[ i ][ 0 ] = dp[ i-1 ][ 0 ];
			}
		}
		else
		{
			if( r( s[ i-1 ] ) <= s[ i ] )
			{
				dp[ i ][ 0 ] = dp[ i-1 ][ 1 ];
			}
			else
			{
				dp[ i ][ 0 ] = inf;
			}
		}


		if( s[ i-1 ] <= r( s[ i ] ) )
		{
			if( r( s[ i-1 ] ) <= r( s[ i ] ) )
			{
				dp[ i ][ 1 ] = min( dp[ i-1 ][ 1 ] + c[ i ], dp[ i-1 ][ 0 ] + c[ i ] );
			}
			else
			{
				dp[ i ][ 1 ] = dp[ i-1 ][ 0 ] + c[ i ];
			}
		}
		else
		{
			if( r( s[ i-1 ] ) <= r( s[ i ] ) )
			{
				dp[ i ][ 1 ] = dp[ i-1 ][ 1 ] + c[ i ];
			}
			else
			{
				dp[ i ][ 1 ] = inf;
			}
		}

#undef r

		if( dp[ i ][ 0 ] == inf && dp[ i ][ 1 ] == inf )
		{
			printf( "-1\n" );
			return 0;
		}
	}

	//
	printf( "%lld\n", min( dp[ n-1 ][ 0 ], dp[ n-1 ][ 1 ] ) );
	return 0;
}

