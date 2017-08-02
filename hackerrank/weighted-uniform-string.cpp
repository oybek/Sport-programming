
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define max_val 100001*26

bitset< max_val > yes;

int main()
{
	string s; s.reserve( 100001 );
	int n;

	cin >> s >> n;

	int l = 0;
	char prev = -1;
	for( char c : s )
	{
		if( c == prev )
			++l;
		else
			l = 1;

		yes.set( l*(c-'a'+1) );
		prev = c;
	}

	while( n-- )
	{
		int x;
		cin >> x;
		if( x >= max_val )
			cout << "No" << endl;
		else
			cout << ( yes[ x ] ? "Yes" : "No" ) << endl;
	}

	return 0;
}

