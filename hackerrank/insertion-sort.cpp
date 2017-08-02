
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define N_max 100001

int T;
int N;
int a[ N_max ];

int main()
{
	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d", &N );
		for( int i = 0; i < N; ++i )
			scanf( "%d", a+i );

		for( int i = 0; i < N; ++i )
		sort( a, a+N );

		ull ans = 0;
		for( int i = 0; i < N; ++i ) {
			ans += max( 0, a[i].second-i );
		}

		printf( "%llu\n", ans );
	}

	return 0;
}

