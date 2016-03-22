
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
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

int main() {
	int n, v, k, t;
	vector<int> ans;
	cin >> n >> v;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		bool f = 1;
		while (k--) {
			cin >> t;
			if (t < v && f) {
				f = false;
				ans.push_back(i);
			}
		}
	}
	cout << ans.size() << endl;
	for (int t : ans)
		cout << t << ' ';

	return 0;
}

