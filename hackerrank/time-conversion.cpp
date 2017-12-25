
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

	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));
	int ss =stoi(s.substr(6, 2));

	if( s[ s.size()-2 ] == 'P' )
		h = ( h == 12 ? 12 : h+12 );
	else
		h = ( h == 12 ? 0 : h );

	cout	<< setfill('0') << setw(2) << h << ':'
			<< setfill('0') << setw(2) << m << ':'
			<< setfill('0') << setw(2) << ss;

	return 0;
}

