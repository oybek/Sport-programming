
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

	vector<int> h( n );
	for( int& x : h )
		scanf( "%d", &x );

	printf( "%d\n", *max_element(all(h)) );

	return 0;
}

