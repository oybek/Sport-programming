
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

class coord
{
	public:
		int x;
		int y;

		coord( int x, int y )
			: x(x)
			, y(y)
		{}
};

class board
{
	private:
		int height;
		int length;
		vector<int> a;

	public:
		board()
		{
			height = 3;
			length = 3;
			a.resize(9);
			for( int i = 0; i < a.size(); ++i )
				a[i] = i+1;
		}

		int get_height() const
		{
			return height;
		}

		int get_length() const
		{
			return length;
		}

		int& get( int i, int j )
		{
			return a[ 3*i+j ];
		}

		// Создает новую доску и меняет в ней местами элементы на позициях a и b
		board swap( coord a, coord b )
		{
			board new_board = *this;
			std::swap( new_board.get( a.x, a.y ), new_board.get( b.x, b.y ) );
			return new_board;
		}

		string to_string() const
		{
			string s = "";
			for( int i = 0; i < a.size(); ++i )
			{
				s.push_back( a[i]+'0' );
			}
			return s;
		}

		bool operator== ( const board& arg ) const
		{
			for( int i = 0; i < a.size(); ++i )
			{
				if( a[i] != arg.a[i] )
				{
					return false;
				}
			}
			return true;
		}
};

class
{
	public:
		bool operator() ( int n )
		{
			return n == 2
				|| n == 3
				|| n == 5
				|| n == 7
				|| n == 11
				|| n == 13
				|| n == 17;
		}
} is_prime;

class
{
	private:
		map<string, int> solution;

	public:
		void precalc()
		{
			board good_board;

			queue< pair<board, int> > Q;
			Q.push( make_pair( good_board, 0 ) );

			while( !Q.empty() )
			{
				auto cur_board = Q.front().first;
				auto cur_depth = Q.front().second;
				Q.pop();

				if( solution.count( cur_board.to_string() ) )
					continue;
				else
					solution[ cur_board.to_string() ] = cur_depth;

				//
				for( int i = 0; i < cur_board.get_height(); ++i )
				{
					for( int j = 0; j < cur_board.get_length(); ++j )
					{
						if( i+1 < cur_board.get_height() )
						{
							int sum = cur_board.get(i, j) + cur_board.get(i+1, j);
							if( is_prime( sum ) )
								Q.push( make_pair( cur_board.swap( coord(i+1, j), coord(i, j) ), cur_depth+1 ) );
						}

						if( j+1 < cur_board.get_length() )
						{
							int sum = cur_board.get(i, j+1) + cur_board.get(i, j);
							if( is_prime( sum ) )
								Q.push( make_pair( cur_board.swap( coord(i, j+1), coord(i, j) ), cur_depth+1 ) );
						}
					}
				}
			}
		}

		// Надо определить минимальное количество шагов для того чтобы плохую доску превратить в хорошую
		int operator() ( const board& bad_board )
		{
			if( solution.count( bad_board.to_string() ) )
				return solution[ bad_board.to_string() ];
			else
				return -1;
		}
} solve;

int main()
{
	int test_n;
	cin >> test_n;

	board good_board;

	solve.precalc();

	while( test_n-- )
	{
		board cur_board;

		for( int i = 0; i < 3; ++i )
			for( int j = 0; j < 3; ++j )
				cin >> cur_board.get( i, j );

		int answer = solve( cur_board );
		cout << (answer == inf ? -1 : answer ) << endl;
	}

	return 0;
}

