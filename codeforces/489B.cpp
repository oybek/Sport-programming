
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

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int n, m;

	cin >> n;
	vector<int> a( n );
	for( int& x : a )
		cin >> x;

	cin >> m;
	vector<int> b( m );
	for( int& x : b )
		cin >> x;

	sort( all(a) );
	sort( all(b) );

	int ans = 0;
	for( int i = 0; i < a.size(); ++i )
	{
		for( int j = 0; j < b.size(); ++j )
		{
			if( abs( a[ i ] - b[ j ] ) <= 1 )
			{
				b[ j ] = inf;
				++ans;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}

