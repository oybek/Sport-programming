
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

#define INF 1000000001
#define SQR(x) ( (x)*(x) )
#define DIV(a, b) ( (a)/(b) + ( (a)%(b) ? 1 : 0 ) )

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

i64 n, k;

bool is_good( i64 d )
{
	return n/d - k*(k-1)/2 > k-1;
}

int main()
{
	cin >> n >> k;

	if( k == 1 )
	{
		cout << n << endl;
		return 0;
	}

	if( k > DIV( 2*n, k+1 ) )
	{
		cout << "-1" << endl;
		return 0;
	}

	i64 d_max = -1;

	for( i64 d = 1; d*d <= n; ++d )
	{
		if( n % d )
			continue;

		if( is_good( d ) )
			d_max = max( d, d_max );

		if( is_good( n/d ) )
			d_max = max( n/d, d_max );
	}

	if( d_max == -1 )
	{
		cout << "-1\n";
	}
	else
	{
		for( i64 i = 1; i < k; ++i )
			cout << d_max*i << ' ';
		cout << n - d_max * k * ( k-1 ) / 2 << endl;
	}

	return 0;
}

