
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

string s[3];

bool won(char c) {
	return
		(s[0][0] == c && s[1][1] == c && s[2][2] == c) ||
		(s[2][0] == c && s[1][1] == c && s[0][2] == c) ||

		(s[0][0] == c && s[0][1] == c && s[0][2] == c) ||
		(s[1][0] == c && s[1][1] == c && s[1][2] == c) ||
		(s[2][0] == c && s[2][1] == c && s[2][2] == c) ||

		(s[0][0] == c && s[1][0] == c && s[2][0] == c) ||
		(s[0][1] == c && s[1][1] == c && s[2][1] == c) ||
		(s[0][2] == c && s[1][2] == c && s[2][2] == c);
}

bool is_good() {
	int x_count = 0, o_count = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (s[i][j] == 'X')
				++x_count;
			else
			if (s[i][j] == 'O')
				++o_count;

	if (won('X')) {
		return x_count == o_count+1;
	} else
	if (won('O')) {
		return x_count == o_count;
	} else {
		return
			x_count == o_count ||
			x_count == o_count+1;
	}
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		cin >> s[0]
			>> s[1]
			>> s[2];
		cout << (is_good() ? "yes" : "no") << endl;
	}

	return 0;
}

