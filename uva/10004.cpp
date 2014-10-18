
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_G_SIZE 200

#define for_(t, i, a, b) \
	for (t i = (a); i != (b); ++i)

int N, M;
bool finished, bicolorable;
int color[ MAX_G_SIZE ];
vector<int> G[ MAX_G_SIZE ];

void dfs(int cur, int col) {
	color[ cur ] = col;
	/*for ( int i = 0; i < (int) G[ cur ].size(); ++i )*/
	for_(size_t, i, 0, G[ cur ].size())
		if ( color[ G[ cur ][i] ] == -1 ) {
			dfs(G[ cur ][i], !col);
			if ( finished )
				return;
		} else
		if ( color[ G[ cur ][i] ] == col) {
			bicolorable = false;
			finished = true;
			return;
		}
}

int main() {
	int i, j;

	while ( 1 ) {
		cin >> N;
		cin >> M;

		if ( !N )
			break;

		fill(color, color + N, -1);

		for ( i = 0; i < N; ++i )
			G[ i ].resize(0);

		while ( M-- ) {
			cin >> i >> j;
			G[ i ].push_back(j);
			G[ j ].push_back(i);
		}

		bicolorable = true;
		dfs(0, 0);
		if ( bicolorable ) {
			cout << "BICOLORABLE.\n";
		} else {
			cout << "NOT BICOLORABLE.\n";
		}
	}

	return 0;
}

