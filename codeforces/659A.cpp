
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
	int n, a, b;
	cin >> n >> a >> b;

	if( b < 0 )
	{
		b = -b;
		while( b-- )
		{
			if( --a < 1 )
				a = n;
		}
	}
	else
	{
		while( b-- )
		{
			if( ++a > n )
				a = 1;
		}
	}

	cout << a;

	return 0;
}

