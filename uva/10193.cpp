
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

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int bstr2int(const string & s) {
	int n = 0, p = 1;
	for (string::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
		n += (*it-'0')*p;
		p <<= 1;
	}
	return n;
}

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int main() {
	int test_n;
	string s;

	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i) {
		cin >> s;
		int a = bstr2int(s);
		cin >> s;
		int b = bstr2int(s);

		cout << "Pair #" << test_i << ": " << (gcd(a, b) == 1 ? "Love is not all you need!" : "All you need is love!") << endl;
	}

	return 0;
}

