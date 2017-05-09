
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

	vector<int> a( n );
	for( int& x : a )
		scanf( "%d", &x );

	sort( all(a) );

	int ans = 0;
	i64 sum = 0;
	for( int x : a )
	{
		if( x >= sum )
		{
			++ans;
			sum += x;
		}
	}
	printf( "%d\n", ans );

	return 0;
}

