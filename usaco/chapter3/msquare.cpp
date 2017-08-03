
/*
ID: aybek.h2
PROG: msquare
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

string A( string s )
{
	swap( s[0], s[7] );
	swap( s[1], s[6] );
	swap( s[2], s[5] );
	swap( s[3], s[4] );
	return s;
}

string B( string s )
{
	{
		char c = s[3];
		s[3] = s[2];
		s[2] = s[1];
		s[1] = s[0];
		s[0] = c;
	}

	{
		char c = s[4];
		s[4] = s[5];
		s[5] = s[6];
		s[6] = s[7];
		s[7] = c;
	}

	return s;
}

string C( string s )
{
	char c = s[1];
	s[1] = s[6];
	s[6] = s[5];
	s[5] = s[2];
	s[2] = c;
	return s;
}

map< string, string > sol;

void show( string s )
{
	cout << s.substr(0, 4) << endl;
	cout << s[7] << s[6] << s[5] << s[4] << endl;
}

int main()
{
#ifndef LOCAL
	freopen( "msquare.in", "rt", stdin );
	freopen( "msquare.out", "wt", stdout );
#endif

	//
	queue< pair<string, string> > Q;

	//show( C("12345678") );

	//cout << B(C(C(B(A(C(B("12345678"))))))) << endl;

	//
	Q.push( make_pair( "12345678", "" ) );
	while( !Q.empty() )
	{
		pair<string, string> cur = Q.front(); Q.pop();

		if( sol.find( cur.first ) == sol.end() )
		{
			sol.insert( cur );

			Q.push( make_pair( A(cur.first), cur.second+'A' ) );
			Q.push( make_pair( B(cur.first), cur.second+'B' ) );
			Q.push( make_pair( C(cur.first), cur.second+'C' ) );
		}
	}

	string s;

	{
		int n = 8;
		while( n-- )
		{
			int t;
			cin >> t;
			s.push_back( t+'0' );
		}
	}

	cout << sol[ s ].size() << endl << sol[ s ] << endl;
	//cout << sol[ s ] << endl;
	return 0;
}

