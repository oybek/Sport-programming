
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

string s;
int n;
vector<string> ss;

int main()
{
	cin >> s;
	cin >> n;

	ss.resize( n );
	for( int i = 0; i < n; ++i )
	{
		cin >> ss[i];
	}

	sort( all(ss) );

	auto it = lower_bound( all(ss), s );
	cout << ( it == ss.end() || it->substr(0, s.size()) != s ? s : *it ) << endl;

	return 0;
}

