
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int N, M, piece_num, i;
	cin >> N >> M;

	char c;
	bool only_lets = true;

	i = 0;
	while (cin.get(c)) {
		if (c == '\n') break;

		if (c != ' ' && !isalpha(c)) {
			only_lets = false;
		}

		if (only_lets == true) {
			if (i == M) {
				++piece_num;
				i = 0;
			}
		} else {
			if (i == N) {
				++piece_num;
				only_lets = true;
				i = 0;
			}
		}

		++i;
	}

	return 0;
}

