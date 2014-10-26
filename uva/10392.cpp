
#include <cmath>
#include <bitset>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

void factorize(ll n, vector<ll> & f) {
	int i;
	ll c, lim;

	if ( n == 0 ) return;

	for ( c = n; c%2 == 0; c /= 2 )
		f.push_back(2);

	lim = ll(sqrt(c))+1;
	for (i = 3; (i <= lim) && (i < 1000000); ) {
		if ( c % i == 0 ) {
			f.push_back(i);
			c /= i;
			lim = ll(sqrt(c))+1;
		} else
			i += 2;

	}

	if (c > 1) f.push_back(c);
}

int main() {

	ll n;
	vector<ll> f;
	f.reserve(64);
	bool first = true;

	while (1) {
		cin >> n;
		if (n < 0)
			break;

		f.resize(0);
		factorize(n, f);

		if (first) first = false;
		else cout << endl;

		for (int i = 0; i < int(f.size()); ++i)
			cout << "    " << f[i] << endl;
	}

	return 0;
}

