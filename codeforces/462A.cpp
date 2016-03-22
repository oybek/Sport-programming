
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

int n;
vector<string> a;

bool is_good() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (((i-1 >= 0 && a[i-1][j] == 'o')
				+(i+1  < n && a[i+1][j] == 'o')
				+(j-1 >= 0 && a[i][j-1] == 'o')
				+(j+1  < n && a[i][j+1] == 'o'))%2)
				return false;
	return true;
}

int main() {
	cin >> n;
	a.resize(n);
	for (string & s : a)
		cin >> s;
	cout << (is_good() ? "YES" : "NO") << endl;

	return 0;
}

