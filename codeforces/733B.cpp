
#include <bits/stdc++.h>

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

	vector<int> l( n );
	vector<int> r( n );

	for( int i = 0; i < n; ++i )
		scanf( "%d %d", &(l[i]), &(r[i]) );

	int ls = accumulate( all(l), 0 );
	int rs = accumulate( all(r), 0 );

	int b = abs( ls-rs );
	int ans = -1;
	for( int i = 0; i < n; ++i )
	{
		int cb = abs( (ls-l[i]+r[i]) - (rs-r[i]+l[i]) );
		if( cb > b )
		{
			ans = i;
			b = cb;
		}
	}

	printf( "%d\n", ans+1 );

	return 0;
}

