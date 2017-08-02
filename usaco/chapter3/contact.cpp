
/*
ID: aybek.h2
PROG: contact
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN 200001

int A, B, N;
string s;

vector< string > a[ MAX_LEN ];

#ifdef LOCAL
void output_map( map< string, int >& m )
{
	for( auto it : m )
		cout << it.first << ' ' << it.second << endl;
}
#endif

bool cmp( const string& s1, const string& s2 )
{
	if( s1.size() != s2.size() )
		return s1.size() < s2.size();
	else
		return s1 < s2;
}

int main()
{
#ifndef LOCAL
	freopen( "contact.in", "rt", stdin );
	freopen( "contact.out", "wt", stdout );
#endif

	s.reserve( MAX_LEN );

	//
	cin >> A >> B >> N;
	{
		string t; t.reserve( 81 );
		while( cin >> t )
			s.append( t );
	}

	//
	map< string, int > cnt;
	for( int l = A; l <= B; ++l )
	{
		for( int i = 0; i+l <= s.size(); ++i )
			cnt[ s.substr( i, l ) ] += 1;
	}

	//
	for( map< string, int >::iterator it = cnt.begin(); it != cnt.end(); ++it )
	{
		a[ it->second ].push_back( it->first );
	}

	for( int i = MAX_LEN-1; i > 0 && N > 0; --i )
	{
		if( a[ i ].size() > 0 )
		{
			N--;

			sort( a[ i ].begin(), a[ i ].end(), cmp );

			cout << i << endl;

			int online = 0;
			for( int j = 0; j < a[ i ].size(); ++j )
			{
				cout << a[ i ][ j ];

				++online;
				if( online == 6 || j+1 == a[ i ].size() )
				{
					cout << endl;
					online = 0;
				}
				else
					cout << ' ';
			}
		}
	}

	return 0;
}

