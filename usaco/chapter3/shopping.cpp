
/*
ID: aybek.h2
PROG: shopping
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define offer_max 100

#define K_MAX 6

// code to index mapping
int c2i[1000] = { -1 };

//
int item_cost[5];
int offer_cost[offer_max];
int offer_num;
int offer[offer_max][5];
int dp[ K_MAX ][ K_MAX ][ K_MAX ][ K_MAX ][ K_MAX ];

// configuration we need
int need[5];

//
void read_input()
{
	int I = 0;
	{
		int n;
		cin >> n;
		offer_num = n;

		for( int i = 0; i < n; ++i )
		{
			int t;
			cin >> t;

			for( int j = 0; j < t; ++j )
			{
				int c, k;
				cin >> c >> k;

				if( c2i[c] == -1 )
					c2i[c] = I++;

				offer[i][ c2i[c] ] = k;
			}

			cin >> offer_cost[i];
		}
	}

	{
		int n;
		cin >> n;

		for( int i = 0; i < n; ++i )
		{
			int c, k, p;

			cin >> c >> k >> p;

			if( c2i[c] == -1 )
				c2i[c] = I++;

			need[ c2i[c] ] = k;
			item_cost[ c2i[c] ] = p;
		}
	}
}

bool is_good( int x1, int x2, int x3, int x4, int x0 )
{
	return x1 >= 0 && x2 >= 0 && x3 >= 0 && x4 >= 0 && x0 >= 0;
}

template <class it>
void show_array(it a, it b)
{
	while( a != b )
	{
		cout << *a << ' ';
		++a;
	}
	cout << endl;
}

int main()
{
#ifndef LOCAL
	freopen( "shopping.in", "rt", stdin );
	freopen( "shopping.out", "wt", stdout );
#endif

	fill( c2i, c2i+1000, -1 );

	read_input();

	// bottom up
	for( int x0 = 0; x0 <= 5; ++x0 )
	for( int x1 = 0; x1 <= 5; ++x1 )
	for( int x2 = 0; x2 <= 5; ++x2 )
	for( int x3 = 0; x3 <= 5; ++x3 )
	for( int x4 = 0; x4 <= 5; ++x4 )
	{
		dp[x0][x1][x2][x3][x4] = item_cost[0]*x0 + item_cost[1]*x1 + item_cost[2]*x2 + item_cost[3]*x3 + item_cost[4]*x4;

		for( int i = 0; i < offer_num; ++i )
		{
			if( x0-offer[i][0] >= 0 &&
				x1-offer[i][1] >= 0 &&
				x2-offer[i][2] >= 0 &&
				x3-offer[i][3] >= 0 &&
				x4-offer[i][4] >= 0 )
			{
				dp[x0][x1][x2][x3][x4] = min( dp[x0][x1][x2][x3][x4], dp[x0-offer[i][0]][x1-offer[i][1]][x2-offer[i][2]][x3-offer[i][3]][x4-offer[i][4]] + offer_cost[i] );
			}
		}
	}

#ifdef LOCAL
	show_array( item_cost, item_cost+5 );
	show_array( need, need+5 );
#endif
	cout << dp[need[0]][need[1]][need[2]][need[3]][need[4]] << endl;


	return 0;
}

