
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

bool is_good( const string& s, int len )
{
	int i = 0;
	int n = stoi( s.substr(0, len) );
}

int main()
{
	int q;
	cin >> q;
	while( q-- )
	{
		string s;
		cin >> s;

		for( int len = 1; len <= s.size()/2; ++len )
		{
			if( is_good( s, len ) )
			{
				cout << "YES " << s.substr(0, len) << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}

