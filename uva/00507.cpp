
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int test_n;
	cin >> test_n;

	while( test_n-- )
	{
		int n;
		vector<int> a;

		cin >> n;
		a.resize(n);

		for( int i = 1; i < n; ++i )
			cin >> a[i];

		int ans = 0;
		int sum = 0;
		int min_sum = 0;

		for( int i = 1; i < n; ++i )
		{
			sum += a[i];
			ans = max( sum - min_sum, ans );
			min_sum = min( sum, min_sum );
		}
	}

	return 0;
}

