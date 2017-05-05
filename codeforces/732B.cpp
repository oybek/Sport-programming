
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
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for( int& x : a )
		cin >> x;

	int dop = 0;

	for( int i = 0; i+1 < a.size(); ++i )
	{
		int diff = k - a[ i ] - a[ i+1 ];
		if( diff > 0 )
		{
			dop += diff;
			a[ i+1 ] += diff;
		}
	}

	cout << dop << endl;
	for( int x : a )
		cout << x << ' ';
	cout << endl;

	return 0;
}

