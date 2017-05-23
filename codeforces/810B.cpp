
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define n_max 100001

int n, f;
struct day
{
	int k, l;

	bool operator< ( const day& a ) const
	{
		return min( 2*k, l ) - min( k, l ) > min( 2*a.k, a.l ) - min( a.k, a.l );
	}
} a[ n_max ];

int main()
{
	scanf( "%d %d", &n, &f );
	for( int i = 0; i < n; ++i )
		scanf( "%d %d", &(a[i].k), &(a[i].l) );

	sort( a, a+n );

	i64 ans = 0;
	for( int i = 0; i < f; ++i )
		ans += min( 2*a[i].k, a[i].l );
	for( int i = f; i < n; ++i )
		ans += min( a[i].k, a[i].l );

	printf( "%lld", ans );

	return 0;
}

