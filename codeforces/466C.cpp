
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

#define n_max 500001
int a[n_max],
	good[n_max];
i64 cnt[n_max];

int main()
{
	int n;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i )
		scanf( "%d", a+i );

	i64 sum = accumulate( a, a+n, 0ll );

	if( sum%3 )
	{
		printf("0\n");
		return 0;
	}

	i64 sum3 = sum / 3;
	i64 t = 0;
	for( int i = n-1; i >= 0; --i )
	{
		t += a[i];
		if( t == sum3 )
			good[i] = 1;
	}

	cnt[n-1] = good[n-1];
	for( int i = n-2; i >= 0; --i )
		cnt[i] = cnt[i+1] + good[i];

	t = 0;
	i64 ans = 0;
	for( int i = 0; i+1 < n; ++i )
	{
		t += a[i];
		if( t == sum3 )
			ans += cnt[i+2];
	}

	printf("%I64d\n", ans);

	return 0;
}

