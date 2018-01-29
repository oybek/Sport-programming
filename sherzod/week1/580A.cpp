
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n = 0;
	int good = 1, best = 1;
	int prev_t = inf, t = 0;

	cin >> n;
	while( n-- )
	{
		cin >> t;

		if( t >= prev_t )
			++good;
		else
			good = 1;

		best = max( good, best );

		prev_t = t;
	}

	cout << best << endl;

	return 0;
}

