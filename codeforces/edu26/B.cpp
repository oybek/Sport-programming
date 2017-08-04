
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n, m;
string a[ 100 ];

bool is_good_h()
{
	for( int i = 0; i < n/3; ++i )
	{
		for( int j = 0; j < m; ++j )
			if( a[0][0] != a[i][j] )
			{
				return false;
			}
	}
	for( int i = n/3; i < 2*n/3; ++i )
	{
		for( int j = 0; j < m; ++j )
			if( a[n/3][0] != a[i][j] )
			{
				return false;
			}
	}
	for( int i = 2*n/3; i < n; ++i )
	{
		for( int j = 0; j < m; ++j )
			if( a[2*n/3][0] != a[i][j] )
			{
				return false;
			}
	}
	return ( a[0][0] != a[n/3][0] ) && ( a[n/3][0] != a[2*n/3][0] ) && ( a[0][0] != a[2*n/3][0] );
}

bool is_good_v()
{
	for( int i = 0; i < m/3; ++i )
	{
		for( int j = 0; j < n; ++j )
			if( a[0][0] != a[j][i] )
			{
				return false;
			}
	}
	for( int i = m/3; i < 2*m/3; ++i )
	{
		for( int j = 0; j < n; ++j )
			if( a[0][m/3] != a[j][i] )
			{
				return false;
			}
	}
	for( int i = 2*m/3; i < m; ++i )
	{
		for( int j = 0; j < n; ++j )
			if( a[0][2*m/3] != a[j][i] )
			{
				return false;
			}
	}
	return ( a[0][0] != a[0][m/3] ) && ( a[0][m/3] != a[0][2*m/3] ) && ( a[0][0] != a[0][2*m/3] );
}

int main()
{
	cin >> n >> m;

	for( int i = 0; i < n; ++i )
		cin >> a[i];

	if( ( m%3 == 0 && is_good_v() ) || ( n%3 == 0 && is_good_h() ) )
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}

