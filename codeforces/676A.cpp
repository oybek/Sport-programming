
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
	int n;
	scanf( "%d", &n );

	vector<int> a( n );
	for( int i = 0; i < n; ++i )
		scanf( "%d", &(a[i]) );

	int imax = max_element(all(a)) - a.begin();
	int imin = min_element(all(a)) - a.begin();

	printf( "%d\n", max( max(imax-0, n-1-imax), max(imin-0, n-1-imin) ) );

	return 0;
}

