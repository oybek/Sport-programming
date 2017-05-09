
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int a[5];
int cnt[101];

int main()
{
	for( int i = 0; i < 5; ++i )
	{
		scanf( "%d", a+i );
		++cnt[a[i]];
	}

	int sum = accumulate( a, a+5, 0 );
	int ans = sum;
	for( int i = 0; i < 5; ++i )
	{
		if( cnt[a[i]] >= 3 )
			ans = min( sum-a[i]*3, ans );
		if( cnt[a[i]] == 2 )
			ans = min( sum-a[i]*2, ans );
	}

	cout << ans << endl;

	return 0;
}

