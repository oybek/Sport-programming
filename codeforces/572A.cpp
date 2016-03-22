
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

const int a_sz_max = 100001;
int a_sz, b_sz, k, m, a[a_sz_max], b[a_sz_max];

int main() {
	cin >> a_sz >> b_sz >> k >> m;
	for (int i = 0; i < a_sz; ++i) cin >> a[i];
	for (int i = 0; i < b_sz; ++i) cin >> b[i];
	int x = *min_element(b+b_sz-m, b+b_sz);
	for (int i = 0; i < k; ++i)
		if (a[i] >= x) {
			cout << "NO";
			return 0;
		}
	cout << "YES";

	return 0;
}

