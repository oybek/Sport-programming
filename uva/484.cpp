
#include <map>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ll n;

	map<ll, int> occ;
	vector<ll> order; order.reserve(1000000);

	while (cin >> n) {
		if (occ.find(n) == occ.end()) {
			occ[n] = 1;
			order.push_back(n);
		} else {
			++occ[n];
		}
	}

	for (int i = 0; i < int(order.size()); ++i) {
		cout << order[i] << ' ' << occ[order[i]] << endl;
	}

	return 0;
}

