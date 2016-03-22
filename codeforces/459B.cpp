
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

const int n_max = 200001;
int n, b[n_max];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	sort(b, b+n);
	int64 c1 = upper_bound(b, b+n, b[0])-b,
		  c2 = n-(lower_bound(b, b+n, b[n-1])-b);
	cout << b[n-1]-b[0] << ' ' << (b[n-1] == b[0] ? c1*(c1-1)/2 : c1*c2);

	return 0;
}

