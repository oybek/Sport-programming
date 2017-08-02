
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n;
int t;
vector<int> a;
vector<int> s;

int main()
{
	cin >> n >> t;
	a.resize( n );
	for( auto& x : a )
	{
		cin >> x;
	}


	s.resize( n );
	s[ 0 ] = a[ 0 ];
	for( int i = 1; i < s.size(); ++i )
	{
		s[ i ] = s[ i-1 ] + a[ i ];
	}

	int ans = 0;
	for( int i = 0; i < s.size(); ++i )
	{
		int j = upper_bound( s.begin()+i
			, s.end()
			, ans
			, [](int a, int b) { return a-s[i]+a[i] < b-s[i]+a[i]; } );
	}

	return 0;
}

