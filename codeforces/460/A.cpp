
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> ab;
	ab.resize( n );
	for( int i = 0; i < n; ++i )
	{
		cin >> ab[i].first >> ab[i].second;
	}

	pair<int, int> ans = ab.front();
	for( int i = 0; i < n; ++i )
	{
		if( ans.first*ab[i].second > ans.second*ab[i].first )
			ans = ab[i];
	}

	printf( "%.10lf\n", ans.first*double(m)/ans.second );

	return 0;
}

