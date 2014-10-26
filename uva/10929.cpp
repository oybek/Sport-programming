
#include <cmath>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	string s;
	for (;;) {
		cin >> s;

		if ((s.size() == 1) &&
			(s[0] == '0'))
			break;

		int s1 = 0, s2 = 0;
		for (int i = 0; i < int(s.size()); ++i) {
			if (i%2) {
				s2 += s[i]-'0';
			} else {
				s1 += s[i]-'0';
			}
		}

		cout << s << " is" << (abs(s1-s2)%11 ? " not ": " " ) << "a multiple of 11.\n";
	}

	return 0;
}

