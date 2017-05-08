
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int t;
	scanf( "%d", &t );

	while( t-- )
	{
		i64 n;
		scanf( "%lld", &n );
		printf( "%lld\n", n*(n+1)/2 - 2*( int(pow( 2, int(log2(n))+1 )-1) ) );
	}

	return 0;
}

