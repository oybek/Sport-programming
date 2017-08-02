
/*
ID: aybek.h2
PROG: stamps
LANG: C++
*/

#define PROB_NAME "stamps"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VALUE 2000001

int used[ MAX_VALUE ];

int K;
int N;
vector<int> val;

void show( int size )
{
	for( int i = 1; i <= size; ++i )
		cout << used[ i ] << ' ';
	cout << endl;
}

int main()
{
#ifndef LOCAL
	freopen( PROB_NAME".in", "rt", stdin );
	freopen( PROB_NAME".out", "wt", stdout );
#endif

	cin >> K >> N;

	val.resize( N );
	for( int i = 0; i < val.size(); ++i )
		cin >> val[ i ];

	sort( val.begin(), val.end() );

	for( int i = 0; i < val.size(); ++i )
		used[ val[i] ] = 1;

	int size = val[ val.size()-1 ] * K;
	for( int i = 1; i <= size; ++i )
	{
		if( used[ i ] > 0 && used[ i ] < K )
		{
			for( int j = 0; j < val.size(); ++j )
			{
				if( used[ i+val[j] ] == 0 )
					used[ i+val[j] ] = used[ i ] + 1;
				else
					used[ i+val[j] ] = min( used[ i+val[j] ], used[ i ] + 1 );
			}
		}
	}

	//show( size );
	
	// find length of maximal non null contain cont subseq
	
	if( used[ 1 ] == 0 )
	{
		cout << "0" << endl;
	}
	else
	{
		int ans = 1;
		while( used[ ans ] > 0 )
			++ans;
		cout << ans-1 << endl;
	}

	return 0;
}

