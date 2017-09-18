
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

bool is_number( string s )
{
	for( char c : s )
		if( !isdigit(c) )
			return false;
	return true;
}

set<string> over_18 { "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE" };

int main()
{
	int n;
	cin >> n;

	int ans = 0;
	while( n-- )
	{
		string s;
		cin >> s;

		if( is_number(s) )
		{
			if( atoi(s.c_str()) < 18 )
				++ans;
		}
		else
		{
			if( over_18.find(s) != over_18.end() )
				++ans;
		}
	}

	cout << ans << endl;

	return 0;
}

