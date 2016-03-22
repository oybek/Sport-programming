
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define k_max 101

int k, a[k_max];

int is_good_i;
bool is_good(int n) {
	int t = is_good_i;
	for (int t = is_good_i; n > 0 && t > 0; --t) {
		n /= 10;
	}
	return n%10 == 0;
}

vector<int> solve(bool bad_exists) {
	vector<int> res;

	if (count_if(a, a+k, is_good) == 0)
		return res;

	bad_exists = any_of(a, a+k, [](int n) { return !is_good(n); });

	bool f = true;
	for (int i = 0; i < k; ++i) {
		if (is_good(a[i]))
			res.push_back(a[i]);
	}
	if (bad_exists) {
		res.push_back(*find_if(a, a+k, [](int n) { return !is_good(n); }));
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}


	return 0;
}

