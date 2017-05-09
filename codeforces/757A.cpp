
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int cnt[256];

int main()
{
	string s;
	cin >> s;
	for( char c : s )
		++cnt[c];

	int ans = cnt['B'];
	ans = min( ans, cnt['a']/2 );
	ans = min( ans, cnt['u']/2 );
	ans = min( ans, cnt['l'] );
	ans = min( ans, cnt['b'] );
	ans = min( ans, cnt['s'] );
	ans = min( ans, cnt['r'] );
	printf( "%d\n", ans );

	return 0;
}

