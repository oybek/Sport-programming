
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

#define n_max 100001

int n, a[n_max], as[n_max];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		as[i] = a[i];
	}

	sort(as, as+n);

	int i = 0, j = n-1;
	for (; i < n; ++i)
		if (a[i] != as[i])
			break;

	if (i == n) {
		cout << "yes\n1 1";
		return 0;
	}

	for (; j >= 0; --j)
		if (a[j] != as[j])
			break;
	reverse(a+i, a+j+1);
	if (is_sorted(a, a+n))
		cout << "yes" << endl << i+1 << ' ' << j+1 << endl;
	else
		cout << "no";

	return 0;
}

