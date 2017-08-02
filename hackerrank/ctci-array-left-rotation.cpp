
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define n_max 100001

int n, d;
int a[ n_max ];

int main()
{
	scanf( "%d%d", &n, &d );
	for( int i = 0; i < n; ++i )
		scanf( "%d", a+i );

	for( int i = d%n, t = n; t--; )
	{
		printf( "%d ", a[ i ] );
		if( ++i == n )
			i = 0;
	}

	return 0;
}

