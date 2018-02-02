
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<string> a;
	a.resize(n);
	for( int i = 0; i < n; ++i )
		cin >> a[i];

	if( k == 1 )
	{
		int ans = 0;
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < m; ++j )
				if( a[i][j] == '.' )
					++ans;
		cout << ans << endl;
		return 0;
	}

	char prev = -1;
	int ans = 0;
	int count = 0;
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < m; ++j )
		{
			if( a[i][j] == '.' )
			{
				++count;
			}
			else
			{
				ans += max( count-k+1, 0 );
				count = 0;
			}
		}
		if( count  > 0 )
		{
			ans += max( count-k+1, 0 );
			count = 0;
		}
	}

	for( int i = 0; i < m; ++i )
	{
		for( int j = 0; j < n; ++j )
		{
			if( a[j][i] == '.' )
			{
				++count;
			}
			else
			{
				ans += max( count-k+1, 0 );
				count = 0;
			}
		}
		if( count  > 0 )
		{
			ans += max( count-k+1, 0 );
			count = 0;
		}
	}

	cout << ans << endl;

	return 0;
}

