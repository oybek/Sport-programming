
/*
ID: aybek.h2
PROG: fence6
LANG: C++
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

	return 0;
}

