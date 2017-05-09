
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define n_max 100000

int n,
	a[n_max],
	dp[n_max];

int main()
{
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i )
		scanf( "%d", a+i );

	dp[0] = 1;
	for( int i = 1; i < n; ++i )
		if( a[i] > a[i-1] )
			dp[i] = dp[i-1]+1;
		else
			dp[i] = 1;

	printf( "%d\n", *max_element( dp, dp+n ) );

	return 0;
}

