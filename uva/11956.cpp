
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

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

#define ram_sz 100
int ram[ram_sz];

void init_ram() {
	for (int i = 0; i < ram_sz; ++i)
		ram[i] = 0;
}

void dump_ram() {
	cout << uppercase << hex;
	for (int i = 0; i < ram_sz; ++i) {
		cout << ' ' << hex << uppercase << setfill('0') << setw(2) << ram[i];
	}
}

#ifndef ONLINE_JUDGE
void debug() {
	ram[0] = 15;
	dump_ram();
	exit(0);
}
#endif

int main() {
	string s; s.reserve(100001);
	int test_n, pos;

	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i) {
		/* prepare stage */
		pos = 0;
		init_ram();

		/* input stage */
		cin >> s;
		for (string::iterator it = s.begin(); it != s.end(); ++it) {
			switch (*it) {
				case '<': if (--pos < 0) pos = ram_sz-1; break;
				case '>': if (++pos > ram_sz-1) pos = 0; break;
				case '+': if (++ram[pos] > 255) ram[pos] = 0; break;
				case '-': if (--ram[pos] < 0) ram[pos] = 255; break;
			}
		}

		/* output */
		cout << "Case " << dec << test_i << ':';
		dump_ram();
		cout << endl;
	}

	return 0;
}

