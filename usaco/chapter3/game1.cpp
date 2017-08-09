
/*
ID: aybek.h2
PROG: game1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define N_MAX 201

int N;
int a[ N_MAX ];

// TODO: write bottom up solution
// for memoization
pair<int, int> dp[ N_MAX ][ N_MAX ][ 2 ];

pair<int, int> get_ans( int i, int j, bool firstPlayerTurn )
{
	assert( i < j );
	if( dp[i][j][firstPlayerTurn].first > 0 )
		return dp[i][j][firstPlayerTurn];

	if( firstPlayerTurn )
	{
		if( i+1 == j )
		{
			dp[i][j][firstPlayerTurn] = make_pair( max(a[i], a[j]), min(a[i], a[j]) );
		}
		else
		{
			// chose left
			pair<int, int> case1 = get_ans( i+1, j, !firstPlayerTurn );
			case1.first += a[i];

			// chose right
			pair<int, int> case2 = get_ans( i, j-1, !firstPlayerTurn );
			case2.first += a[j];

			dp[i][j][firstPlayerTurn] = case1.first > case2.first
				? case1
				: case2;
		}
	}
	else
	{
		if( i+1 == j )
		{
			return make_pair( min(a[i], a[j]), max(a[i], a[j]) );
		}
		else
		{
			// chose left
			pair<int, int> case1 = get_ans( i+1, j, !firstPlayerTurn );
			case1.second += a[i];

			// chose right
			pair<int, int> case2 = get_ans( i, j-1, !firstPlayerTurn );
			case2.second += a[j];

			dp[i][j][firstPlayerTurn] = case1.second > case2.second
				? case1
				: case2;
		}
	}

	return dp[i][j][firstPlayerTurn];
}

int main()
{
#ifndef LOCAL
	freopen( "game1.in", "rt", stdin );
	freopen( "game1.out", "wt", stdout );
#endif

	cin >> N;
	for( int i = 0; i < N; ++i )
		cin >> a[ i ];

	pair<int, int> ans = get_ans( 0, N-1, true );

	cout << ans.first << ' ' << ans.second << endl;

	return 0;
}

