
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

int n, m;
string a[51];

bool is_face(int x, int y) {
	string s {
		a[x][y],
		a[x+1][y],
		a[x][y+1],
		a[x+1][y+1],
	};
	sort(s.begin(), s.end());
	return s == "acef";
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i+1 < n; ++i)
		for (int j = 0; j+1 < m; ++j)
			if (is_face(i, j))
				++ans;
	cout << ans;

	return 0;
}

