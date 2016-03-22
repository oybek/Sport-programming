
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
	int k, cnt[256];
	string s;
	fill(cnt, cnt+256, 0);

	cin >> k >> s;

	if (s.size()%k) { cout << -1; return 0; }
	for (char c : s) ++cnt[c];

	for (int i = 'a'; i <= 'z'; ++i)
		if (cnt[i]%k) { cout << -1; return 0; }

	string t;
	for (int i = 'a'; i <= 'z'; ++i)
		for (int j = cnt[i]/k; j--; )
			t.push_back(char(i));

	while (k--)
		cout << t;

	return 0;
}

