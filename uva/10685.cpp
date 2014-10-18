
#include <cmath>
#include <vector>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, M; /* vertex and edge numbers */

#define MAX_VERTEX_NUM 5000

bool color[ MAX_VERTEX_NUM ];
vector< vector<int> > G;
unordered_map<string, int> id;

/* returns maximal path */
void dfs(int cur, const int c)
{
	int i;

	for ( i = 0; i < G[ cur ].size(); ++i )
		if ( !color[ G[cur][i] ] ) {
			color[ G[cur][i] ] = c;
			dfs( G[cur][i], c);
		}
}

int main() {
	int i, max_deep;
	string s1, s2;
	G.reserve( MAX_VERTEX_NUM );

	while ( 1 ) {
		G.clear();
		id.clear();
		max_deep = 0;

		cin >> N >> M;
		if ( !N && !M )
			break;

		G.resize( N );
		for ( i = 0; i < N; ++i ) {
			cin >> s1;
			id.insert( make_pair(s1, i) );
		}

		while ( M-- ) {
			cin >> s1 >> s2;

			G[ id[s1] ].push_back( id[s2] );
			G[ id[s2] ].push_back( id[s1] );
		}

		for ( i = 0; i < N; ++i ) {
			fill(color, color + N, 0);
			color[ i ] = i+1;
			max_deep = max( max_deep, dfs( i, i+1 ) );
		}

		cout << max_deep << endl;
	}

	return 0;
}

