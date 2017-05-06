
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
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;

	int c256 = min( k2, min( k5, k6 ) );

	k2 -= c256;
	k5 -= c256;
	k6 -= c256;

	int c32 = min( k3, k2 );

	cout << 256*c256 + 32*c32 << endl;

	return 0;
}

