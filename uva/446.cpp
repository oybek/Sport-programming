
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

string bin(int a) {
	string s;
	s.resize(13);
	for (int i = 0; i < 13; ++i)
		if (a&(1<<i))
			s[i] = '1';
		else
			s[i] = '0';
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int test_n, a, b;
	char c;

	cin >> test_n;
	while (test_n--) {
		cin >> hex >> a >> c >> hex >> b;

		cout << bin(a) << ' ' << c << ' ' << bin(b) << " = " << (c == '+' ? a+b : a-b) << endl;
	}

	return 0;
}

