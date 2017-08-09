
/*
ID: aybek.h2
PROG: kimbits
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int L;
ll I;
ll dp[33][33];

void show_dp()
{
	for( int j = 0; j <= L; ++j )
	{
		for( int i = 1; i <= N; ++i )
			cout << setw(7) << dp[i][j];
		cout << endl;
	}
}

string get_ans( int n, int l, long i )
{
#ifdef LOCAL
//	cout << n << ' ' << l << ' ' << i << endl;
#endif
	if( n == 0 )
		return "";

	return dp[n-1][l] <= i
		? "1"+get_ans( n-1, l-1, i-dp[n-1][l] )
		: "0"+get_ans( n-1, l, i );
}

int main()
{
	// Always count dp[x][0], dp[0][y]

#ifndef LOCAL
	freopen( "kimbits.in", "rt", stdin );
	freopen( "kimbits.out", "wt", stdout );
#endif
	//
	cin >> N >> L >> I;

	//
	for( int l = 0; l <= L; ++l )
		dp[0][l] = 1;

	for( int n = 1; n <= N; ++n )
	{
		dp[n][0] = 1;
		for( int l = 1; l <= L; ++l )
			dp[n][l] = dp[n-1][l] + dp[n-1][l-1]; } 
#ifdef LOCAL
//	show_dp();
#endif

	//
	cout << get_ans( N, L, I-1 ) << endl;

	return 0;
}

