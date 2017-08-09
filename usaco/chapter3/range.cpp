
/*
ID: aybek.h2
PROG: range
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define N_MAX 251

int N;
int a[N_MAX][N_MAX];
int s[N_MAX][N_MAX];
int ans[N_MAX];

int main()
{
#ifndef LOCAL
	freopen( "range.in", "rt", stdin );
	freopen( "range.out", "wt", stdout );
#endif

	//
	cin >> N;
	for( int i = 1; i <= N; ++i )
	{
		string s;
		cin >> s;
		for( int j = 0; j < N; ++j )
		{
			a[i][j+1] = s[j]-'0';
		}
	}


	// precalc
	s[1][1] = a[1][1];

	for( int i = 2; i <= N; ++i )
	{
		s[i][1] = s[i-1][1] + a[i][1];
		s[1][i] = s[1][i-1] + a[1][i];
	}

	for( int i = 2; i <= N; ++i )
	{
		for( int j = 2; j <= N; ++j )
		{
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	}

	//
	for( int l = 2; l <= N; ++l )
	{
		int ll = l*l;
		for( int i = 1; i+l-1 <= N; ++i )
		{
			for( int j = 1; j+l-1 <= N; ++j )
			{
				int ii = i+l-1;
				int jj = j+l-1;

				if( s[ii][jj] - s[i-1][jj] - s[ii][j-1] + s[i-1][j-1] == ll )
				{
					++ans[l];
				}
			}
		}
	}

	//
	for( int i = 2; i <= N; ++i )
	{
		if( ans[i] > 0 )
		{
			cout << i << ' ' << ans[i] << endl;
		}
	}

	return 0;
}

