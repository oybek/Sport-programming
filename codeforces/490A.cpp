
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
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

int n, t;
vector<int> a[4];

int main() {
	for (int i = 1; i <= 3; ++i)
		a[i].reserve(5001);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		a[t].push_back(i);
	}

	cout << min(a[1].size(), min(a[2].size(), a[3].size())) << endl;
	while (a[1].size() && a[2].size() && a[3].size()) {
		cout
			<< *a[1].rbegin() << ' '
			<< *a[2].rbegin() << ' '
			<< *a[3].rbegin() << endl;
		a[1].pop_back();
		a[2].pop_back();
		a[3].pop_back();
	}

	return 0;
}

