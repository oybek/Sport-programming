
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
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

#define a_size 10001
int a[a_size];

int main()
{
	int dn, dm, z;

	scanf( "%d%d%d", &dn, &dm, &z );

	for( int n = dn; n <= z; n += dn )
		++a[n];

	for( int m = dm; m <= z; m += dm )
		++a[m];

	printf( "%ld\n", count( a, a+a_size, 2 ) );

	return 0;
}

