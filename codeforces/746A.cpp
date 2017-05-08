
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int a, b, c;
	scanf( "%d%d%d", &a, &b, &c );
	int t = min( a, min( b/2, c/4 ) );
	printf( "%d", t + 2*t + 4*t );

	return 0;
}

