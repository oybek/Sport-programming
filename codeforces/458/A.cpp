
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n;
	vector< int > a;

	cin >> n;
	a.resize(n);
	for( int& x : a )
		cin >> x;

	sort( a.rbegin(), a.rend() );

	for( int x : a )
	{
		int x_sqrt = round( sqrt( x ) );
		if( sqr( x_sqrt )
	}

	return 0;
}

