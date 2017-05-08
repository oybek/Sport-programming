
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

	string s; s.reserve( 1001 );
	for( int i = 1; s.size() <= n; ++i )
		s += to_string( i );

	printf( "%c", s[n-1] );

	return 0;
}

