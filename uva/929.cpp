
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIDE_MAX 1000

#define temp false
#define perm true

int N, M;
int G[ SIDE_MAX ][ SIDE_MAX ];
int dist[ SIDE_MAX ][ SIDE_MAX ];
bool sign[ SIDE_MAX ][ SIDE_MAX ];

int get_minpath_len() {
	int i, j;
	pair<int, int> p;
	pair<int, int> min[2];

	for ( i = 0; i < N; ++i )
		for ( j = 0; j < M; ++j ) {
			dist[ i ][ j ] = numeric_limits<int>::max();
			sign[ i ][ j ] = temp;
		}
	dist[ 0 ][ 0 ] = G[ 0 ][ 0 ];
	sign[ 0 ][ 0 ] = perm;

	p = make_pair(0, 0);

	{
	}

	return 0;
}

int main() {

	return 0;
}

