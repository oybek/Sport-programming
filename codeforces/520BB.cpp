
/* Use <F5> to compile & run program
 * file.in will be redirected to stdin
 * in file.out you'll get program stdout
 */

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

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()
#define pow2(x) (1<<x)

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define m_max 10001

int dp[ 2*m_max ];

int main()
{
	int n, m;
	cin >> n >> m;

	dp[ n ] = 0;
	for( int i = 1; n-i >= 0; ++i )
		dp[ n-i ] = i;

	for( int i = 1; pow2(i) * n <= 2*m; ++i )
		dp[ pow2(i)*n ] = i;

	for( int i = 1; pow2(i) * n <= 2*m; ++i )
	{
		for( int j = pow2(i) * n - 1; j > pow2(i-1)*n; --j )
		{
			if( j%2 )
				dp[ j ] = dp[ j+1 ]+1;
			else
				dp[ j ] = min( dp[ j+1 ]+1, dp[ j/2 ]+1 );
		}
	}

	cout << dp[ m ] << endl;

	return 0;
}

