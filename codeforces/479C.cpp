
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

#define n_max 5001

int n;
pair<int, int> ba[n_max];

bool is_good() {
	for (int i = 0; i+1 < n; ++i)
		if (ba[i].second > ba[i+1].second)
			return false;
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ba[i].first >> ba[i].second;
	sort(ba, ba+n);
	cout << (is_good() ? ba[n-1].second : ba[n-1].first);

	return 0;
}

