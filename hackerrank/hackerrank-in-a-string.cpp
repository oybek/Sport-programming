
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void check( const string& s )
{
	const string ss = "hackerrank";

	int j = 0;
	for( int i = 0; i < s.size(); ++i )
	{
		if( s[ i ] == ss[ j ] )
		{
			if( ++j == ss.size() )
			{
				cout << "YES" << endl;
				return;
			}
		}
	}

	cout << "NO" << endl;
	return;
}

int main()
{
	int q;
	cin >> q;

	while( q-- )
	{
		string s;
		cin >> s;

		check( s );
	}

	return 0;
}

