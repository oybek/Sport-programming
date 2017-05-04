
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
	int n, k;
	cin >> n >> k;

	int i = 1;
	for( ; 240 - k - 5*i*(i+1)/2 >= 0; ++i )
	{
	}

	cout << min( i-1, n ) << endl;

	return 0;
}

