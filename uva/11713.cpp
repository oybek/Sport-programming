
#include <string>
#include <iostream>
using namespace std;

bool is_vowel(char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			return true;
	}
	return false;
}

int main() {
	int tt;
	string s1, s2;

	cin >> tt;
	while (tt--) {
		cin >> s1 >> s2;

		if (s1.size() != s2.size()) {
			cout << "No";
		} else {
			int i;
			for (i = 0; i < int(s1.size()); ++i) {
				if (s1[i] != s2[i] &&
					(!is_vowel(s1[i]) || !is_vowel(s2[i]))) {

					cout << "No";
					break;
				}
			}
			if (i == int(s1.size()))
				cout << "Yes";
		}
		cout << endl;
	}

	return 0;
}

