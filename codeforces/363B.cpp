
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define n_max 150002

int n, k, h[n_max], s[n_max];

int main()
{
	scanf( "%d%d", &n, &k );
	for( int i = 1; i <= n; ++i )
		scanf( "%d", h+i );

	s[1] = h[1];
	for( int i = 2; i <= n; ++i )
		s[i] = s[i-1]+h[i];

	int ans = 1;
	for( int i = 2; i+k-1 <= n; ++i )
	{
		if( s[i+k-1]-s[i-1] < s[ans+k-1]-s[ans-1] )
			ans = i;
	}
	printf( "%d\n", ans );

	return 0;
}

