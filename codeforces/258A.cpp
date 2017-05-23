
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

char s[ 100001 ];

int main()
{
	scanf( "%s", s );

	int s_len = strlen( s );
	for( int i = 0; i < s_len; ++i )
	{
		if( s[ i ] == '0' )
		{
			s[ i ] = 0;
			printf( "%s%s\n", s, s+i+1 );
			return 0;
		}
	}

	s[ s_len-1 ] = 0;
	printf( "%s\n", s );
	return 0;
}

