
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define N_MAX 100001

int N, P;
vector< int > graph[ N_MAX ];
bitset< N_MAX > visited;
vector< int > component;

int dfs( int cur )
{
	if( visited[ cur ] )
		return 0;

	visited[ cur ] = 1;

	int s = 1;
	for( int i = 0; i < graph[ cur ].size(); ++i )
		s += dfs( graph[ cur ][ i ] );

	return s;
}

int main()
{
	cin >> N >> P;
	while( P-- )
	{
		int a, b;
		cin >> a >> b;

		graph[ a ].push_back( b );
		graph[ b ].push_back( a );
	}

	component.reserve( N_MAX );
	for( int i = 0; i < N; ++i )
	{
		int component_size = dfs( i );

		if( component_size > 0 )
			component.push_back( component_size );
	}

	ll s = (
		sqr( accumulate( all(component), 0ll ) )
		- accumulate( all(component), 0ll, []( ll a, int b ) { return a + sqr(b); } )
	) / 2;

	cout << s << endl;

	return 0;
}

