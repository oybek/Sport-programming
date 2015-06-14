
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
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

int pow(int a, int n) {
	if (n == 0) return 1;
	else if (n%2) {
		return pow(a, n-1)*a;
	} else {
		int t = pow(a, n/2);
		return SQR(t);
	}
}

#define SIZE 32768
int prime_exp[SIZE];

void factorize(int n) {
	for (int d = 2; d*d <= n;) {
		if (n%d) {
			++d;
		} else {
			++prime_exp[d];
			n /= d;
		}
	}
	if (n > 1) {
		++prime_exp[n];
	}
}

int main() {
	int x, y, n;
	string s;
	stringstream ss;
	vector<pair<int, int> > cf;

	while (getline(cin, s)) {
		/* prepare stage */
		ss.clear();
		ss.str(s);
		fill(prime_exp, prime_exp+SIZE, 0);

		/* input stage */
		n = 1;
		while (ss >> x) {
			if (!x) exit(0);
			ss >> y;

			n *= pow(x, y);
		}

		/* solve */
		factorize(n-1);
		bool ff = true;
		for (int i = SIZE-1; i >= 0; --i) {
			if (prime_exp[i]) {
				if (ff) ff = false;
				else cout << ' ';
				cout << i << ' ' << prime_exp[i];
			}
		}
		cout << endl;
	}

	return 0;
}

