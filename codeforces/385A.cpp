
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int n, c;
	scanf( "%d %d", &n, &c );

	vector<int> x(n);
	for( int& y : x )
		scanf( "%d", &y );

	int ans = 0;
	for( int i = 0; i+1 < x.size(); ++i )
		ans = max( x[i]-x[i+1]-c, ans );

	printf( "%d\n", ans );

	return 0;
}

