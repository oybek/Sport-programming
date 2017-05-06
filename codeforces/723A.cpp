
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
#define SQR(x) ((x)*(x))

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int x[ 3 ];
	cin >> x[ 0 ] >> x[ 1 ] >> x[ 2 ];
	sort( x, x+3 );
	cout << ( x[ 1 ] - x[ 0 ] + x[ 2 ] - x[ 1 ] ) << endl;

	return 0;
}

