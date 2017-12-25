
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n;
	cin >> n;

	while( n-- )
	{
		ull a, b;
		cin >> a >> b;

		ull ans = 0;

		for( int i = 0; i < 31; ++i )
		{
			if( a&(1<<i) )
			{
				int x = a+(1<<i) - a&((1<<i)-1);
				if( x > b )
					ans |= (1<<i);
			}
		}

		cout << ans << endl;
	}

	return 0;
}

