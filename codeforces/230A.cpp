
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

int main() {
	int s, n;
	vector<pair<int, int> > a;

	cin >> s >> n;
	a.resize(n);
	for (pair<int, int> & t : a)
		cin >> t.first >> t.second;
	sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
		return x.first == y.first ? x.second > y.second : x.first < y.first;
	});

	for (pair<int, int> t : a) {
		if (s <= t.first) {
			cout << "NO";
			return 0;
		} else {
			s += t.second;
		}
	}

	cout << "YES";

	return 0;
}

