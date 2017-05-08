
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int n, k;

	scanf( "%d %d", &n, &k );

	int ans = -inf;
	while( n-- )
	{
		int t, f;
		scanf( "%d %d", &f, &t );

		if( t > k )
			ans = max( f - t + k, ans );
		else
			ans = max( f, ans );
	}

	printf( "%d\n", ans );

	return 0;
}

