
/*
ID: aybek.h2
PROG: butter
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001
#define P_MAX 801

struct edge
{
	int v, w;

	edge( int av, int aw )
		: v(av), w(aw)
	{}

	bool operator< ( const edge& a ) const
	{
		return w > a.w;
	}
};

int N, P, C;
int cown[ P_MAX ]; // number of cows in pasture i
vector< edge > G[ P_MAX ];
int dist[ P_MAX ];

void dijkstra( int src )
{
	priority_queue< edge > Q;

	for( int i = 1; i <= P; ++i )
	{
		dist[ i ] = INF;
	}
	dist[ src ] = 0;

	Q.push( edge( src, dist[src] ) );

	while( !Q.empty() )
	{
		edge cur = Q.top(); Q.pop();
		if( cur.w > dist[cur.v] )
		{
			continue;
		}

		for( int i = 0; i < G[ cur.v ].size(); ++i )
		{
			edge next = G[cur.v][i];
			if( dist[cur.v] + next.w < dist[next.v] )
			{
				dist[next.v] = dist[cur.v] + next.w;
				Q.push( edge(next.v, dist[next.v]) );
			}
		}
	}
}

int main()
{
#ifndef LOCAL
	freopen( "butter.in", "rt", stdin );
	freopen( "butter.out", "wt", stdout );
#endif

	//
	cin >> N >> P >> C;
	for( int i = 0; i < N; ++i )
	{
		int t;
		cin >> t;
		cown[ t ]++;
	}
	for( int i = 0; i < C; ++i )
	{
		int x, y, w;
		cin >> x >> y >> w;

		G[ x ].push_back( edge( y, w ) );
		G[ y ].push_back( edge( x, w ) );
	}

	//
	int ans = INF;
	for( int i = 1; i <= P; ++i )
	{
		if( cown[i] <= 0 )
			continue;

		dijkstra(i);

		int total_dist = 0;
		for( int j = 1; j <= P; ++j )
		{
			total_dist += cown[j]*dist[j];
		}

		ans = min( ans, total_dist );
	}

	cout << ans << endl;

	return 0;
}

