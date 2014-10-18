
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define ASCII_SIZE 256

struct cf
{
	size_t f, c;

	inline friend
	bool operator < (const cf & a, const cf & b)
	{
		return ( a.f < b.f ? true : a.f == b.f ? a.c > b.c : false );
	}
};

cf mkcf(size_t f, size_t c)
{
	cf tmp = { f, c };
	return tmp;
}

void print_out(vector<cf> & tmp, vector<size_t> & freq)
{
	size_t i;
	for ( i = 0; i < freq.size(); ++i )
		if ( freq[ i ] )
			tmp.push_back( mkcf(freq[ i ], i) );

	sort( tmp.begin(), tmp.end() );

	for ( i = 0; i < tmp.size(); ++i )
		cout << tmp[ i ].c << ' ' << tmp[ i ].f << endl;
}

int main()
{
	char c;
	bool firstly = true;
	vector<cf> tmp;
	vector<size_t> freq( ASCII_SIZE );

	tmp.reserve( ASCII_SIZE );
	fill( freq.begin(), freq.end(), 0 );

	for ( ; cin.get(c); )
	{
		if (c >= 32 && c <= 128)
		{
			++freq[ c ];
		} else
		if (c == '\n')
		{
			if (firstly) firstly = false;
			else cout << endl;
			print_out(tmp, freq);

			tmp.resize( 0 );
			fill( freq.begin(), freq.end(), 0 );
		}
	}

	return 0;
}

