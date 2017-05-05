
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

#define m_max 100

int main()
{
	int n, m, count = 0;
	bitset<m_max> a;

	cin >> n >> m;
	while( n-- )
	{
		int sz;
		cin >> sz;
		while( sz-- )
		{
			int t;
			cin >> t;
			a[ t ] = 1;
		}
	}

	cout << ( a.count() == m ? "YES" : "NO" );

	return 0;
}

