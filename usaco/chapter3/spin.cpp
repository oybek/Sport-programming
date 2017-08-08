
/*
ID: aybek.h2
PROG: spin
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int circle[360];
int speed[5];
vector< pair<int, int> > w[ 5 ];

void rotate()
{
	for( int i = 0; i < 5; ++i )
	{
		for( int j = 0; j < w[i].size(); ++j )
		{
			w[i][j].first += speed[i];
			w[i][j].first %= 360;

			w[i][j].second += speed[i];
			w[i][j].second %= 360;
		}
	}
}

int main()
{
#ifndef LOCAL
	freopen( "spin.in", "rt", stdin );
	freopen( "spin.out", "wt", stdout );
#endif

	//
	vector< pair<int, int> > w[ 5 ];
	for( int i = 0; i < 5; ++i )
	{
		cin >> speed[i];

		int n;
		cin >> n;
		while( n-- )
		{
			int x, y;
			cin >> x >> y;
			w[i].push_back( make_pair( x, y ) );
		}
	}

	//
	for( int t = 0; t < 10000; ++t )
	{
		fill( circle, circle+360, 0 );

		for( int i = 0; i < 5; ++i )
		{
			for( int j = 0; j < w[i].size(); ++j )
			{
				int k = ( w[i][j].first + speed[i] * t )%360;
				for( int x = 0; x <= w[i][j].second; ++x )
				{
					if( ++circle[ (k+x)%360 ] >= 5 )
					{
						cout << t << endl;
						return 0;
					}
				}
			}
		}
		rotate();
	}

	cout << "none" << endl;
	return 0;
}

