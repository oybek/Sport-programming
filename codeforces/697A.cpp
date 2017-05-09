
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int t, s, x;
	scanf( "%d %d %d", &t, &s, &x );

	if( x < t )
	{
		puts("NO");
	}
	else if( x == t )
	{
		puts("YES");
	}
	else if( x == t+1 )
	{
		puts("NO");
	}
	else
	{
		printf( "%s\n", (x-t)%s == 0 || (x-t)%s == 1 ? "YES" : "NO" );
	}

	return 0;
}

