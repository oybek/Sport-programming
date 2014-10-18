
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct tree_node {
	vector<int> child;
	vector<int> parent;
};

#define MAX_N 101

tree_node G[ MAX_N ];
bool sign[ MAX_N ];
int N;

void dfs( vector<int> & nodes, int cur )
{
	for ( int i = 0; i < (int) G[ cur ].child.size(); ++i )
		if ( !sign[ G[ cur ].child[ i ] ] )
			dfs( nodes, G[ cur ].child[ i ] );

	bool is_leaf = true;
	for ( int i = 0; i < (int) G[ cur ].child.size(); ++i)
		if ( !sign[ G[ cur ].child[ i ] ] ) {
			is_leaf = false;
			break;
		}

	if ( is_leaf ) {
		sign[ cur ] = true;
		nodes.push_back( cur );
	}
}

int find_greatest( int cur )
{
	for ( int i = 0; i < (int) G[ cur ].parent.size(); ++i )
		return find_greatest( G[ cur ].parent[ i ] );
	return cur;
}

int main()
{
	int i, t;
	vector<int> nodes;

	cin >> N;
	for ( i = 1; i <= N; ++i ) {
		for ( ; ; ) {
			cin >> t;
			if ( t == 0 )
				break;
			G[ i ].child.push_back( t );
			G[ t ].parent.push_back( i );
		}
	}

	for ( i = 1; i <= N; ++i ) {
		if ( !sign[ i ] )
			dfs( nodes, find_greatest(i) );
	}

	for ( i = nodes.size()-1; i > 0; --i )
		cout << nodes[ i ] << ' ';
	cout << nodes[ 0 ] << endl;

	return 0;
}

