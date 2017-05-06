
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define n_MAX 100

int n, k;
int a[ n_MAX ][ n_MAX ];

void print_solution()
{
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < n; ++j )
			cout << a[ i ][ j ] << ' ';
		cout << endl;
	}
}

int main()
{
	cin >> n >> k;
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < n; ++j )
		{
			int count = 0;
			if( a[ i ][ j ] == 0 && a[ j ][ i ] == 0 )
			{
				count = ( i == j ? 1 : 2 );
			}

			if( count <= k )
			{
				a[ i ][ j ] = a[ j ][ i ] = 1;
				k -= count;
			}
		}
	}

	if( k > 0 )
	{
		cout << "-1\n";
	}
	else
	{
		print_solution();
	}

	return 0;
}

