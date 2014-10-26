
#include <cmath>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int tt;
	string s;

	cin >> tt; cin.get();
	while (tt--) {
		getline(cin, s);

		int sqr_len = sqrt(float(s.size()));
		if (sqr_len*sqr_len != int(s.size())) {
			cout << "INVALID\n";
			continue;
		}

		for (int i = 0; i < sqr_len; ++i)
		for (int j = 0; j < sqr_len; ++j)
			cout << s[sqr_len*j+i];
		cout << endl;
	}

	return 0;
}

