
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

int main() {
	int n, h[n_max], m[n_max];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	m[n-1] = 0;
	for (int i = n-2; i >= 0; --i)
		m[i] = max(h[i+1], m[i+1]);
	for (int i = 0; i < n; ++i)
		cout << max(m[i]-h[i]+1, 0) << ' ';

	return 0;
}

