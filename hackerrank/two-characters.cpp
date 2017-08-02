
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int get_length( const string& s, char c1, char c2 )
{
	int cnt = 0;
	char prev = ' ';
	for( char c : s )
	{
		if( c != c1 && c != c2 )
			continue;

		if( prev == c )
			return 0;

		prev = c;
		++cnt;
	}

	if( cnt == 1 )
		return 0;

	return cnt;
}

int main()
{
	string s;
	cin >> s >> s;

	int ans = 0;
	for( char c1 = 'a'; c1 <= 'z'; ++c1 )
		for( char c2 = 'a'; c2 <= 'z'; ++c2 )
			ans = max( ans, get_length( s, c1, c2 ) );

	cout << ans << endl;

	return 0;
}

