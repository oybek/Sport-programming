
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define MOD 1000000007

int aa[50001];
int bb[50001];

int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	aa[0] = bb[0] = 1;

	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= a && i-j >= 0; ++j )
		{
			aa[i] += bb[i-j];
		}

		for( int j = 1; j <= b && i-j >= 0; ++j )
		{
			aa[i] += bb[i-j];
		}
	}

	return 0;
}

