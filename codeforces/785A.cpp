
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

int a[ 'Z'+1 ];

int main()
{
	a[ 'T' ] = 4;
	a[ 'C' ] = 6;
	a[ 'O' ] = 8;
	a[ 'D' ] = 12;
	a[ 'I' ] = 20;

	int n;
	int ans = 0;
	cin >> n;
	while( n-- )
	{
		string s;
		cin >> s;

		ans += a[ s[ 0 ] ];
	}

	cout << ans << endl;

	return 0;
}

