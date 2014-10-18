
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, i, iofmax;
	vector<int> a, len;

	while ( cin >> t )
		a.push_back(t);

	len.resize( a.size() );
	iofmax = 0;
	len[0] = 1;
	for ( i = 1; i < (int) a.size(); ++i ) {
		len[i] = ( a[i] > a[i-1] ? len[i-1]+1: 1);

		if ( len[ i ] >= len[ iofmax ] )
			iofmax = i;
	}

	cout << len[iofmax] << endl << '-' << endl;
	for ( i = iofmax-len[iofmax]; i < iofmax; ++i )
		cout << a[i] << endl;

	return 0;
}

