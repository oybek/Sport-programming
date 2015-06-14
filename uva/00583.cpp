
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

bool factorize(int n, std::map<int, int> & pairs) {
	pairs.clear();

	if (n == 0)
		return false;

	int i, c;
	for (c = n; c%2 == 0; c /= 2) {
		if (pairs.find(2) == pairs.end())
			pairs[2] = 1;
		else
			++pairs[2];
	}

	int lim = static_cast<int>(sqrt(c))+1;
	for (i = 3; i <= lim; ) {
		if (c%i == 0) {
			if (pairs.find(i) == pairs.end())
				pairs[i] = 1;
			else
				++pairs[i];
			c /= i;
			lim = static_cast<int>(sqrt(c))+1;
		} else { i += 2; }
	}

	if (c > 1) {
		if (pairs.find(c) == pairs.end())
			pairs[c] = 1;
		else
			++pairs[c];
	}

	return true;
}

/*
void show(map<int, int> & muls) {
	for ( auto e : muls ) {
		cout << e.first << ' ' << e.second << endl;
	}
}
*/

int main() {
	int n;
	bool flag;
	map<int, int> muls;
	map<int, int>::iterator it;
	for ( ;; ) {
		cin >> n;
		if ( !n )
			break;

		factorize(abs(n), muls);

		cout << n << " = ";

		flag = true;
		if (n < 0) {
			cout << -1;
			flag = false;
		}

		for ( it = muls.begin(); it != muls.end(); ++it )
			for ( ; it->second--; ) {
				if ( flag ) flag = false;
				else cout << " x ";

				cout << it->first;
			}
		cout << endl;
	}

	return 0;
}

