
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

class mate
{
	public:
		int m, s;

		bool operator> ( const mate& a ) const
		{
			return m > a.m;
		}
};

int n, d;
vector<mate> a;

int main()
{
	//
	scanf( "%d%d", &n, &d );
	a.resize( n );
	for( int i = 0; i < n; ++i )
		scanf( "%d%d", &(a[i].m), &(a[i].s) );

	//
	sort( all(a) );
	int ans = 0;
	for( int i = 0; i < n; i = j )
	{
		int t = a[i].s;
		int j = i+1;
		for( ; j < n && abs( a[i]-a[j] ) <= d; ++j )
		{
			t += a[j].s;
		}
		ans = max( ans, t );
	}

	//
	printf( "%d", ans );

	return 0;
}

