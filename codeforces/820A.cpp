
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int c, v0, v1, a, l;
	scanf( "%d%d%d%d%d", &c, &v0, &v1, &a, &l );

	bool f = true;

	int ans = 1;
	for(; c > 0; ++ans )
	{
		if( !f )
			c += l;

		c -= min( v0 + ans*a, v1 );
		if( c <= 0 )
		{
			printf( "%d\n", ans );
			return 0;
		}

		f = false;
	}

	return 0;
}

