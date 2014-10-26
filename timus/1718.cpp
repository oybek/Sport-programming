
#include <set>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n, tn, max = 0;
	set<string> author;

	string name, s;

	cin >> n;
	while (n--) {
		cin >> name >> s;

		switch (toupper(s[0])) {
			case 'C':
				break;

			case 'A':
				if (author.find(name) == author.end()) {
					author.insert(name);
					++max;
				}
				break;

			case 'W':
			case 'T':
			case 'M':
				cin >> tn;
				if (author.find(name) == author.end()) {
					author.insert(name);
					max += (tn >= 6);
				}
				break;
		}
	}

	cout << 0 << ' ' << max << endl;

	return 0;
}

