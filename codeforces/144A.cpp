
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
#include <numeric>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define all(c) c.begin(), c.end()
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	int n;
	vector<int> a;

	cin >> n;
	a.resize(n);
	for_each(a.begin(), a.end(), [](int & t) {
		cin >> t;
	});

	int x = distance(a.begin(), max_element(all(a)));
	int y = distance(
		min_element(all(a), [](int a, int b) { return a <= b; }),
		a.end())-1;

	cout << (x+y < a.size() ? x+y : x+y-1);

	return 0;
}

