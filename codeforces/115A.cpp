
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define n_max 2001

int main()
{
	int n;
	scanf( "%d", &n );

	vector<int> p( n );
	for( int& x : p )
	{
		scanf( "%d", &x );
		if( x != -1 )
			--x;
	}

	int ans = 0;
	for( int i = 0; i < n; ++i )
	{
		int j = p[i];
		int t = 1;
		for( ; j != -1; j = p[j] )
			++t;

		ans = max( t, ans );
	}

	printf( "%d\n", ans );

	return 0;
}

