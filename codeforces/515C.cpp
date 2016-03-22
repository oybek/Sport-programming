
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
	int n, cnt[10];
	string s, ans; ans.reserve(1000);

	string a[10];
	a[0] = a[1] = "";
	a[2] = "2";
	a[3] = "3";
	a[4] = "322";
	a[5] = "5";
	a[6] = "53";
	a[7] = "7";
	a[8] = "7222";
	a[9] = "7332";

	cin >> n >> s;
	for (char c : s)
		ans += a[c-'0'];
	sort(ans.rbegin(), ans.rend());
	cout << ans;

	return 0;
}

