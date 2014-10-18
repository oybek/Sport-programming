
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define repeat(n) for (size_t _i = 0; _i < n; ++_i)
#define skip_word { string s; cin >> s; }

int main() {
	using namespace std;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int scor, conc, n;
	cin >> n;
	while (n--) {
		string s;
		repeat(3) skip_word;
		cin >> s;
		repeat(2) skip_word;
		cin >> scor;
		repeat(3) skip_word;
		cin >> conc;
		repeat(3) skip_word;

		if (s == "home") {
			if (scor > conc) {
				cout << "0 ";
			}
		} else
		if (s == "away") {
		}
	}

	return 0;
}

