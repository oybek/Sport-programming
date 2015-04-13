
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;

int64 a, b, d;
vector<int64> adivs;

int main() {
	adivs.reserve(100);

	cin >> a >> b;
	if (a > b)
		swap(a, b);

	for (d = 1; d*d < a; ++d) {
		if (a%d == 0) {
			adivs.push_back(d);
			adivs.push_back(a/d);
		}
	}
	if (d*d == a)
		adivs.push_back(d);

	sort(adivs.begin(), adivs.end());
	for (vector<int64>::iterator it = adivs.begin(); it != adivs.end(); ++it)
		if (b%(*it) == 0)
			cout << *it << ' ';

	return 0;
}

