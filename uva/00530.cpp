
#include <map>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

/* I guess n will not be greater 100 */

bool factorize(int n, std::map<int, int> & pairs) {
#define INCREASE(m, a) if (m.find(a) == m.end()) m[a] = 1 else ++m[a];
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

/* a1! / a2! / a3! */
typedef map<int, int> mii;

mii a1;
mii a2;
mii a3;

void factorize_fact(mii & a, int i, int j) {
	a.clear();
	for (; i <= j; ++i)
		factorize(i, a);
}

void divide(mii & a1, mii & a2) {
	for (mii::iterator it = a2.begin(); it != a2.end(); ++it) {
		a1.find(it->first)->second -= it->second;
		a2.erase(it);
	}
}

int main() {
	int n, k;
	for (;;) {
		cin >> n >> k;
		if (!n && !k)
			break;

		if (k > n-k) {
			factorize_fact(a1, k+1, n);
			factorize_fact(a2, 2, n-k);
		} else {
			factorize_fact(a1, n-k+1, n);
			factorize_fact(a2, 2, k);
		}

		divide(a1, a2);

		int ans = 1;
		for (mii::iterator it = a1.begin(); it != a1.end(); ++it)
			ans *= pow(it->first, it->second);

		cout << ans << endl;
	}

	return 0;
}

