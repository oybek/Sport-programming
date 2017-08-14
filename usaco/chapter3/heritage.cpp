
/*
ID: aybek.h2
PROG: heritage
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

string in;
string pre;
string ans;

void post( string in, string pre )
{
	if( in.size() == 0 )
		return;

	int i = in.find( pre[0] );

	post( in.substr( 0, i ), pre.substr( 1 ) );
	post( in.substr( i+1 ), pre.substr( i+1 ) );

	ans.push_back( pre[0] );
}

int main()
{
#ifndef LOCAL
	freopen( "heritage.in", "rt", stdin );
	freopen( "heritage.out", "wt", stdout );
#endif

	cin >> in >> pre;
	ans.reserve( in.size() );

	post( in, pre );
	cout << ans << endl;

	return 0;
}

