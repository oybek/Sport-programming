
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

const int n_max = 101;
int n, k;
pair<int, int> a[n_max];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a, a+n);

	int s = 0;
	vector<int> ans; ans.reserve(n_max);
	for (int i = 0; i < n; ++i) {
		s += a[i].first;
		if (s <= k) {
			ans.push_back(a[i].second);
		} else {
			break;
		}
	}
	cout << ans.size() << endl;
	for (int t : ans)
		cout << t << ' ';

	return 0;
}

