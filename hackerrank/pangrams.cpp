
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	string s;
	getline( cin, s );

	bitset< 'z'+1 > a;
	for( char c : s )
		if( isalpha( c ) )
			a.set( tolower( c ) );

	cout << ( a.count() == 26 ? "pangram" : "not pangram" ) << endl;

	return 0;
}

