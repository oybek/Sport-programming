
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int testi, a_size, b_size;
	vector<int>::iterator it;
	vector<int> a, b;

	testi = 1;
	while ( cin >> a_size >> b_size ) {
		if ( !a_size && !b_size )
			break;

		a.resize(a_size);
		b.resize(b_size);

		for ( auto & e : a ) cin >> e;
		for ( auto & e : b ) cin >> e;

		sort(a.begin(), a.end());

		cout << "CASE# " << testi << ":\n";
		for ( auto e : b ) {
			if ( ((it = lower_bound(a.begin(), a.end(), e)) != a.end())
				&& (*it == e) )
				cout << e << " found at " << it - a.begin() + 1 << endl;
			else
				cout << e << " not found\n";
		}

		++testi;
	}

	return 0;
}

