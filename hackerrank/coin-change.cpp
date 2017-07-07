
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define m_max 51
#define n_max 251

int n, m;
int c[ m_max ];
double dp[ n_max ];

int main() {

	//
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < m; ++i ) {
		scanf( "%d", c+i );
	}

	//
	dp[ 0 ] = 1;
	for( int i = 0; i < m; ++i ) {
		for( int j = c[i]; j <= n; ++j ) {
			dp[ j ] = dp[ j ] + dp[ j-c[i] ];
		}
	}

	//
	printf( "%.0F\n", dp[n] );

	return 0;
}

