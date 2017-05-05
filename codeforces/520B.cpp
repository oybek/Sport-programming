
/* Use <F5> to compile & run program
 * file.in will be redirected to stdin
 * in file.out you'll get program stdout
 */

#include <algorithm>
#include <bitset>
#include <cassert> #include <climits>
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

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define SIZE 30001
int ans[ SIZE ];

int main()
{
	int n, m;
	cin >> n >> m;

	fill( ans, ans+SIZE, -1 );

	ans[ n ] = 0;

	queue<int> Q;
	Q.push( n );

	while( !Q.empty() )
	{
		int t = Q.front(); Q.pop();

		if( t == m )
		{
			cout << ans[ t ] << endl;
			return 0;
		}

		if( t-1 >= 0 && ans[ t-1 ] == -1 )
		{
			ans[ t-1 ] = ans[ t ] + 1;
			Q.push( t-1 );
		}

		if( 2*t <= 2*m && ans[ 2*t ] == -1 )
		{
			ans[ 2*t ] = ans[ t ] + 1;
			Q.push( 2*t );
		}
	}

	return 0;
}

