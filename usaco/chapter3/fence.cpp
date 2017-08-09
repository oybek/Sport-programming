
/*
ID: aybek.h2
PROG: fence
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define N_MAX 501

int M, N;
int G[N_MAX][N_MAX];
vector<int> ans;

int odd_vertex_num()
{
	int n = 0;
	for( int i = 1; i <= N; ++i )
	{
		n += accumulate( G[i]+1, G[i]+N+1, 0 )%2;
	}
	return n;
}

void find_circuit( int cur )
{
	for( int i = 1; i <= N; ++i )
	{
		if( G[cur][i] )
		{
			G[cur][i] -= 1;
			G[i][cur] -= 1;
			find_circuit(i);
		}
	}
	ans.push_back( cur );
}

int main()
{
#ifndef LOCAL
	freopen( "fence.in", "rt", stdin );
	freopen( "fence.out", "wt", stdout );
#endif

	//
	ans.reserve( 1025 );

	//
	cin >> M;
	while( M-- )
	{
		int x, y;
		cin >> x >> y;

		N = max( N, max( x, y ) );
		G[x][y] += 1;
		G[y][x] += 1;
	}

#ifdef LOCAL
	cout << "odd vertex num: " << odd_vertex_num() << endl;
#endif

	//
	int ovn = odd_vertex_num();
	assert( (ovn == 2) || (ovn == 0 ) );

	if( ovn == 2 )
	{
		for( int i = 1; i <= N; ++i )
		{
			if( accumulate( G[i]+1, G[i]+N+1, 0 )%2 )
			{
				find_circuit( i );
				break;
			}
		}
	}
	else
	{
		find_circuit( 1 );
	}

	//
	for( int i = ans.size()-1; i >= 0; --i )
		cout << ans[i] << endl;

	return 0;
}

