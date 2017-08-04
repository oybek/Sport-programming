
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

//
int n, a, b;
vector<pair<int, int> > v;

int is_good( int x, int y )
{
	return x <= a && y <= b;
}

int main()
{
	//
	cin >> n >> a >> b;
	v.resize(n);
	for( int i = 0; i < v.size(); ++i )
	{
		cin >> v[i].first >> v[i].second;
	}

	//
	int ans = 0;
	for( int i = 0; i < v.size(); ++i )
	{
		for( int j = i+1; j < v.size(); ++j )
		{
#define x first
#define y second
			if( is_good( max(v[i].x, v[j].x), v[i].y+v[j].y ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );

			if( is_good( v[i].x + v[j].x, max( v[i].y, v[j].y ) ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );

			if( is_good( max(v[i].x, v[j].y), v[i].y+v[j].x ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );

			if( is_good( v[i].x + v[j].y, max( v[i].y, v[j].x ) ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );

			if( is_good( max(v[i].y, v[j].x), v[i].x+v[j].y ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );

			if( is_good( max(v[i].y, v[j].y), v[i].x+v[j].x ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );

			if( is_good( v[i].y + v[j].x, max( v[i].x, v[j].y ) ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );

			if( is_good( v[i].y + v[j].y, max( v[i].x, v[j].x ) ) )
				ans = max( ans, v[i].x*v[i].y + v[j].x*v[j].y );
#undef x
#undef y
		}
	}

	cout << ans << endl;

	return 0;
}

