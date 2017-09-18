
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

	string hello = "hello";
	int j = 0;
	for( int i = 0; i < s.size(); ++i )
	{
		if( s[i] == hello[j] )
		{
			if( ++j == hello.size() )
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}

