
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

	if( n < 6 || n%2 )
	{
		printf( "0\n" );
	}
	else
	{
		n /= 2;
		if( n%2 )
		{
			printf( "%d\n", n/2 );
		}
		else
		{
			printf( "%d\n", n/2-1 );
		}
	}

	return 0;
}

