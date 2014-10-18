
#include <cctype>
#include <iostream>

int main() {
	using namespace std;

	int wordn = 0;
	char c;
	bool in = false;

	while (cin.get(c)) {
		if (isalpha(c)) {
			if (in == false) {
				in = true;
				++wordn;
			}
		} else {
			if (c == '\n') {
				cout << wordn << endl;
				wordn = 0;
			}
			in = false;
		}
	}

	return 0;
}

