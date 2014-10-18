
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

#define SIZE 256

int main()
{
	using namespace std;

	int let_num[ SIZE ];
	string a, b, c;

	bool first = true;

	while ( ! cin.eof() )
	{
		getline(cin, a);
		getline(cin, b);

		fill(let_num, let_num + SIZE, 0);

		for ( auto e : a )
			++let_num[ int(e) ];

		c.resize(0);
		for ( auto e : b )
			if ( let_num[ int(e) ] > 0 ) {
				c.push_back(e);
				--let_num[ int(e) ];
			}

		sort( c.begin(), c.end() );
		
		if ( first ) first = false;
		else cout << endl;

		cout << c;
	}

	return 0;
}

