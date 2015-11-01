
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

int main() {
	int n, s = 0;
	vector<int> a;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}

	sort(a.rbegin(), a.rend());

	int s1 = 0;
	for (int i = 0; i < n; ++i) {
		s1 += a[i];
		if (s1 > s-s1) {
			cout << i+1;
			return 0;
		}
	}

	return 0;
}

