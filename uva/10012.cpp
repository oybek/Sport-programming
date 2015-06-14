
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <cfloat>
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

#define r_n_MAX 8

float f(float r1, float r2) {
	return (r1+r2) * sqrt(1.0f - SQR(abs(r1-r2)/(r1+r2)));
}

float get_len(float * r, int r_n) {
	if (r_n == 0)
		return 0.0f;
	float l = 0.0f;
	for (int i = 0; i+1 < r_n; ++i) {
		float t = 0.0f;
		for (int j = 0; j <= i; ++j) {
			t = max(f(r[j], r[i+1]), t);
		}
		l += t;
	}
	return r[0] + l + r[r_n-1];
}

int main() {
	int test_n, r_n;
	float r[r_n_MAX], ans;

	cin >> test_n;

	while (test_n--) {
		cin >> r_n;
		for (int i = 0; i < r_n; ++i)
			cin >> r[i];

		sort(r, r+r_n);
		ans = get_len(r, r_n);
		do {
			ans = min(get_len(r, r_n), ans);
		} while (next_permutation(r, r+r_n));

		cout << fixed << setprecision(3) << ans << endl;
	}

	return 0;
}

