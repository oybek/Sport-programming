
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int N;
int k;
vector<int> x;

int main()
{
	cin >> N >> k;

	x.resize( N );
	for( int& n : x )
		cin >> n;

	sort( all( x ) );

	int ans = x[ k-1 ] - x[ 0 ];
	for( int i = 1; i+k-1 < x.size(); ++i )
		ans = min( ans, x[ i+k-1 ] - x[ i ]);

	cout << ans << endl;

	return 0;
}

