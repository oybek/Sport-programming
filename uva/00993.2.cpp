
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

using namespace std;

void solve(int n, vector<int> & v) {
	if (n == 0) {
		v.push_back(1);
		v.push_back(0);
		return;
	} else
	if (n == 1) {
		v.push_back(1);
		return;
	}

	v.resize(0);
	for (int i = 9; i > 1; )
		if (n%i == 0) {
			v.push_back(i);
			n /= i;
		} else
			--i;
	if (n > 9) {
		v.resize(1);
		v[0] = -1;
	}
	reverse(v.begin(), v.end());
}

int main() {
	int test_n, n;
	vector<int> v;

	cin >> test_n;
	while (test_n--) {
		cin >> n;
		solve(n, v);
		for (int i = 0; i < int(v.size()); ++i)
			cout << v[i];
		cout << endl;
	}

	return 0;
}

