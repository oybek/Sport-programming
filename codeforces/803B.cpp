
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

#define n_MAX 200001

int n;
int a[ n_MAX ];
int d[ n_MAX ];

int main()
{
	cin >> n;
	for( int i = 0; i < n; ++i )
	{
		cin >> a[ i ];
		d[ i ] = ( a[ i ] == 0 ? 0 : INF );
	}

	for( int i = 0; i < n; ++i )
	{
		if( a[ i ] == 0 )
		{
			for( int dx = 1; i-dx >= 0 && d[ i-dx ] > dx; ++dx )
				d[ i-dx ] = dx;

			for( int dx = 1; i+dx  < n && d[ i+dx ] > dx; ++dx )
				d[ i+dx ] = dx;
		}
	}

	for( int i = 0; i < n; ++i )
		cout << d[ i ] << ' ';
	cout << endl;

	return 0;
}

