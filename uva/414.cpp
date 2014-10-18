
#include <cmath>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int i, t, sn[ 14 ], minsn, vn;
	string s;

	while ( cin >> t ) {
		if ( !t ) break;

		getline(cin, s);

		minsn = -1;
		fill(sn, sn + t, 0);

		for (i = 0; i < t; ++i) {
			getline(cin, s);
			for (auto e : s)
				sn[ i ] += (e == ' ');
			minsn = ((minsn == -1) ? sn[ i ]: min(minsn, sn[ i ]));
		}

		vn = 0;
		for (i = 0; i < t; ++i)
			vn += sn[ i ] - minsn;

		cout << vn << endl;
	}

	return 0;
}

