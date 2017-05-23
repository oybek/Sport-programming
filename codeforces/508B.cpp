
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	string s;
	cin >> s;

	for( int i = 0; i+1 < s.size(); ++i )
	{
		int n = s[i]-'0';
		int m = s[s.size()-1]-'0';
		if( n < m && !(n%2) )
		{
			swap( s[i], s[s.size()-1] );
			cout << s << endl;
			return 0;
		}
	}

	for( int i = s.size()-2; i >= 0; --i )
	{
		int n = s[i]-'0';
		if( !(n%2) )
		{
			swap( s[i], s[s.size()-1] );
			cout << s << endl;
			return 0;
		}
	}

	puts( "-1 ");
	return 0;
}

