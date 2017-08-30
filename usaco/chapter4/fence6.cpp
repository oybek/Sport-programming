
/*
ID: aybek.h2
PROG: fence6
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

#define inf 1000000009

#define N_MAX 101

struct edge
{
	int v, w;

	edge( int av, int aw )
		: v(av), w(aw)
	{}

	bool operator< ( const edge& a ) const
	{
		return !( w < a.w );
	}
};


unordered_map< bitset<N_MAX>, int > vertex;

int N = 0;
int G[ N_MAX ][ N_MAX ];

void construct_graph()
{
	int edge_num;
	cin >> edge_num;

	while( edge_num-- )
	{
		int edge_i;
		int w;
		int n1;
		int n2;
		int t;

		bitset< N_MAX > a;
		bitset< N_MAX > b;

		cin	>> edge_i
			>> w
			>> n1
			>> n2;

		a.set( edge_i );
		for( int i = 0; i < n1; ++i )
		{
			cin >> t;
			a.set(t);
		}

		b.set( edge_i );
		for( int i = 0; i < n2; ++i )
		{
			cin >> t;
			b.set(t);
		}

		if( vertex.find(a) == vertex.end() )
			vertex[ a ] = N++;

		if( vertex.find(b) == vertex.end() )
			vertex[ b ] = N++;

		G[ vertex[a] ][ vertex[b] ] = w;
		G[ vertex[b] ][ vertex[a] ] = w;
	}
}

int ans = inf;

bitset< N_MAX > was;
vector<int> path;

int get_path_len()
{
	int len = 0;
	for( int i = 0; i+1 < path.size(); ++i )
		len += G[ path[i] ][ path[i+1] ];
	len += G[ path[ path.size()-1 ] ][ 0 ];
	return len;
}

void print_path()
{
	for( int i = 0; i < path.size(); ++i )
	{
		cout << path[i] << ' ';
	}
	cout << endl;
}

void dfs( int cur )
{
	if( path.size() > 2 )
	{
		ans = min( ans, get_path_len() );
#ifdef LOCAL
		cout << ans << endl;
		print_path();
#endif
	}

	for( int i = 0; i < N; ++i )
	{
		// no edge
		if( G[cur][i] == inf )
			continue;

		if( was[i] )
			continue;

		was[ i ] = 1;
		path.push_back( i );

		dfs( i );

		was[ i ] = 0;
		path.pop_back();
	}
}

int main()
{
#ifndef LOCAL
	freopen( "fence6.in", "rt", stdin );
	freopen( "fence6.out", "wt", stdout );
#endif

	for( int i = 0; i < N_MAX; ++i )
		for( int j = 0; j < N_MAX; ++j )
			G[i][j] = inf;

	construct_graph();

#ifdef LOCAL
	for( int i = 0; i < N; ++i )
	{
		for( int j = 0; j < N; ++j )
		{
			if( G[i][j] == inf )
				cout << setw(4) << "inf";
			else
				cout << setw(4) << G[i][j];
		}
		cout << endl;
	}
#endif

	for( int i = 0; i < N; ++i )
	{
		path.clear();

		was[i] = 1;
		path.push_back( i );

		dfs( i );

		path.pop_back();
	}

	cout << ans << endl;

	return 0;
}

