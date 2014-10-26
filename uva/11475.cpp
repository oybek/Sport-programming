
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

bool is_palindrome(string s, int i, int j) {
	while (i < j) {
		if (s[i] != s[j])
			return false;
		++i;
		--j;
	}
	return true;
}

int main() {
	string s, tail;
	while (cin >> s) {
		for (int i = 0; i < int(s.size()); ++i) {
			if (is_palindrome(s, i, s.size()-1)) {
				cout << s;
				for (int j = i-1; j >= 0; --j)
					cout << s[j];
				cout << endl;
				break;
			}
		}
	}

	return 0;
}

