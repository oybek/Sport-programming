
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

int digsum(int n) {
	int s = 0;
	for (; n > 0; n /= 10) {
		s += n%10;
	}
	return s;
}

int main() {
	int test_n;

	cin >> test_n;
	string s, t;
	while (test_n--) {
		s.resize(0);

		cin >> t; s += t;
		cin >> t; s += t;
		cin >> t; s += t;
		cin >> t; s += t;

		int sum = 0;
		for (int i = 0; i < int(s.size()); i += 2) {
			sum += digsum((s[i]-'0')*2);
		}
		for (int i = 1; i < int(s.size()); i += 2) {
			sum += digsum((s[i]-'0'));
		}

		cout << (sum%10 == 0 ? "Valid": "Invalid") << endl;
	}

	return 0;
}

