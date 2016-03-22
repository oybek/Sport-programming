
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

int n;
vector<pair<int, int> > neg, pos;

int sum(const vector<pair<int, int> > & a, int size) {
	int sum = 0;
	for (int i = 0; i < size && i < a.size(); ++i)
		sum += a[i].second;
	return sum;
}

int main() {
	cin >> n;
	while (n--) {
		int x, a;
		cin >> x >> a;

		if (x < 0) {
			neg.push_back(make_pair(x, a));
		} else {
			pos.push_back(make_pair(x, a));
		}
	}

	sort(neg.rbegin(), neg.rend());
	sort(pos.begin(), pos.end());

	cout << sum(neg, min(neg.size(), pos.size())+1)
		+ sum(pos, min(neg.size(), pos.size())+1);

	return 0;
}

