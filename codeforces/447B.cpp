
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

char s[ 1001 ];
int k;
int w[ 256 ];

int main()
{
	//
	scanf( "%s%d", s, &k );
	for( int i = 'a'; i <= 'z'; ++i )
	{
		scanf( "%d", w+i );
	}
	int s_size = strlen( s );

	//
	ll ans = 0;
	for( int i = 0; i < s_size; ++i )
	{
		ans += w[ s[i] ] * (i+1);
	}

	int w_max = *max_element( w+'a', w+'z'+1 );
	for( int i = s_size; i < s_size+k; ++i )
	{
		ans += w_max * (i+1);
	}

	printf( "%I64d\n", ans );
	return 0;
}

