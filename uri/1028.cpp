
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

inline void DEBUG(bool cond, const char * msg) {
#ifdef DO_DEBUG
	if (cond) {
		std::cerr << msg << '\n';
		exit(0);
	}
#endif
}

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int N, F1, F2;

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
	cin >> N;
	while (N--) {
		cin >> F1 >> F2;
		cout << gcd(F1, F2) << endl;
	}

	return 0;
}

