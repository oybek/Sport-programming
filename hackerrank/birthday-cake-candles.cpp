
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define n_max 100001

int n;
int h[n_max];

int main()
{
	cin >> n;
	for( int i = 0; i < n; ++i )
	{
		cin >> h[i];
	}

	sort( h, h+n );

	cout << count( h, h+n, h[n-1] ) << endl;

	return 0;
}


