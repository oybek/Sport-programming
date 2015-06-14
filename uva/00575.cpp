
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, i;
	string s;
	while ( 1 )
	{
		cin >> s;
		if ( s[0] == '0' ) break;

		reverse( s.begin(), s.end() );
		for ( i = n = 0; i < (int) s.size(); ++i )
			n += (s[i]-'0') * ((2<<i) - 1);

		cout << n << endl;
	}

	return 0;
}

