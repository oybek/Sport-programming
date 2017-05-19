
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

	for( int i = 0; i+1 < a.size(); ++i )
		printf( "%d ", a[i]+a[i+1] );
	printf( "%d\n", *a.rbegin() );

	return 0;
}

