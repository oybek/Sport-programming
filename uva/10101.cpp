
#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long uint64;

int main() {
	int i = 1;
	string s;
	while (cin >> s) {
		cout << i++ << ". ";
		if (s.size() < 3) {
			cout << s << endl;
		} else
		if (s.size() == 3) {
			cout << s.substr(0, 1) << " shata ";
		}
	}

	return 0;
}

