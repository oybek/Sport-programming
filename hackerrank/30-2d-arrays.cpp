
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

#define SIZE 6

int main() {
    vector< vector<int> > a( SIZE ,vector<int>( SIZE ) );

    for( int a_i = 0; a_i < SIZE; a_i++ )
	{
       for( int a_j = 0; a_j < SIZE; a_j++ )
          cin >> a[ a_i ][ a_j ];
    }

	int ans = -INF;
	for( int i = 1; i+1 < SIZE; ++i )
	{
		for( int j = 1; j+1 < SIZE; ++j )
		{
			ans = max( ans,
					a[ i ][ j ]
					+ a[ i-1 ][ j-1 ]
					+ a[ i-1 ][ j ]
					+ a[ i-1 ][ j+1 ]
					+ a[ i+1 ][ j-1 ]
					+ a[ i+1 ][ j ]
					+ a[ i+1 ][ j+1 ] );
		}
	}

	cout << ans;

	return 0;
}

