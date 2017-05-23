
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n;
vector<int> a;

int main()
{
	scanf( "%d", &n );
	a.resize( n );
	for( int& x : a )
		scanf( "%d", &x );

	sort( all(a) );

	for( int i = 0; i+2 < n; ++i )
	{
		if( a[i] < a[i+1]+a[i+2] && a[i+1] < a[i]+a[i+2] && a[i+2] < a[i+1]+a[i] )
		{
			printf( "YES\n" );
			return 0;
		}
	}

	printf( "NO\n" );
	return 0;
}

