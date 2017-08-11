
/*
ID: aybek.h2
PROG: rockers
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

// knapsack problem

#define N_MAX 21
#define T_MAX 21 

int N, T, M;
vector<int> song;

int dp[N_MAX][T_MAX];

template <class it>
void print( it a, it b )
{
	while( a != b )
		cout << setw(2) << *a++;
	cout << endl;
}

void find_ans( int k, int s, vector<int>& ans )
{
	if( dp[k][s] == 0 )
		return;

	if( dp[k-1][s] == dp[k][s] )
		find_ans( k-1, s, ans );
	else
	{
		find_ans( k-1, s-song[k], ans );
		ans.push_back( k );
	}
}

void knapsack()
{
	for( int i = 0; i <= T; ++i )
		dp[0][i] = 0;

	for( int i = 0; i <= N; ++i )
		dp[i][0] = 0;

	for( int k = 1; k <= N; ++k )
		for( int s = 1; s <= T; ++s )
			if( s >= song[k] )
				dp[k][s] = max( dp[k-1][s], dp[k-1][s-song[k]] + 1 );
			else
				dp[k][s] = dp[k-1][s];

	vector<int> ans;

	find_ans( N, T, ans );

	// slyly delete song that placed in disk
	for( int i = 0; i < ans.size(); ++i )
		song[ans[i]] = T+1;

#ifdef LOCAL
	print( ans.begin(), ans.end() );
#endif
}

int main()
{
#ifndef LOCAL
	freopen( "rockers.in", "rt", stdin );
	freopen( "rockers.out", "wt", stdout );
#endif

	//
	cin >> N >> T >> M;

	song.resize( N+1 );
	for( int i = 1; i <= N; ++i )
		cin >> song[i];

	while( M-- )
		knapsack();

	cout << count( song.begin(), song.end(), T+1 ) << endl;

	return 0;
}

