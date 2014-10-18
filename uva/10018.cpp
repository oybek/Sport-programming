
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>

bool palindrome(const std::string & s) {
	int i, j;
	for (i = 0, j = s.size()-1; i < j; ++i, --j)
		if (s[i] != s[j])
			return false;
	return true;
}

int main() {
	using namespace std;

	string s;
	uint64_t n, m, i;

	cin >> n;
	while (n--) {

		cin >> m;

		for (i = 0; !palindrome(to_string(m)); ++i) {
			s = to_string(m);
			reverse(s.begin(), s.end());
			m += stoi(s);
		}

		cout << i << ' ' << m << endl;
	}

	return 0;
}

