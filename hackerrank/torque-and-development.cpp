
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define n_max 100001

ll n;
int m;
int road_cost;
int lib_cost;
vector< int > graph[ n_max ];
bitset< n_max > sign;

// count elements
int dfs( int cur )
{
	if( sign[ cur ] )
	{
		return 0;
	}

	sign.set( cur );

	int s = 1;
	for( int i = 0; i < graph[ cur ].size(); ++i )
	{
		s += dfs( graph[ cur ][ i ] );
	}

	return s;
}

void solve()
{
	cin	>> n
		>> m
		>> lib_cost
		>> road_cost;

	if( lib_cost <= road_cost )
	{
		cout << n * lib_cost << endl;

		while( m-- )
		{
			int a, b;
			cin >> a >> b;
		}
	}
	else
	{
		//
		sign.reset();
		for( int i = 1; i <= n; ++i )
		{
			graph[ i ].resize( 0 );
		}

		//
		while( m-- )
		{
			int a, b;
			cin >> a >> b;
			graph[ a ].push_back( b );
			graph[ b ].push_back( a );
		}

		ll ans = 0;
		for( int node = 1; node <= n; ++node )
		{
			if( !sign[ node ] )
			{
				int node_num = dfs( node );
				ans += road_cost * ( node_num - 1 ) + lib_cost;
			}
		}

		cout << ans << endl;
	}
}

int main()
{
	int q;
	cin >> q;
	while( q-- )
	{
		solve();
	}

	return 0;
}

