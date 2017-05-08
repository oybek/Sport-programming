
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

	vector<pair<int, int> > a( n );
	for( int i = 0; i < n; ++i )
		scanf( "%d %d", &(a[i].first), &(a[i].second) );

	sort( all(a) );

	int ans = a[0].second;
	for( int i = 1; i < n; ++i )
		if( ans > a[i].second )
			ans = a[i].first;
		else
			ans = a[i].second;

	cout << ans << endl;

	return 0;
}

