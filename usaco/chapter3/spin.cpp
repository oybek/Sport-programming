
/*
ID: aybek.h2
PROG: spin
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

template< int SIZE >
class bit_array
{
	private:
		bitset< SIZE > a;

	public:
		void reset_range( int i, int n )
		{
			while( n-- )
			{
				a[ i ] = 0;
				if( ++i >= SIZE )
					i = 0;
			}
			a[ i ] = 0;
		}

		void set() { a.set(); }
		bool all() {
			for( int i = 0; i < a.size(); ++i )
				if( a[i] == false )
					return false;
			return true;
		}

#ifdef LOCAL
		void print() { cout << a.to_string() << endl; }
#endif
};

struct wheel
{
	int speed; // degrees per second
	vector< pair<int, int> > wedge;
};

bit_array<360> circle;
vector< wheel > w( 5 );

bool is_solution()
{
	circle.set();

	for( int i = 0; i < w.size(); ++i )
	{
		for( int j = 0; j < w[i].wedge.size(); ++j )
		{
			circle.reset_range(
				w[i].wedge[j].first, 
				w[i].wedge[j].second 
			);
		}
	}

#ifdef LOCAL
	circle.print();
	cout << circle.all() << endl;
#endif

	return !( circle.all() );
}

void rotate()
{
	for( int i = 0; i < w.size(); ++i )
	{
		for( int j = 0; j < w[i].wedge.size(); ++j )
		{
			w[i].wedge[j].first += w[i].speed;
			w[i].wedge[j].first %= 360;
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
	for( int i = 0; i < w.size(); ++i )
	{
		cin >> w[i].speed;

		int size;
		cin >> size;

		w[i].wedge.resize( size );
		for( int j = 0; j < w[i].wedge.size(); ++j )
			cin >> w[i].wedge[j].first >> w[i].wedge[j].second;
	}

	//
	for( int ans = 0; ans < 1000; ++ans )
	{
		if( is_solution() )
		{
			cout << ans << endl;
			return 0;
		}

		rotate();
	}

	cout << "none" << endl;

	return 0;
}

