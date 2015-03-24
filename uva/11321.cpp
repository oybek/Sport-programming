
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

#define N_MAX 100001

int N, M;

struct number_t {
	int64 n, m;

	bool operator < (const number_t & a) const {
		if (m == a.m) {
			if (n%2) {
				return a.n%2 ? !(n < a.n) : true;
			} else {
				return a.n%2 ? false : n < a.n;
			}
		} else {
			return m < a.m;
		}
	}
};

int main() {
	number_t a[N_MAX];

	int i;
	while (cin >> N >> M) {
		if (N == 0 && M == 0) {
			cout << "0 0" << endl;
			break;
		}

		for (i = 0; i < N; ++i) {
			cin >> a[i].n;
			a[i].m = a[i].n % M;
		}

		sort(a, a+N);

		cout << N << ' ' << M << endl;
		for (i = 0; i < N; ++i)
			cout << a[i].n << endl;
	}

	return 0;
}

