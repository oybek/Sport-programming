
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;

	unsigned int i, n, carry;
	string a, b;

	while (1) {

		cin >> a >> b;

		if (a == "0" && b == "0")
			break;

		if (a.size() < b.size())
			swap(a, b);

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		carry = n = 0;
		for (i = 0; (i < a.size()) && (i < b.size()); ++i) {
			carry = ((a[i]-'0') + (b[i]-'0') + carry) / 10;

			if (carry > 0)
				++n;
		}

		for (; i < a.size(); ++i) {
			carry = ((a[i]-'0') + carry) / 10;

			if (carry > 0)
				++n;
		}

		if (n == 0) {
			cout << "No carry operation.\n";
		} else
		if (n == 1) {
			cout << n << " carry operation.\n";
		} else {
			cout << n << " carry operations.\n";
		}
	}

	return 0;
}

